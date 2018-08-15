#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    connect(player,&QMediaPlayer::positionChanged,this,&MainWindow::on_positionChanged);
    connect(player,&QMediaPlayer::durationChanged,this,&MainWindow::on_durationChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_startButton_clicked()
{
    if(this->song.isEmpty()){
        qDebug() << "No song selected" << endl;
        ui->currentSongLabel->setText("No Song Selected To Play");
    }
    else{
        player->setMedia(getSongUrl());
         //player->setMedia(QUrl::fromLocalFile("c:/Users/dclop/Downloads/test.mp3"));
        player->play();
        qDebug() << player->errorString();
    }
}

void MainWindow::on_stopButton_clicked()
{
     qDebug() << "stopping" << endl;
    player->stop();
}

void MainWindow::on_volumeSlider_sliderMoved(int position)
{
    int pos = position;
}

void MainWindow::on_progressSlider_sliderMoved(int position)
{
    int pos = position;
}

void MainWindow::on_songChoice_clicked()
{

    QUrl songName;
    songName= QFileDialog::getOpenFileName(this,
    tr("Open Song"),"C://", tr("All Files (*.*)"));
    qDebug() << "You selected : " << songName << endl;
    setSong(songName);
}

void MainWindow::on_durationChanged(quint64 position){

}

void MainWindow::on_positionChanged(quint64 position){

}

void MainWindow::setSong(QUrl song){
    QUrl temp = song;
    this->song = temp;
}

QUrl MainWindow::getSongUrl(){
    return this->song;
}

void MainWindow::on_pauseButton_clicked()
{
    player->pause();
}
