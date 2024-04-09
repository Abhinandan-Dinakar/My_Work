from pycpa import schedulers
from pycpa import analysis
from pycpa import model
from pycpa import options
import time
# initialize pycpa
options.init_pycpa()
# options.set_opt(,value=True)
Obstacle_Detection_system = model.System('Obstacle Detection System')


# define computational resources
core_0 = model.Resource("core0",schedulers.SPPScheduler())



# bind resources to the system
Obstacle_Detection_system.bind_resource(core_0)


# define system tasks



T1 = core_0.bind_task(model.Task('Monitoring the obstacles by emitting sound waves', wcet = 1.99, bcet = 1.99, scheduling_parameter = 0))
T2 = core_0.bind_task(model.Task('Sending the notification to the trucks ', wcet = 5, bcet = 5, scheduling_parameter = 0))


# event models for respective tasks
T1.in_event_model = model.PJdEventModel(P = 30)
T2.in_event_model = model.PJdEventModel(P = 25)


# perform analysis
print("Performing analysis started")
results = analysis.analyze_system(Obstacle_Detection_system)

# print the worst case response times (WCRTs)
print("Result:")
for r in sorted(Obstacle_Detection_system.resources, key=str):
    for t in sorted(r.tasks, key=str):
        print("%s: wcrt=%f, bcrt = %f" % (t.name, results[t].wcrt, results[t].bcrt))



start_time = time.time()
print("---%s seconds---" % (time.time() - start_time))
