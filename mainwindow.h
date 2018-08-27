#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QUrl song;

private slots:

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_volumeSlider_sliderMoved(int position);

    void on_progressSlider_sliderMoved(int position);

    void on_songChoice_clicked();

    void on_durationChanged(quint64 position);

     void on_positionChanged(quint64 position);

     void setSong(QUrl song);

     QUrl getSongUrl();


     void on_pauseButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;


};

#endif // MAINWINDOW_H
