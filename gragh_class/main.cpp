#include "mainwindow.h"

#include <QApplication>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include<QtMultimedia/QMediaPlayer>
#include <QMediaPlaylist>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int Volume;
    QString filePath;
    QString musicPath;
    musicPath=("qrc:/new/prefix1/picture/music.mp3");
    QMediaPlayer *player;
    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->addMedia(QUrl(musicPath));
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    //gameList->addMedia(QUrl("qrc:/img/game.mp3"));//添加音乐
    //gameList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);//循环播放

    player=new QMediaPlayer;//设置默认背景音乐
    player->setMedia(QUrl(musicPath));
    Volume=5;
    player->setVolume(Volume);//音量
    player->play();
    return a.exec();
}
