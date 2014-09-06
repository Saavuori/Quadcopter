#include "serial.h"

SerialHandler::SerialHandler(QObject* parent): QThread(parent)
{
    serial = new QSerialPort();
}

SerialHandler::~SerialHandler()
{
    delete serial;
}


void SerialHandler::run()
{


}

void SerialHandler::send(QByteArray text)
{
    if(serial->isOpen())
         serial->write(text);

}
void SerialHandler::send(const char *text)
{
    if(serial->isOpen())
         serial->write(text);

}


void SerialHandler::openPort(const QString portname, qint32 baundrate)
{

    serial->setPortName(portname);
    serial->setBaudRate(baundrate);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if(serial->open(QIODevice::ReadWrite))
        connect(serial,SIGNAL(readyRead()),this,SLOT(serialReceived()));

}


void SerialHandler::serialReceived()
{

    while(serial->canReadLine())
    {

        buffer = serial->readLine(64);

        if(buffer.startsWith("M"))
        {
            List.clear();
            List=buffer.right(buffer.length()-1).split(';');
            if(List.size()==5)
        {
            emit motor1(List[0].toInt());
            emit motor2(List[1].toInt());
            emit motor3(List[2].toInt());
            emit motor4(List[3].toInt());
        }

        }
        else if(buffer.startsWith("A"))
        {

            List = buffer.right(buffer.length()-1).split(';');

            if(List.size()==3)
            {
            emit altitude(List[1].toDouble());
            }

        }
        else
        {

            emit console(buffer);

        }

    }

}
