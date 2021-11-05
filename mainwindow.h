#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVideoWidget>
#include <QMediaPlaylist>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMediaPlayer *player = new QMediaPlayer(this);

    QVideoWidget *videoWidget = new QVideoWidget(this);

private slots:
//    void on_timeSlider_valueChanged(int value);

    void on_volumeSlider_valueChanged(int value);

    void on_start_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
