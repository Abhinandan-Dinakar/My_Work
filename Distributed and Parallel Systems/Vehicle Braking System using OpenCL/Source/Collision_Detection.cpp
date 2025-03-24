
/******************************************************************************

 * Program Name		: Vehicle Braking System in Truck Platooning
 * Author      		: Abhinandan Dinakar
 * Date        		: 25.02.2022
 * Subject 			: Distributed and Parallel Systems
 * Frame Work		: QT Creator
 * Version			: 3.1.0
 
 ******************************************************************************/

/* Header Files */
#include <stdio.h>
#include<iostream>
#include <stdlib.h>
#include <CL/cl.h>
using namespace std;

#define MAX 100

/* Code Execution in Kernel */
const char* KernelSource =

"__kernel void Truck_Platoon(__global float *Sensor,__global float *output2)\n"\
"{\n"\

"  int i = get_global_id(0);\n"\

"  output2[i] = Sensor[i] / 10 ;\n"\

"}\n";

/* Main Program Implementation */
int main()
{
	/* Initialization */
	size_t global;
	cl_device_id device_id;
	cl_context context;
	cl_command_queue command_queue;
	cl_program program;
	cl_kernel kernel;
	cl_device_type dev_type;
	cl_context_properties properties[3];
	cl_int err;
	cl_uint num_of_platforms;
	cl_platform_id platform_id;
	cl_uint num_of_devices;

	/* Buffers for Input and Output*/
	cl_mem DeviceInput_1, Sensor, DeviceOutput_1; 	

	/* Variable Declaration*/
	int i = 0;
	srand((unsigned)time(0));
	int HardwareOut_1[MAX] = {};
	int SensorVal[MAX] = {};

	/* Loop to get Random values as Inputs*/
	for (i = 0; i < MAX; i++)
	{
		SensorVal[i] = (rand() % 1000);	
	}

	/* Check available Platforms*/
	if (clGetPlatformIDs(1, &platform_id, &num_of_platforms) != CL_SUCCESS)
	{
		printf("No Platform ID detected\n");
		return 1;
	}

	/* Check Device ID */
	if (clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_of_devices) != CL_SUCCESS)
	{
		printf("No Device ID detected\n");
		return 1;
	}

	/* Context Properties */
	properties[0] = CL_CONTEXT_PLATFORM;
	properties[1] = (cl_context_properties)platform_id;
	properties[2] = 0;

	/* Contexts for GPU Devices */
	context = clCreateContext(properties, 1, &device_id, NULL, NULL, &err);

	/* Command Queue with Contexts and Devices */
	command_queue = clCreateCommandQueue(context, device_id, 0, &err);

	/* Check Device type */
	clGetDeviceInfo(device_id, CL_DEVICE_TYPE, sizeof(dev_type), &dev_type, NULL);
	if (dev_type == CL_DEVICE_TYPE_GPU)
	{
		printf("|------------------------------------------------|\n");
		printf("|---------------Execution Started----------------|\n");
		printf("|------------------------------------------------|\n\n");
	}

	/* Kernel Source Program */
	program = clCreateProgramWithSource(context, 1, (const char**)&KernelSource, NULL, &err);

	/* Build Solution */
	if (clBuildProgram(program, 0, NULL, NULL, NULL, NULL) != CL_SUCCESS)
	{
		printf("Error\n");
		return 1;
	}

	/* Kernel Program Execution */
	kernel = clCreateKernel(program, "Truck_Platoon", &err);

	/* Buffer Creation in Kernel */ 
	DeviceInput_1 = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * MAX, NULL, NULL);	
	Sensor = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * MAX, NULL, NULL);	
	DeviceOutput_1 = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * MAX, NULL, NULL);

	/* To Load the Data into Buffer (Device Memory) */
	clEnqueueWriteBuffer(command_queue, Sensor, CL_TRUE, 0, sizeof(int) * MAX, SensorVal, 0, NULL, NULL);

	/* Arguments to be set for Kernel */
	clSetKernelArg(kernel, 0, sizeof(cl_mem), &Sensor);
	clSetKernelArg(kernel, 1, sizeof(cl_mem), &DeviceOutput_1);

	/* MAX = 100 */
	global = MAX;

	/* Enqueue for Execution in Kernel */
	clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global, NULL, 0, NULL, NULL);
	clFinish(command_queue);

	/* Get the Outputs from Device to Hardware */
	clEnqueueReadBuffer(command_queue, DeviceOutput_1, CL_TRUE, 0, sizeof(int) * MAX, HardwareOut_1, 0, NULL, NULL);

	/* Program to Check Brake System with respect to Sensor Values  */
	for (int i = 0; i < MAX; i++)
	{
		printf("|------------------------------------------------|\n");
		printf("   Object Detected at the Range of %d meters\n", HardwareOut_1[i]);

		if (HardwareOut_1[i] < 100 && HardwareOut_1[i] > 80)
		{
			printf("   Brake force of 20%% Applied\n");
		}
		else if (HardwareOut_1[i] < 79 && HardwareOut_1[i] > 60)
		{
			printf("   Brake force of 60%% Applied\n");
		}
		else if (HardwareOut_1[i] <= 59 && HardwareOut_1[i] >= 30)
		{
			printf("   Brake force of 80%% Applied\n");
		}
		else
		{
			printf("   Brake force of 100%% Applied\n");
			printf("   Anti-lock Braking System is Activated\n");
		}
		printf("|------------------------------------------------|\n\n");
	}

	/* To release Memory Objects, Program and Kernel */
	clReleaseMemObject(DeviceOutput_1);
	clReleaseMemObject(DeviceInput_1);
	clReleaseMemObject(Sensor);
	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);
	return 0;

}