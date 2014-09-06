/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QLCDNumber *lcd_pitch;
    QLCDNumber *lcd_yawn;
    QSlider *slider_throttle;
    QSlider *slider_pitch;
    QLCDNumber *lcd_roll;
    QSlider *slider_yawn;
    QSlider *slider_roll;
    QLCDNumber *lcd_throttle;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_pitch;
    QLCDNumber *lcd_Alt;
    QLabel *label_11;
    QLabel *label_31;
    QGroupBox *groupBox_2;
    QProgressBar *bar_m1;
    QProgressBar *bar_m2;
    QProgressBar *bar_m4;
    QProgressBar *bar_m3;
    QCheckBox *checkBox_motors;
    QFrame *line;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *pid_yawn_p;
    QDoubleSpinBox *pid_yawn_i;
    QDoubleSpinBox *pid_yawn_d;
    QDoubleSpinBox *pid_pitch_p;
    QDoubleSpinBox *pid_pitch_i;
    QDoubleSpinBox *pid_pitch_d;
    QDoubleSpinBox *pid_roll_p;
    QDoubleSpinBox *pid_roll_i;
    QDoubleSpinBox *pid_roll_d;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_connect;
    QComboBox *comboBox_baundrate;
    QComboBox *comboBox_port;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton_disconnect;
    QGroupBox *groupBox_5;
    QSpinBox *spinBox_alarm_high;
    QLabel *label_7;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_25;
    QSpinBox *spinBox_alarm_low;
    QSpinBox *spinBox_angle_alarm;
    QSpinBox *spinBox_slowLoop;
    QGroupBox *groupBox_6;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QDoubleSpinBox *pid_yawn_p_2;
    QDoubleSpinBox *pid_yawn_i_2;
    QDoubleSpinBox *pid_yawn_d_2;
    QDoubleSpinBox *pid_pitch_p_2;
    QDoubleSpinBox *pid_pitch_i_2;
    QDoubleSpinBox *pid_pitch_d_2;
    QDoubleSpinBox *pid_roll_p_2;
    QDoubleSpinBox *pid_roll_i_2;
    QDoubleSpinBox *pid_roll_d_2;
    QPushButton *pushButton_enable_pid_settings;
    QPushButton *pushButton_start;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_clear_console;
    QPlainTextEdit *console;
    QPushButton *pushButton_get_raw_values;
    QPushButton *pushButton_get_euler;
    QPushButton *pushButton_test;
    QPushButton *pushButton_get_loop_time;
    QPushButton *pushButton_calibrate;
    QPushButton *pushButton_get_set_points;
    QPushButton *pushButton_reset_altitude;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(639, 509);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(10, 10, 621, 311));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(100, 100));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 401, 281));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        groupBox_3->setFont(font);
        lcd_pitch = new QLCDNumber(groupBox_3);
        lcd_pitch->setObjectName(QStringLiteral("lcd_pitch"));
        lcd_pitch->setGeometry(QRect(340, 250, 41, 23));
        lcd_pitch->setFont(font);
        lcd_pitch->setDigitCount(3);
        lcd_yawn = new QLCDNumber(groupBox_3);
        lcd_yawn->setObjectName(QStringLiteral("lcd_yawn"));
        lcd_yawn->setGeometry(QRect(180, 70, 41, 23));
        lcd_yawn->setDigitCount(3);
        slider_throttle = new QSlider(groupBox_3);
        slider_throttle->setObjectName(QStringLiteral("slider_throttle"));
        slider_throttle->setGeometry(QRect(20, 40, 41, 201));
        slider_throttle->setMinimum(50);
        slider_throttle->setMaximum(255);
        slider_throttle->setOrientation(Qt::Vertical);
        slider_pitch = new QSlider(groupBox_3);
        slider_pitch->setObjectName(QStringLiteral("slider_pitch"));
        slider_pitch->setGeometry(QRect(350, 40, 22, 201));
        slider_pitch->setMinimum(-90);
        slider_pitch->setMaximum(90);
        slider_pitch->setOrientation(Qt::Vertical);
        lcd_roll = new QLCDNumber(groupBox_3);
        lcd_roll->setObjectName(QStringLiteral("lcd_roll"));
        lcd_roll->setGeometry(QRect(180, 250, 41, 23));
        lcd_roll->setDigitCount(3);
        slider_yawn = new QSlider(groupBox_3);
        slider_yawn->setObjectName(QStringLiteral("slider_yawn"));
        slider_yawn->setGeometry(QRect(90, 40, 221, 31));
        slider_yawn->setMinimum(-180);
        slider_yawn->setMaximum(180);
        slider_yawn->setValue(0);
        slider_yawn->setOrientation(Qt::Horizontal);
        slider_roll = new QSlider(groupBox_3);
        slider_roll->setObjectName(QStringLiteral("slider_roll"));
        slider_roll->setGeometry(QRect(90, 220, 221, 31));
        slider_roll->setMinimum(-90);
        slider_roll->setMaximum(90);
        slider_roll->setValue(0);
        slider_roll->setOrientation(Qt::Horizontal);
        lcd_throttle = new QLCDNumber(groupBox_3);
        lcd_throttle->setObjectName(QStringLiteral("lcd_throttle"));
        lcd_throttle->setGeometry(QRect(10, 250, 64, 23));
        lcd_throttle->setDigitCount(3);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(180, 200, 41, 20));
        QFont font1;
        font1.setPointSize(8);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(180, 20, 41, 20));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        label_9->setFont(font2);
        label_9->setAlignment(Qt::AlignCenter);
        label_pitch = new QLabel(groupBox_3);
        label_pitch->setObjectName(QStringLiteral("label_pitch"));
        label_pitch->setGeometry(QRect(340, 20, 41, 16));
        label_pitch->setFont(font2);
        label_pitch->setAlignment(Qt::AlignCenter);
        lcd_Alt = new QLCDNumber(groupBox_3);
        lcd_Alt->setObjectName(QStringLiteral("lcd_Alt"));
        lcd_Alt->setGeometry(QRect(160, 140, 81, 41));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(170, 110, 61, 31));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_11->setFont(font3);
        label_11->setAlignment(Qt::AlignCenter);
        label_31 = new QLabel(groupBox_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(10, 20, 64, 21));
        label_31->setFont(font2);
        label_31->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(420, 10, 171, 281));
        bar_m1 = new QProgressBar(groupBox_2);
        bar_m1->setObjectName(QStringLiteral("bar_m1"));
        bar_m1->setGeometry(QRect(10, 40, 31, 231));
        bar_m1->setMinimum(50);
        bar_m1->setMaximum(255);
        bar_m1->setValue(50);
        bar_m1->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        bar_m1->setOrientation(Qt::Vertical);
        bar_m1->setInvertedAppearance(false);
        bar_m1->setTextDirection(QProgressBar::TopToBottom);
        bar_m2 = new QProgressBar(groupBox_2);
        bar_m2->setObjectName(QStringLiteral("bar_m2"));
        bar_m2->setGeometry(QRect(50, 40, 31, 231));
        bar_m2->setMinimum(50);
        bar_m2->setMaximum(255);
        bar_m2->setValue(50);
        bar_m2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        bar_m2->setOrientation(Qt::Vertical);
        bar_m2->setTextDirection(QProgressBar::TopToBottom);
        bar_m4 = new QProgressBar(groupBox_2);
        bar_m4->setObjectName(QStringLiteral("bar_m4"));
        bar_m4->setGeometry(QRect(130, 40, 31, 231));
        bar_m4->setMinimum(50);
        bar_m4->setMaximum(255);
        bar_m4->setValue(50);
        bar_m4->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        bar_m4->setOrientation(Qt::Vertical);
        bar_m4->setTextDirection(QProgressBar::TopToBottom);
        bar_m3 = new QProgressBar(groupBox_2);
        bar_m3->setObjectName(QStringLiteral("bar_m3"));
        bar_m3->setGeometry(QRect(90, 40, 31, 231));
        bar_m3->setMinimum(50);
        bar_m3->setMaximum(255);
        bar_m3->setValue(50);
        bar_m3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        bar_m3->setOrientation(Qt::Vertical);
        bar_m3->setTextDirection(QProgressBar::TopToBottom);
        checkBox_motors = new QCheckBox(groupBox_2);
        checkBox_motors->setObjectName(QStringLiteral("checkBox_motors"));
        checkBox_motors->setGeometry(QRect(10, 20, 51, 17));
        line = new QFrame(groupBox_2);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 205, 171, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 261, 131));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 10, 21, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 10, 16, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 10, 31, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 31, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 60, 31, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 90, 21, 16));
        pid_yawn_p = new QDoubleSpinBox(groupBox);
        pid_yawn_p->setObjectName(QStringLiteral("pid_yawn_p"));
        pid_yawn_p->setGeometry(QRect(50, 30, 62, 22));
        pid_yawn_p->setDecimals(3);
        pid_yawn_p->setSingleStep(0.01);
        pid_yawn_i = new QDoubleSpinBox(groupBox);
        pid_yawn_i->setObjectName(QStringLiteral("pid_yawn_i"));
        pid_yawn_i->setGeometry(QRect(120, 30, 62, 22));
        pid_yawn_i->setDecimals(3);
        pid_yawn_i->setSingleStep(0.01);
        pid_yawn_d = new QDoubleSpinBox(groupBox);
        pid_yawn_d->setObjectName(QStringLiteral("pid_yawn_d"));
        pid_yawn_d->setGeometry(QRect(190, 30, 62, 22));
        pid_yawn_d->setDecimals(3);
        pid_yawn_d->setSingleStep(0.001);
        pid_pitch_p = new QDoubleSpinBox(groupBox);
        pid_pitch_p->setObjectName(QStringLiteral("pid_pitch_p"));
        pid_pitch_p->setGeometry(QRect(50, 60, 62, 22));
        pid_pitch_p->setDecimals(3);
        pid_pitch_p->setSingleStep(0.01);
        pid_pitch_i = new QDoubleSpinBox(groupBox);
        pid_pitch_i->setObjectName(QStringLiteral("pid_pitch_i"));
        pid_pitch_i->setGeometry(QRect(120, 60, 62, 22));
        pid_pitch_i->setDecimals(3);
        pid_pitch_i->setSingleStep(0.01);
        pid_pitch_d = new QDoubleSpinBox(groupBox);
        pid_pitch_d->setObjectName(QStringLiteral("pid_pitch_d"));
        pid_pitch_d->setGeometry(QRect(190, 60, 62, 22));
        pid_pitch_d->setDecimals(3);
        pid_pitch_d->setSingleStep(0.001);
        pid_roll_p = new QDoubleSpinBox(groupBox);
        pid_roll_p->setObjectName(QStringLiteral("pid_roll_p"));
        pid_roll_p->setGeometry(QRect(50, 90, 62, 22));
        pid_roll_p->setDecimals(3);
        pid_roll_p->setSingleStep(0.01);
        pid_roll_i = new QDoubleSpinBox(groupBox);
        pid_roll_i->setObjectName(QStringLiteral("pid_roll_i"));
        pid_roll_i->setGeometry(QRect(120, 90, 62, 22));
        pid_roll_i->setDecimals(3);
        pid_roll_i->setSingleStep(0.01);
        pid_roll_d = new QDoubleSpinBox(groupBox);
        pid_roll_d->setObjectName(QStringLiteral("pid_roll_d"));
        pid_roll_d->setGeometry(QRect(190, 90, 62, 22));
        pid_roll_d->setDecimals(3);
        pid_roll_d->setSingleStep(0.001);
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(280, 200, 261, 81));
        pushButton_connect = new QPushButton(groupBox_4);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(180, 50, 71, 23));
        comboBox_baundrate = new QComboBox(groupBox_4);
        comboBox_baundrate->setObjectName(QStringLiteral("comboBox_baundrate"));
        comboBox_baundrate->setGeometry(QRect(80, 20, 91, 22));
        comboBox_port = new QComboBox(groupBox_4);
        comboBox_port->setObjectName(QStringLiteral("comboBox_port"));
        comboBox_port->setGeometry(QRect(80, 50, 91, 22));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 20, 31, 16));
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 50, 61, 16));
        pushButton_disconnect = new QPushButton(groupBox_4);
        pushButton_disconnect->setObjectName(QStringLiteral("pushButton_disconnect"));
        pushButton_disconnect->setGeometry(QRect(180, 20, 71, 23));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 200, 261, 81));
        spinBox_alarm_high = new QSpinBox(groupBox_5);
        spinBox_alarm_high->setObjectName(QStringLiteral("spinBox_alarm_high"));
        spinBox_alarm_high->setGeometry(QRect(80, 10, 51, 22));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 10, 71, 16));
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(140, 10, 61, 16));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 40, 71, 16));
        label_25 = new QLabel(groupBox_5);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(140, 40, 51, 16));
        spinBox_alarm_low = new QSpinBox(groupBox_5);
        spinBox_alarm_low->setObjectName(QStringLiteral("spinBox_alarm_low"));
        spinBox_alarm_low->setGeometry(QRect(200, 10, 51, 22));
        spinBox_angle_alarm = new QSpinBox(groupBox_5);
        spinBox_angle_alarm->setObjectName(QStringLiteral("spinBox_angle_alarm"));
        spinBox_angle_alarm->setGeometry(QRect(80, 40, 51, 22));
        spinBox_slowLoop = new QSpinBox(groupBox_5);
        spinBox_slowLoop->setObjectName(QStringLiteral("spinBox_slowLoop"));
        spinBox_slowLoop->setGeometry(QRect(200, 40, 51, 22));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(280, 40, 261, 131));
        label_19 = new QLabel(groupBox_6);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(70, 10, 21, 21));
        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(140, 10, 16, 16));
        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(200, 10, 31, 16));
        label_22 = new QLabel(groupBox_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(10, 30, 31, 16));
        label_23 = new QLabel(groupBox_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 60, 31, 21));
        label_24 = new QLabel(groupBox_6);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 90, 21, 16));
        pid_yawn_p_2 = new QDoubleSpinBox(groupBox_6);
        pid_yawn_p_2->setObjectName(QStringLiteral("pid_yawn_p_2"));
        pid_yawn_p_2->setGeometry(QRect(50, 30, 62, 22));
        pid_yawn_p_2->setDecimals(3);
        pid_yawn_p_2->setSingleStep(0.01);
        pid_yawn_i_2 = new QDoubleSpinBox(groupBox_6);
        pid_yawn_i_2->setObjectName(QStringLiteral("pid_yawn_i_2"));
        pid_yawn_i_2->setGeometry(QRect(120, 30, 62, 22));
        pid_yawn_i_2->setDecimals(3);
        pid_yawn_i_2->setSingleStep(0.01);
        pid_yawn_d_2 = new QDoubleSpinBox(groupBox_6);
        pid_yawn_d_2->setObjectName(QStringLiteral("pid_yawn_d_2"));
        pid_yawn_d_2->setGeometry(QRect(190, 30, 62, 22));
        pid_yawn_d_2->setDecimals(3);
        pid_yawn_d_2->setSingleStep(0.001);
        pid_pitch_p_2 = new QDoubleSpinBox(groupBox_6);
        pid_pitch_p_2->setObjectName(QStringLiteral("pid_pitch_p_2"));
        pid_pitch_p_2->setGeometry(QRect(50, 60, 62, 22));
        pid_pitch_p_2->setDecimals(3);
        pid_pitch_p_2->setSingleStep(0.01);
        pid_pitch_i_2 = new QDoubleSpinBox(groupBox_6);
        pid_pitch_i_2->setObjectName(QStringLiteral("pid_pitch_i_2"));
        pid_pitch_i_2->setGeometry(QRect(120, 60, 62, 22));
        pid_pitch_i_2->setDecimals(3);
        pid_pitch_i_2->setSingleStep(0.01);
        pid_pitch_d_2 = new QDoubleSpinBox(groupBox_6);
        pid_pitch_d_2->setObjectName(QStringLiteral("pid_pitch_d_2"));
        pid_pitch_d_2->setGeometry(QRect(190, 60, 62, 22));
        pid_pitch_d_2->setDecimals(3);
        pid_pitch_d_2->setSingleStep(0.001);
        pid_roll_p_2 = new QDoubleSpinBox(groupBox_6);
        pid_roll_p_2->setObjectName(QStringLiteral("pid_roll_p_2"));
        pid_roll_p_2->setGeometry(QRect(50, 90, 62, 22));
        pid_roll_p_2->setDecimals(3);
        pid_roll_p_2->setSingleStep(0.01);
        pid_roll_i_2 = new QDoubleSpinBox(groupBox_6);
        pid_roll_i_2->setObjectName(QStringLiteral("pid_roll_i_2"));
        pid_roll_i_2->setGeometry(QRect(120, 90, 62, 22));
        pid_roll_i_2->setDecimals(3);
        pid_roll_i_2->setSingleStep(0.01);
        pid_roll_d_2 = new QDoubleSpinBox(groupBox_6);
        pid_roll_d_2->setObjectName(QStringLiteral("pid_roll_d_2"));
        pid_roll_d_2->setGeometry(QRect(190, 90, 62, 22));
        pid_roll_d_2->setDecimals(3);
        pid_roll_d_2->setSingleStep(0.001);
        pushButton_enable_pid_settings = new QPushButton(tab);
        pushButton_enable_pid_settings->setObjectName(QStringLiteral("pushButton_enable_pid_settings"));
        pushButton_enable_pid_settings->setGeometry(QRect(10, 10, 151, 23));
        tabWidget->addTab(tab, QString());
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QStringLiteral("pushButton_start"));
        pushButton_start->setGeometry(QRect(460, 420, 171, 61));
        QFont font4;
        font4.setPointSize(36);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton_start->setFont(font4);
        pushButton_stop = new QPushButton(centralWidget);
        pushButton_stop->setObjectName(QStringLiteral("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(460, 360, 171, 61));
        pushButton_stop->setFont(font4);
        pushButton_clear_console = new QPushButton(centralWidget);
        pushButton_clear_console->setObjectName(QStringLiteral("pushButton_clear_console"));
        pushButton_clear_console->setGeometry(QRect(550, 330, 81, 23));
        console = new QPlainTextEdit(centralWidget);
        console->setObjectName(QStringLiteral("console"));
        console->setEnabled(true);
        console->setGeometry(QRect(20, 360, 431, 121));
        console->setReadOnly(true);
        pushButton_get_raw_values = new QPushButton(centralWidget);
        pushButton_get_raw_values->setObjectName(QStringLiteral("pushButton_get_raw_values"));
        pushButton_get_raw_values->setGeometry(QRect(380, 330, 81, 23));
        pushButton_get_euler = new QPushButton(centralWidget);
        pushButton_get_euler->setObjectName(QStringLiteral("pushButton_get_euler"));
        pushButton_get_euler->setGeometry(QRect(310, 330, 61, 23));
        pushButton_test = new QPushButton(centralWidget);
        pushButton_test->setObjectName(QStringLiteral("pushButton_test"));
        pushButton_test->setGeometry(QRect(270, 330, 31, 23));
        pushButton_get_loop_time = new QPushButton(centralWidget);
        pushButton_get_loop_time->setObjectName(QStringLiteral("pushButton_get_loop_time"));
        pushButton_get_loop_time->setGeometry(QRect(180, 330, 81, 23));
        pushButton_calibrate = new QPushButton(centralWidget);
        pushButton_calibrate->setObjectName(QStringLiteral("pushButton_calibrate"));
        pushButton_calibrate->setGeometry(QRect(110, 330, 61, 23));
        pushButton_get_set_points = new QPushButton(centralWidget);
        pushButton_get_set_points->setObjectName(QStringLiteral("pushButton_get_set_points"));
        pushButton_get_set_points->setGeometry(QRect(20, 330, 81, 23));
        pushButton_reset_altitude = new QPushButton(centralWidget);
        pushButton_reset_altitude->setObjectName(QStringLiteral("pushButton_reset_altitude"));
        pushButton_reset_altitude->setGeometry(QRect(470, 330, 81, 23));
        MainWindow->setCentralWidget(centralWidget);
        tabWidget->raise();
        pushButton_start->raise();
        pushButton_stop->raise();
        console->raise();
        pushButton_clear_console->raise();
        pushButton_get_raw_values->raise();
        pushButton_get_euler->raise();
        pushButton_test->raise();
        pushButton_get_loop_time->raise();
        pushButton_calibrate->raise();
        pushButton_get_set_points->raise();
        pushButton_reset_altitude->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QUADCOPTER V0.1", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Controls", 0));
        label_8->setText(QApplication::translate("MainWindow", "Roll", 0));
        label_9->setText(QApplication::translate("MainWindow", "Yaw", 0));
        label_pitch->setText(QApplication::translate("MainWindow", "Pitch", 0));
        label_11->setText(QApplication::translate("MainWindow", "Altitude", 0));
        label_31->setText(QApplication::translate("MainWindow", "Throttle", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Motors", 0));
        checkBox_motors->setText(QApplication::translate("MainWindow", "Enable", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Flight", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "PID Agle", 0));
        label->setText(QApplication::translate("MainWindow", "P", 0));
        label_2->setText(QApplication::translate("MainWindow", "  I", 0));
        label_3->setText(QApplication::translate("MainWindow", "   D", 0));
        label_4->setText(QApplication::translate("MainWindow", "Yawn", 0));
        label_5->setText(QApplication::translate("MainWindow", "Pitch", 0));
        label_6->setText(QApplication::translate("MainWindow", "Roll", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Serial", 0));
        pushButton_connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        label_12->setText(QApplication::translate("MainWindow", "Port", 0));
        label_13->setText(QApplication::translate("MainWindow", "Baund Rate", 0));
        pushButton_disconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Alarms", 0));
        label_7->setText(QApplication::translate("MainWindow", "alarm_high", 0));
        label_17->setText(QApplication::translate("MainWindow", "alarm_low", 0));
        label_18->setText(QApplication::translate("MainWindow", "angle_alarm", 0));
        label_25->setText(QApplication::translate("MainWindow", " slowLoop", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "PID Rate", 0));
        label_19->setText(QApplication::translate("MainWindow", "P", 0));
        label_20->setText(QApplication::translate("MainWindow", "  I", 0));
        label_21->setText(QApplication::translate("MainWindow", "   D", 0));
        label_22->setText(QApplication::translate("MainWindow", "Yawn", 0));
        label_23->setText(QApplication::translate("MainWindow", "Pitch", 0));
        label_24->setText(QApplication::translate("MainWindow", "Roll", 0));
        pushButton_enable_pid_settings->setText(QApplication::translate("MainWindow", "Enable / Disable PID settings", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Settings", 0));
        pushButton_start->setText(QApplication::translate("MainWindow", "START", 0));
        pushButton_stop->setText(QApplication::translate("MainWindow", "STOP", 0));
        pushButton_clear_console->setText(QApplication::translate("MainWindow", "Clear console", 0));
        pushButton_get_raw_values->setText(QApplication::translate("MainWindow", "GetRawValues", 0));
        pushButton_get_euler->setText(QApplication::translate("MainWindow", "Get Euler", 0));
        pushButton_test->setText(QApplication::translate("MainWindow", "test", 0));
        pushButton_get_loop_time->setText(QApplication::translate("MainWindow", "Get Loop time", 0));
        pushButton_calibrate->setText(QApplication::translate("MainWindow", "Calibrate", 0));
        pushButton_get_set_points->setText(QApplication::translate("MainWindow", "Get set points", 0));
        pushButton_reset_altitude->setText(QApplication::translate("MainWindow", "Reset Altitude", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
