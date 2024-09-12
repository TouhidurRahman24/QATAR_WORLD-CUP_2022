#include "group.h"
#include "qsqldatabase.h"
#include "ui_group.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QPixmap>
#include<qsqlquery.h>
#include "qsqlquery.h"
#include<qmatrix4x4.h>
#include "qsqlquerymodel.h"
GROUP::GROUP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GROUP)
{
    ui->setupUi(this);


    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE","myconnect");
        db.setDatabaseName("C:/world_cup/world_cup.sqlite");
        db.open();

       QSqlQuery query(QSqlDatabase::database("myconnect"));
       QSqlQuery query1(QSqlDatabase::database("myconnect"));
       QSqlQuery query2(QSqlDatabase::database("myconnect"));
       QSqlQuery query3(QSqlDatabase::database("myconnect"));
       QSqlQuery query4(QSqlDatabase::database("myconnect"));
       QSqlQuery query5(QSqlDatabase::database("myconnect"));
       QSqlQuery query6(QSqlDatabase::database("myconnect"));
       QSqlQuery query7(QSqlDatabase::database("myconnect"));
       QSqlQuery query8(QSqlDatabase::database("myconnect"));
       QSqlQuery query9(QSqlDatabase::database("myconnect"));



        query.prepare(" SELECT * FROM team order by SERIAL ASC limit 4 ");
        query1.prepare("SELECT * FROM team order by SERIAL ASC limit 4,4");
        query2.prepare("SELECT * FROM team order by SERIAL ASC limit 8,4");
        query3.prepare("SELECT * FROM team order by SERIAL ASC limit 12,4");
        query4.prepare("SELECT * FROM team order by SERIAL ASC limit 16,4");
        query5.prepare("SELECT * FROM team order by SERIAL ASC limit 20,4");
        query6.prepare("SELECT * FROM team order by SERIAL ASC limit 24,4");
        query7.prepare("SELECT * FROM team order by SERIAL ASC limit 28,4");
        query8.prepare("SELECT * FROM PLAYER");

        if(!query.exec())
        {
             QMessageBox::warning(this,"building","DATABASE QUERY NOT OPENED");
        }
        else {

            ui->tableWidget->setColumnCount(3);
            ui->tableWidget_2->setColumnCount(3);
            ui->tableWidget_3->setColumnCount(3);
            ui->tableWidget_4->setColumnCount(3);
            ui->tableWidget_5->setColumnCount(3);
            ui->tableWidget_6->setColumnCount(3);
            ui->tableWidget_7->setColumnCount(3);
            ui->tableWidget_8->setColumnCount(3);



            int rowcount=0;

           while(query.next())
          {

                ui->tableWidget->insertRow(rowcount);
                ui->tableWidget->setColumnWidth(0,5);
                ui->tableWidget->setColumnWidth(1,10);
                ui->tableWidget->setColumnWidth(2,110);


                 QTableWidgetItem *serial= new QTableWidgetItem;
                 QTableWidgetItem *thumbnail = new QTableWidgetItem;
                 QTableWidgetItem *name= new QTableWidgetItem;

                 serial->setText(query.value(0).toString());
                 name->setText(query.value(2).toString());
                 if(rowcount==1)
                 {
                 QString imgPath ="C:/world_cup/Flag_of_equador.png";
                 QImage *img = new QImage();
                 bool loaded = img->load(imgPath);
                 if (loaded) {

                     thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                     ui->tableWidget->setItem(rowcount,1,thumbnail);

                 } else {
                     qDebug()<<"Image "<<imgPath<<" was not opened!";
                 }

                 }
                 else if(rowcount==2)
                 {
                     QString imgPath ="C:/world_cup/download.png";
                     QImage *img = new QImage();
                     bool loaded = img->load(imgPath);
                     if (loaded) {

                         thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                         ui->tableWidget->setItem(rowcount,1,thumbnail);

                     } else {
                         qDebug()<<"Image "<<imgPath<<" was not opened!";
                     }

                 }
                 else
                 {
                     QString imgPath =query.value(1).toString();

                 QImage *img = new QImage();
                 bool loaded = img->load(imgPath);
                 if (loaded) {

                     thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                     ui->tableWidget->setItem(rowcount,1,thumbnail);

                 } else {
                     qDebug()<<"Image "<<imgPath<<" was not opened!";
                 }
                 }
                 ui->tableWidget->setItem(rowcount,0,serial);
                 ui->tableWidget->setItem(rowcount,2,name);



                 rowcount++;
        }
            rowcount=0;
            query1.exec();
           while(query1.next())
          {

                ui->tableWidget_2->insertRow(rowcount);
                ui->tableWidget_2->setColumnWidth(0,5);
                ui->tableWidget_2->setColumnWidth(1,10);
                ui->tableWidget_2->setColumnWidth(2,110);
                 QTableWidgetItem *serial= new QTableWidgetItem;
                 QTableWidgetItem *thumbnail = new QTableWidgetItem;
                 QTableWidgetItem *name= new QTableWidgetItem;

                 serial->setText(query1.value(0).toString());
                 name->setText(query1.value(2).toString());
                 QString imgPath = query1.value(1).toString();
                 QImage *img = new QImage();
                 bool loaded = img->load(imgPath);
                 if (loaded) {

                     thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                     ui->tableWidget_2->setItem(rowcount,1,thumbnail);

                 } else {
                     qDebug()<<"Image "<<imgPath<<" was not opened!";
                 }

                 ui->tableWidget_2->setItem(rowcount,0,serial);
                 ui->tableWidget_2->setItem(rowcount,2,name);



                 rowcount++;
        }
           rowcount=0;
           query2.exec();

           while(query2.next())
          {

                ui->tableWidget_3->insertRow(rowcount);
                ui->tableWidget_3->setColumnWidth(0,5);
                ui->tableWidget_3->setColumnWidth(1,10);
                ui->tableWidget_3->setColumnWidth(2,110);
                 QTableWidgetItem *serial= new QTableWidgetItem;
                 QTableWidgetItem *thumbnail = new QTableWidgetItem;
                 QTableWidgetItem *name= new QTableWidgetItem;

                 serial->setText(query2.value(0).toString());
                 name->setText(query2.value(2).toString());
                 QString imgPath = query2.value(1).toString();
                 QImage *img = new QImage();
                 bool loaded = img->load(imgPath);
                 if (loaded) {

                     thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                     ui->tableWidget_3->setItem(rowcount,1,thumbnail);

                 } else {
                     qDebug()<<"Image "<<imgPath<<" was not opened!";
                 }

                 ui->tableWidget_3->setItem(rowcount,0,serial);
                 ui->tableWidget_3->setItem(rowcount,2,name);



                 rowcount++;
        }
           rowcount=0;
           query3.exec();

           while(query3.next())
          {

                ui->tableWidget_4->insertRow(rowcount);
                ui->tableWidget_4->setColumnWidth(0,5);
                ui->tableWidget_4->setColumnWidth(1,10);
                ui->tableWidget_4->setColumnWidth(2,110);
                 QTableWidgetItem *serial= new QTableWidgetItem;
                 QTableWidgetItem *thumbnail = new QTableWidgetItem;
                 QTableWidgetItem *name= new QTableWidgetItem;

                 serial->setText(query3.value(0).toString());
                 name->setText(query3.value(2).toString());
                 QString imgPath = query3.value(1).toString();
                 QImage *img = new QImage();
                 bool loaded = img->load(imgPath);
                 if (loaded) {

                     thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                     ui->tableWidget_4->setItem(rowcount,1,thumbnail);

                 } else {
                     qDebug()<<"Image "<<imgPath<<" was not opened!";
                 }

                 ui->tableWidget_4->setItem(rowcount,0,serial);
                 ui->tableWidget_4->setItem(rowcount,2,name);

                 rowcount++;
        }
           rowcount=0;
           query4.exec();
           while(query4.next())
          {

                ui->tableWidget_5->insertRow(rowcount);
                ui->tableWidget_5->setColumnWidth(0,5);
                ui->tableWidget_5->setColumnWidth(1,10);
                ui->tableWidget_5->setColumnWidth(2,110);
                 QTableWidgetItem *serial= new QTableWidgetItem;
                 QTableWidgetItem *thumbnail = new QTableWidgetItem;
                 QTableWidgetItem *name= new QTableWidgetItem;

                 serial->setText(query4.value(0).toString());
                 name->setText(query4.value(2).toString());
                 QString imgPath = query4.value(1).toString();
                 QImage *img = new QImage();
                 bool loaded = img->load(imgPath);
                 if (loaded) {

                     thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                     ui->tableWidget_5->setItem(rowcount,1,thumbnail);

                 } else {
                     qDebug()<<"Image "<<imgPath<<" was not opened!";
                 }

                 ui->tableWidget_5->setItem(rowcount,0,serial);
                 ui->tableWidget_5->setItem(rowcount,2,name);



                 rowcount++;
        }
           rowcount=0;
           query5.exec();

           while(query5.next())
          {

                ui->tableWidget_6->insertRow(rowcount);
                ui->tableWidget_6->setColumnWidth(0,5);
                ui->tableWidget_6->setColumnWidth(1,10);
                ui->tableWidget_6->setColumnWidth(2,110);
                 QTableWidgetItem *serial= new QTableWidgetItem;
                 QTableWidgetItem *thumbnail = new QTableWidgetItem;
                 QTableWidgetItem *name= new QTableWidgetItem;

                 serial->setText(query5.value(0).toString());
                 name->setText(query5.value(2).toString());
                 QString imgPath = query5.value(1).toString();
                 QImage *img = new QImage();
                 bool loaded = img->load(imgPath);
                 if (loaded) {

                     thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                     ui->tableWidget_6->setItem(rowcount,1,thumbnail);

                 } else {
                     qDebug()<<"Image "<<imgPath<<" was not opened!";
                 }

                 ui->tableWidget_6->setItem(rowcount,0,serial);
                 ui->tableWidget_6->setItem(rowcount,2,name);



                 rowcount++;
        }
           rowcount=0;
           query6.exec();
           while(query6.next())
          {

                ui->tableWidget_7->insertRow(rowcount);
                ui->tableWidget_7->setColumnWidth(0,5);
                ui->tableWidget_7->setColumnWidth(1,10);
                ui->tableWidget_7->setColumnWidth(2,110);
                 QTableWidgetItem *serial= new QTableWidgetItem;
                 QTableWidgetItem *thumbnail = new QTableWidgetItem;
                 QTableWidgetItem *name= new QTableWidgetItem;

                 serial->setText(query6.value(0).toString());
                 name->setText(query6.value(2).toString());
                 QString imgPath = query6.value(1).toString();
                 QImage *img = new QImage();
                 bool loaded = img->load(imgPath);
                 if (loaded) {

                     thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                     ui->tableWidget_7->setItem(rowcount,1,thumbnail);

                 } else {
                     qDebug()<<"Image "<<imgPath<<" was not opened!";
                 }

                 ui->tableWidget_7->setItem(rowcount,0,serial);
                 ui->tableWidget_7->setItem(rowcount,2,name);



                 rowcount++;
        }
           rowcount=0;
           query7.exec();
           while(query7.next())
          {

                ui->tableWidget_8->insertRow(rowcount);
                ui->tableWidget_8->setColumnWidth(0,5);
                ui->tableWidget_8->setColumnWidth(1,10);
                ui->tableWidget_8->setColumnWidth(2,110);
                 QTableWidgetItem *serial= new QTableWidgetItem;
                 QTableWidgetItem *thumbnail = new QTableWidgetItem;
                 QTableWidgetItem *name= new QTableWidgetItem;

                 serial->setText(query7.value(0).toString());
                 name->setText(query7.value(2).toString());
                 QString imgPath = query7.value(1).toString();
                 QImage *img = new QImage();
                 bool loaded = img->load(imgPath);
                 if (loaded) {

                     thumbnail->setData(Qt::DecorationRole, QPixmap::fromImage(*img).scaled(20,20));
                     ui->tableWidget_8->setItem(rowcount,1,thumbnail);

                 } else {
                     qDebug()<<"Image "<<imgPath<<" was not opened!";
                 }

                 ui->tableWidget_8->setItem(rowcount,0,serial);
                 ui->tableWidget_8->setItem(rowcount,2,name);



                 rowcount++;
        }














        }



}

GROUP::~GROUP()
{
    delete ui;
}
