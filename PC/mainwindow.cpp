#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <unistd.h>
#include <QScrollBar>
#include <QString>


QByteArray output;
QString str;
QByteArray buffer;
QByteArray tmp;
QSerialPortInfo port;
QList<QByteArray> List;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->console->clear();

    timerMOTOR = new QTimer(this);


    ui->comboBox_baundrate->addItem("57600",QSerialPort::Baud57600);
    ui->comboBox_baundrate->addItem("9600",QSerialPort::Baud9600);


    for(QSerialPortInfo port : QSerialPortInfo::availablePorts())
        ui->comboBox_port->addItem(port.portName(),port.description());

    serialhandler = new SerialHandler(this);


    connect(serialhandler,SIGNAL(console(QString)),ui->console,SLOT(insertPlainText(QString)));

    connect(serialhandler,SIGNAL(motor1(int)),ui->bar_m1,SLOT(setValue(int)));
    connect(serialhandler,SIGNAL(motor2(int)),ui->bar_m2,SLOT(setValue(int)));
    connect(serialhandler,SIGNAL(motor3(int)),ui->bar_m3,SLOT(setValue(int)));
    connect(serialhandler,SIGNAL(motor4(int)),ui->bar_m4,SLOT(setValue(int)));

    ui->pushButton_connect->click();

}


MainWindow::~MainWindow()
{

    //serial->close();
    delete ui;
}

void MainWindow::on_slider_yawn_valueChanged(int value)
{
    ui->lcd_yawn->display(value);

    output.clear();
    str.clear();

    output.append("SSY");
    output.append(str.setNum(double(value)));
    output.append("\r\n");

    writeSerial(output);

}
void MainWindow::on_slider_roll_valueChanged(int value)
{
    ui->lcd_roll->display(value);

    output.clear();
    str.clear();

    output.append("SSR");
    output.append(str.setNum(double(value)));
    output.append("\r\n");

    writeSerial(output);

}
void MainWindow::on_slider_throttle_valueChanged(int value)
{
    ui->lcd_throttle->display(value);

    output.clear();
    str.clear();

    output.append("SST");
    output.append(str.setNum(int(value)));
    output.append("\r\n");

    writeSerial(output);

}
void MainWindow::on_slider_pitch_valueChanged(int value)
{
    ui->lcd_pitch->display(value);

    output.clear();
    str.clear();

    output.append("SSP");
    output.append(str.setNum(double(value)));
    output.append("\r\n");

    writeSerial(output);

}


//**************PID ANGLE*********************//
void MainWindow::on_pid_yawn_d_valueChanged(double arg1)
{
    output.clear();

    output.append("SP5 3 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);

}
void MainWindow::on_pid_yawn_i_valueChanged(double arg1)
{
    output.clear();

    output.append("SP5 2 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_yawn_p_valueChanged(double arg1)
{
    output.clear();

    output.append("SP5 1 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);

}
void MainWindow::on_pid_pitch_p_valueChanged(double arg1)
{
    output.clear();

    output.append("SP3 1 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_pitch_i_valueChanged(double arg1)
{
    output.clear();

    output.append("SP3 2 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_pitch_d_valueChanged(double arg1)
{
    output.clear();

    output.append("SP3 3 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_roll_p_valueChanged(double arg1)
{
    output.clear();

    output.append("SP4 1 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_roll_i_valueChanged(double arg1)
{
    output.clear();

    output.append("SP4 2 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_roll_d_valueChanged(double arg1)
{
    output.clear();

    output.append("SP4 3 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
//-------------------------------------------//

//**************PID RATE*********************//
void MainWindow::on_pid_yawn_d_2_valueChanged(double arg1)
{
    output.clear();

    output.append("SP2 3 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);

}
void MainWindow::on_pid_yawn_i_2_valueChanged(double arg1)
{
    output.clear();

    output.append("SP2 2 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_yawn_p_2_valueChanged(double arg1)
{
    output.clear();

    output.append("SP2 1 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);

}
void MainWindow::on_pid_pitch_p_2_valueChanged(double arg1)
{
    output.clear();

    output.append("SP0 1 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_pitch_i_2_valueChanged(double arg1)
{
    output.clear();

    output.append("SP0 2 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_pitch_d_2_valueChanged(double arg1)
{
    output.clear();

    output.append("SP0 3 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_roll_p_2_valueChanged(double arg1)
{
    output.clear();

    output.append("SP1 1 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_roll_i_2_valueChanged(double arg1)
{
    output.clear();

    output.append("SP1 2 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
void MainWindow::on_pid_roll_d_2_valueChanged(double arg1)
{
    output.clear();

    output.append("SP1 3 ");             //1. Pitc 2. Roll 3. Yaw   //1. P 2. I 3.D
    output.append(QString::number((float)arg1));
    output.append("\r\n");

    writeSerial(output);
}
//-------------------------------------------//

//**************KEY ASSIGMENT*********************//
void MainWindow::keyPressEvent(QKeyEvent * event)
{        
    if(event->key() == Qt::Key_W)
        ui->slider_pitch->setValue(ui->slider_pitch->value()+2);
    if(event->key() == Qt::Key_S)
        ui->slider_pitch->setValue(ui->slider_pitch->value()-2);

    if(event->key() == Qt::Key_D)
        ui->slider_roll->setValue(ui->slider_roll->value()+2);
    if(event->key() == Qt::Key_A)
        ui->slider_roll->setValue(ui->slider_roll->value()-2);

    if(event->key() == Qt::Key_E)
        ui->slider_yawn->setValue(ui->slider_yawn->value()+2);
    if(event->key() == Qt::Key_Q)
        ui->slider_yawn->setValue(ui->slider_yawn->value()-2);

    if(event->key() == Qt::Key_Up || event->key() == Qt::Key_Plus)
        ui->slider_throttle->setValue(ui->slider_throttle->value()+2);
    if(event->key() == Qt::Key_Down || event->key() == Qt::Key_plusminus)
        ui->slider_throttle->setValue(ui->slider_throttle->value()-2);
    if(event->key() == Qt::Key_Escape)
        ui->pushButton_stop->click();
    if(event->key() == Qt::Key_Space)
    {
        ui->slider_pitch->setValue(0);
        ui->slider_roll->setValue(0);
        ui->slider_yawn->setValue(0);
    }



}
//-------------------------------------------//

//**************PUSH BUTTONS*********************//
void MainWindow::on_pushButton_stop_clicked()
{
    output.clear();
    output.append("SQ");
    writeSerial(output);

        ui->slider_throttle->setValue(0);
}
void MainWindow::on_pushButton_start_clicked()
{
    writeSerial("SA");
}
void MainWindow::on_pushButton_get_set_points_clicked()
{
    writeSerial("GA");
}
void MainWindow::on_pushButton_calibrate_clicked()
{
    writeSerial("SC");
}
void MainWindow::on_pushButton_get_euler_clicked()
{
    writeSerial("SS");
}
void MainWindow::on_pushButton_get_raw_values_clicked()
{
    writeSerial("GR");
}
void MainWindow::on_pushButton_get_loop_time_clicked()
{
    writeSerial("GT");
}
void MainWindow::on_pushButton_test_clicked()
{
    writeSerial("SM"); //MOTOR TEST
}
void MainWindow::on_pushButton_reset_altitude_clicked()
{
    writeSerial("SR");
}
void MainWindow::on_pushButton_connect_clicked()
{
    serialhandler->openPort(ui->comboBox_port->itemText(ui->comboBox_port->currentIndex()),QSerialPort::Baud57600);
}
void MainWindow::on_pushButton_enable_pid_settings_clicked()
{
     writeSerial("SE"); //MOTOR TEST
}
//-------------------------------------------//

//**************OTHER*********************//
void MainWindow::on_console_textChanged()
{
    ui->console->verticalScrollBar()->setValue(ui->console->verticalScrollBar()->maximum());
}
void MainWindow::writeSerial(QByteArray &text)
{
    serialhandler->send(text);
}
void MainWindow::writeSerial(const char *text)
{
    serialhandler->send(text);
}
void MainWindow::on_pushButton_clear_console_clicked()
{
    ui->console->clear();
}
void MainWindow::on_checkBox_motors_clicked()
{
    writeSerial("GM");
}//-------------------------------------------//


















