#ifndef SERIAL_H
#define SERIAL_H

#include <QSerialPort>
#include <QThread>
#include <QMutex>

class SerialHandler : public QThread
{
    Q_OBJECT

public:

    explicit SerialHandler(QObject* parent = 0);
    ~SerialHandler();

   void serialConnect();
   void run();

signals:

    void motor1(int);
    void motor2(int);
    void motor3(int);
    void motor4(int);

    void console(QString text);
    void altitude(double alt);

public slots:

    void send(QByteArray text);
    void send(const char *text);
    void openPort(const QString portname, qint32 baundrate);

private slots:

    void serialReceived();

private:

    QSerialPort *serial;
    bool stop;
    QByteArray buffer;
    QList<QByteArray> List;
};

#endif
