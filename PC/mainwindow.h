#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QScrollBar>
#include <QThread>
#include "serial.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:

    //Slider
    void on_slider_yawn_valueChanged(int value);
    void on_slider_roll_valueChanged(int value);
    void on_slider_throttle_valueChanged(int value);
    void on_slider_pitch_valueChanged(int value);
    //PID
    void on_pid_yawn_i_valueChanged(double arg1);
    void on_pid_yawn_d_valueChanged(double arg1);
    void on_pid_yawn_p_valueChanged(double arg1);
    void on_pid_pitch_p_valueChanged(double arg1);
    void on_pid_roll_p_valueChanged(double arg1);
    void on_pid_pitch_i_valueChanged(double arg1);
    void on_pid_pitch_d_valueChanged(double arg1);
    void on_pid_roll_i_valueChanged(double arg1);
    void on_pid_roll_d_valueChanged(double arg1);
    //PID_2
    void on_pid_yawn_i_2_valueChanged(double arg1);
    void on_pid_yawn_d_2_valueChanged(double arg1);
    void on_pid_yawn_p_2_valueChanged(double arg1);
    void on_pid_pitch_p_2_valueChanged(double arg1);
    void on_pid_roll_p_2_valueChanged(double arg1);
    void on_pid_pitch_i_2_valueChanged(double arg1);
    void on_pid_pitch_d_2_valueChanged(double arg1);
    void on_pid_roll_i_2_valueChanged(double arg1);
    void on_pid_roll_d_2_valueChanged(double arg1);

    //PUSH BUTTONS
    void on_pushButton_stop_clicked();
    void on_pushButton_start_clicked();
    void on_checkBox_motors_clicked();
    void on_pushButton_get_euler_clicked();
    void on_pushButton_get_set_points_clicked();
    void on_pushButton_calibrate_clicked();
    void on_pushButton_get_raw_values_clicked();
    void on_pushButton_get_loop_time_clicked();
    void on_pushButton_clear_console_clicked();
    void on_pushButton_test_clicked();
    void on_pushButton_reset_altitude_clicked();
    void on_pushButton_connect_clicked();

   //OTHER
    void writeSerial(QByteArray &text);
    void writeSerial(const char *text);
    void on_console_textChanged();

    void on_pushButton_enable_pid_settings_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
    QTimer *timerMOTOR;
    QTimer *timerSerialBuffer;
    SerialHandler *serialhandler;

};

#endif // MAINWINDOW_H
