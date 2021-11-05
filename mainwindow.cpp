#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVideoWidget>
#include <QMediaPlaylist>
//#include <iostream>

// Добавить текущее время и максимальное время видео
// Добавить иконки на кнопки
// После окончания видео кнопка должна быть "play", а не "pause"

// Как вызывать определенные действия при определенных условиях после компиляции. Т.е. напр. как сделать так чтобы ползунок после окончания переносился в начало
// connect(ui->pushButton, SIGNAL(toggled(bool)), this, SLOT(ButtonToggled(bool)));  Пример connect

int buttonPos = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player->setVideoOutput(videoWidget);
    ui->layout->addWidget(videoWidget);


    videoWidget->show();
    player->setMedia(QUrl("C:/Users/admin/Documents/MyFirstVP/Zoo.avi"));

    player->setPosition(8000); // Устанавливаем таймкод
    player->setVolume(80);  // Звук
    player->play();

//    connect(player, SIGNAL (setPosition), ui->timeSlider, SLOT (sliderPosition) );
//    ui->timeSlider->sliderPosition() = player->position();
    int n = 5;
    player->setPosition(n);
    ui->volumeSlider->setValue(100);
    ui->lcdNumber->display(ui->volumeSlider->value());
    ui->start->setText("Pause");
//    ui->timeSlider->setMaximum(player->duration());
    connect(player,&QMediaPlayer::durationChanged, ui->timeSlider,&QSlider::setMaximum);//Thanx
    connect(player, &QMediaPlayer::positionChanged, ui->timeSlider,&QSlider::setValue); //for
    connect(ui->timeSlider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);    //Denis
//    connect(ui->timeSlider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);
    // Как-нибудь приконектить ползунок и видео
    if (player->duration() == player->position())
    {
        ui->start->setText("Pause");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_timeSlider_valueChanged(int value)
//{
//    player->setPosition(value*(player->duration()/100));
//}


void MainWindow::on_volumeSlider_valueChanged(int value)
{
    player->setVolume(value);
    ui->lcdNumber->display(ui->volumeSlider->value());
}


void MainWindow::on_start_clicked()
{
    if (player->duration() == player->position())
    {
        player->play();
        buttonPos = 0;
        ui->start->setText("Pause");
    }
    else
    {
        if (buttonPos == 0)
      {
         player->pause();
         buttonPos = 1;
         ui->start->setText("Play");
      }
     else
      {
          player->play();
          buttonPos = 0;
          ui->start->setText("Pause");
      }
    }
}

//while (player->position() != player->duration)
//{
//     ui->timeSlider->sliderPosition() = player->position();
//}

