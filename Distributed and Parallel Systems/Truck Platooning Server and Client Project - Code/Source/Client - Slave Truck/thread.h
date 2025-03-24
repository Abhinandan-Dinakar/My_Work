#ifndef THREAD_H
#define THREAD_H

#include <QObject>
#include <QWidget>
#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(QObject *parent = nullptr);
    void run();
    bool bStart() const;
    void setStart(bool bStart);

signals:
    void send();
public slots:
private:
    bool m_bStart;
};

#endif // THREAD_H
