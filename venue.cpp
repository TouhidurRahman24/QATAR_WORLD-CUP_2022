#include "venue.h"
#include "qsqlquery.h"
#include "ui_venue.h"
#include<QTimer>
#include<QSql>
#include<QSqlDatabase>
#include<lineup.h>
#include<ticket.h>
#include<QTimer>
#include<QDate>
#include<QDateTime>
#include <QDebug>
#include<QMessageBox>
venue::venue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::venue)
{
    ui->setupUi(this);


}

venue::~venue()
{
    delete ui;
}

void venue::on_pushButton_clicked()
{

    int s=ui->comboBox->currentIndex();
    QSqlQuery qy(QSqlDatabase::database("myconnect"));
    qy.prepare("select * from VENUE where SERIAL=:match");
    qy.bindValue(":match",s);
    if(qy.exec())
    {
        while(qy.next())
        {
                ui->lineEdit_stadium->setText(qy.value(1).toString());
                ui->lineEdit_location->setText(qy.value(2).toString());
                ui->lineEdit_capacity->setText(qy.value(3).toString());
                ui->lineEdit_open->setText(qy.value(4).toString());
                ui->lineEdit_match->setText(qy.value(5).toString());
                ui->lineEdit_field->setText(qy.value(6).toString());
                ui->lineEdit_cost->setText(qy.value(7).toString());
                ui->textEdit_des->setText(qy.value(8).toString());
                if(s==1)
                {
                    QPixmap pix("C:/world_cup/lusail.jpg");
                    ui->label_pic->setPixmap(pix.scaled(350,350,Qt::KeepAspectRatio));
                    QPixmap pix1("C:/world_cup/qr_lusail.png");
                    ui->label_PICQR->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));

                }
                else if(s==2)
                {
                    QPixmap pix("C:/world_cup/al-bayt-stadium.png");
                    ui->label_pic->setPixmap(pix.scaled(350,350,Qt::KeepAspectRatio));
                    QPixmap pix1("C:/world_cup/qr_albayt.png");
                    ui->label_PICQR->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
                }
                else if(s==3)
                {
                    QPixmap pix("C:/world_cup/AL_JANOUB.png");
                    ui->label_pic->setPixmap(pix.scaled(350,350,Qt::KeepAspectRatio));
                    QPixmap pix1("C:/world_cup/qr_aljamoub.png");
                    ui->label_PICQR->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
                }
                else if(s==4)
                {
                    QPixmap pix("C:/world_cup/ahmed-bin-ali-stadium.png");
                     ui->label_pic->setPixmap(pix.scaled(350,350,Qt::KeepAspectRatio));
                     QPixmap pix1("C:/world_cup/qr_ahmed_ali.png");
                     ui->label_PICQR->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
                }
                else if(s==5)
                {
                    QPixmap pix("C:/world_cup/Khalifa-International-Stadium-3.jpg");
                    ui->label_pic->setPixmap(pix.scaled(350,350,Qt::KeepAspectRatio));
                    QPixmap pix1("C:/world_cup/qr_khalifa.png");
                    ui->label_PICQR->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
                }
                else if(s==6)
                {
                    QPixmap pix("C:/world_cup/Education_City_Stadium_-_Hero.png");
                    ui->label_pic->setPixmap(pix.scaled(350,350,Qt::KeepAspectRatio));
                    QPixmap pix1("C:/world_cup/qr_education_city.png");
                    ui->label_PICQR->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
                }
                else if(s==7)
                {
                    QPixmap pix("C:/world_cup/FIFA-World-Cup-Qatar-2022-Venue-Aerial-Views.png");
                    ui->label_pic->setPixmap(pix.scaled(350,350,Qt::KeepAspectRatio));
                    QPixmap pix1("C:/world_cup/qr_stadium_974.png");
                    ui->label_PICQR->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
                }
                else if(s==8)
                {
                    QPixmap pix("C:/world_cup/al_thumama.jpg");
                    ui->label_pic->setPixmap(pix.scaled(350,350,Qt::KeepAspectRatio));
                    QPixmap pix1("C:/world_cup/qr_althumama.png");
                    ui->label_PICQR->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));
                }

        }



    }
    else
    {
        QMessageBox::warning(this,"building","DATABASE QUERY NOT OPENED");
    }


}

