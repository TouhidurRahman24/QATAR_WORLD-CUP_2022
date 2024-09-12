#include "main_menu.h"
#include "qsqlquery.h"
#include "ui_main_menu.h"
#include<group.h>
#include<QSql>
#include<QSqlDatabase>
#include<lineup.h>
#include<ticket.h>
#include<QTimer>
#include<QDate>
#include<QDateTime>
#include <QDebug>
#include<QMessageBox>
#include<roadmap.h>
#include<venue.h>
#include<ui_venue.h>
#include<QMediaPlayer>
#include<qmediaplayer.h>
#include<QSoundEffect>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia>
void show1();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE","myconnect");
      db.setDatabaseName("C:/world_cup/world_cup.sqlite");
    db.open();
    QDateTime now = QDateTime::currentDateTime();
    QDateTime xmas(QDate(now.date().year(), 11, 20), QTime(22, 0));
    int secin=(now.secsTo(xmas));

   unsigned int dayin=secin/86400;
    secin=secin%86400;
   unsigned int hour=secin/3600;
    secin=secin%3600;
   unsigned int min=secin/60;
   unsigned int sec=secin%60;

    /*
    int day = 86400;
    int hour = 3600;
    int minute = 60;



    int daysout = Math.floor(totalseconds / day);
    int hoursout = Math.floor((totalseconds - daysout * day)/hour);
    int minutesout = Math.floor((totalseconds - daysout * day - hoursout * hour)/minute);
    totalseconds - daysout * day - hoursout * hour - minutesout * minute;
*/
    QString hours=QString::number(hour);
    QString mini=QString::number(min);
    QString seco=QString::number(sec);
    QString days=QString::number(dayin);
    QString str=hours+"."+mini+"."+seco;

    QTimer *timer = new QTimer;
    QTime t = QTime::fromString(str, "h.m.s");
        int head1=t.hour();
        int head2=t.minute();
        int head3=t.second();
        QString h1=QString::number(head1);
        QString m1=QString::number(head2);
        QString s1=QString::number(head3);

    *q=days;
    *displayTime = t;

    ui->label->setText(days+" Days "+h1+" Hours "+m1+" Min "+s1+" Sec");
    connect(timer,SIGNAL(timeout()), this, SLOT(show1()));
    timer->start(1000);


    /*
     QMediaPlayer *player = new QMediaPlayer();

      player->setSource(QUrl::fromLocalFile( "C:/world_cup/QATAR_World_Cup_Official_Trailer_Hayya_Hayya_Better_Together_2022.mp3"));
      qDebug()<<player->mediaStatus();
      player->play();
      */
      QSoundEffect effect;
      effect.setSource(QUrl::fromLocalFile("C:/world_cup/QATAR_World_Cup_Official_Trailer_Hayya_Hayya_Better_Together_2022.wav"));
      qDebug()<<effect.isPlaying();

      effect.play();








}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::show1()
{
    int head1=displayTime->hour();
    int head2=displayTime->minute();
    int head3=displayTime->second();
    QString h1=QString::number(head1);
    QString m1=QString::number(head2);
    QString s1=QString::number(head3);

    QTime newTime = displayTime->addSecs(-1);
    displayTime->setHMS(newTime.hour(),newTime.minute(),newTime.second());
    ui->label->setText(q->toUpper()+" Days "+h1+" Hours "+m1+" Min "+s1+" Sec");


    /*
    int sec,min,hr;
     hr=QTime::currentTime().hour();
     min=QTime::currentTime().minute();
      QString s=QTime::currentTime().addSecs(-1).toString();

    QString  day=QDateTime::currentDateTime().toString("dd");
        qint64 da= day.toInt();
        da=da-5;

     s=QString::number(sec);
    QString m=QString::number(min);
    QString h=QString::number(hr);

    ui->label->setText(day+" "+h+" "+m+" "+s);
*/
    if(displayTime->hour() != 0 ||
            displayTime->minute() != 0 ||
            displayTime->second() != 0)
    {
        timer->start(1000);
    }
    else
    {

        timer->stop();
    }
}


void MainWindow::on_pushButton_group_clicked()
{
    GROUP g;
    g.setModal(true);
    g.exec();
}


void MainWindow::on_pushButton_lineup_clicked()
{
    lineup l;
    l.setModal(true);
    l.exec();

}


void MainWindow::on_pushButton_ticket_clicked()
{
    TICKET t;
    t.setModal(true);
    t.exec();
}


void MainWindow::on_pushButton_roadmap_clicked()
{
    roadmap t;
    t.setModal(true);
    t.exec();
}


void MainWindow::on_pushButton_venue_clicked()
{
    venue t;
    t.setModal(true);
    t.exec();
}

