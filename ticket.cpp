#include "ticket.h"
#include "ui_ticket.h"
#include<QSql>
#include<QSqlQuery>
#include<QMessageBox>
#include<main_menu.h>
#include<ui_main_menu.h>
#include "main_menu.h"
#include<QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include<QPrintDialog>
#include<QtPrintSupport>
#include<QAbstractPrintDialog>
#include<QMessageBox>
#include <QApplication>
#include <QtCore>
#include<QTextDocument>
#include<webauthn.h>
#include<QtWebView>
TICKET::TICKET(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TICKET)
{
    ui->setupUi(this);

    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE","myconnect");
   db.setDatabaseName("C:/world_cup/world_cup.sqlite");
   if(db.open())
   {

       QSqlQuery query(db);
       QString str ="select * from fixture";
       if(!query.exec(str))
       {
            QMessageBox::warning(this,"building","DATABASE QUERY NOT OPENED");
       }
       else {
           ui->tableWidget->setColumnCount(8);

           ui->tableWidget->setColumnWidth(0,50);
           ui->tableWidget->setColumnWidth(1,50);
           ui->tableWidget->setColumnWidth(2,90);
           ui->tableWidget->setColumnWidth(3,90);
           ui->tableWidget->setColumnWidth(4,90);
           ui->tableWidget->setColumnWidth(5,90);
           ui->tableWidget->setColumnWidth(6,90);
           ui->tableWidget->setColumnWidth(7,120);
           ui->tableWidget->setColumnWidth(8,90);

           int rowcount=0;

           while(query.next())
           {

               ui->tableWidget->insertRow(rowcount);
                QTableWidgetItem *select= new QTableWidgetItem;
                QTableWidgetItem *NAME= new QTableWidgetItem;
                QTableWidgetItem *MOBILE= new QTableWidgetItem;
                QTableWidgetItem *NID= new QTableWidgetItem;
                QTableWidgetItem *H_ADDRESS= new QTableWidgetItem;
                QTableWidgetItem *FLAT= new QTableWidgetItem;
                QTableWidgetItem *RENT= new QTableWidgetItem;
                QTableWidgetItem *DUE= new QTableWidgetItem;
                QTableWidgetItem *ADVANCE= new QTableWidgetItem;


                select->setText(query.value(0).toString());
                FLAT->setText(query.value(1).toString());
                NAME->setText(query.value(2).toString());
                MOBILE->setText(query.value(3).toString());
                NID->setText(query.value(4).toString());
                H_ADDRESS->setText(query.value(5).toString());
                RENT->setText(query.value(6).toString());
                DUE->setText(query.value(7).toString());
                ADVANCE->setText(query.value(8).toString());

                ui->tableWidget->setItem(rowcount,0,select);
                ui->tableWidget->setItem(rowcount,1,FLAT);
                ui->tableWidget->setItem(rowcount,2,NAME);
                ui->tableWidget->setItem(rowcount,3,MOBILE);
                ui->tableWidget->setItem(rowcount,4,NID);
                ui->tableWidget->setItem(rowcount,5,H_ADDRESS);
                ui->tableWidget->setItem(rowcount,6,RENT);
                ui->tableWidget->setItem(rowcount,7,DUE);
                ui->tableWidget->setItem(rowcount,8,ADVANCE);

                rowcount++;
           }
           db.close();
       }
   }
   else
   {
       QMessageBox::warning(this,"building","DATABASE NOT OPENED");
   }



}

TICKET::~TICKET()
{
    delete ui;
}

void TICKET::on_tableWidget_activated(const QModelIndex &index)
{
    int val1 = index.row();
    QString val= QString::number(val1+1);
    QSqlQuery qy(QSqlDatabase::database("myconnect"));
  //qy.prepare("select * from renter(FLAT,H_ADDRESS,MOBILE,NID,NAME)""values(:flat,:H_ADDRESS,:MOBILE,:nid,:name)");
   qy.prepare("select * from fixture where SERIAL='"+val+"'or DAY='"+val+"'or DATE='"+val+"'or TIME='"+val+"'or HOME='"+val+"'or AWAY='"+val+"'or VENUE='"+val+"'or TYPE='"+val+"'");

  if(qy.exec())
  {
      while(qy.next())
       {
            QString serial=qy.value(0).toString();
              QString day=qy.value(1).toString();
               QString date=qy.value(2).toString();
                  QString time=qy.value(3).toString();
                    QString home=qy.value(4).toString();
                     QString away=qy.value(5).toString();
                        QString venue=qy.value(6).toString();
                         QString type= qy.value(7).toString();
            ui->label_HOME->setText(home);
            ui->label_AWAY->setText(away);
            ui->label_STADIUM->setText(venue);
            ui->label_MATCHDAY->setText("MATCH "+serial);
            ui->label_TIME->setText(day+" "+time+" "+date);

            *serial1=serial;
            *day1=day;
            *date1=date;
            *time1=time;
            *home1=home;
            *away1=away;
            *venue1=venue;
            *type1=type;


                         break;

       }


  }
  else
  {
      QMessageBox::warning(this,"Login Form","UNSUCCESSFULL IN QUERY");
  }
}




void TICKET::on_pushButton_back_clicked()
{
    hide();
    MainWindow w;
    w.show();

}


void TICKET::on_pushButton_TICKET_clicked()
{

if(ui->lineEdit_PRICE->text()=="")
{
    QMessageBox::warning(this,"Login Form","PLEASE SELECT FIXTURE AND SEAT");
}
else
{
   QString time=time1->toUpper();
    int timehtml=time.toInt()-2;
    QString price=ui->lineEdit_PRICE->text();
    QString timegate=QString::number(timehtml);
    QString html=
       // { " <html><head><title>CodePen - Admit One Ticket (Aug 2021 #CodePenChallenge)</title></head><body><p align=\"center\"><span style=\" font-family:'Staatliches','cursive'; font-size:14px; color:#a9a9a9;\">QATAR 2022 QATAR 2022 QATAR 2022 </span></p><p align=\"center\"><span style=\" font-family:'Staatliches','cursive'; font-size:10pt; color:#000000;\">TUESDAY NOV 20, 2022</span><span style=\" font-family:'Staatliches','cursive'; font-size:14px; color:#000000;\"/></p><h1 align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:37px; margin-right:37px; -qt-block-indent:0; text-indent:0px; background-color:#ffffff;\"><span style=\" font-family:'Staatliches','cursive'; font-size:xx-large; font-weight:700; color:#000000; background-color:#ffffff;\">Qatar vs Ecuador</span></h1><p align=\"center\"><span style=\" font-family:'Staatliches','cursive'; font-size:10pt; color:#000000; background-color:#ffffff;\">MATCH 1</span></p><p align=\"center\"><span style=\" font-family:'Staatliches','cursive'; font-size:10pt; color:#000000;\">KICK-OF TIME: 22:00 </span></p><p align=\"center\"><span style=\" font-family:'Staatliches','cursive'; font-size:10pt; color:#000000;\">GATES OPEN: 20:00</span></p><p align=\"center\"><span style=\" font-family:'Staatliches','cursive'; font-size:10pt; color:#000000; background-color:#ffffff;\">Tickets number: #20030220</span><span style=\" font-family:'Staatliches','cursive'; font-size:10pt; color:#000000;\"/></p><p align=\"center\"><span style=\" font-family:'Staatliches','cursive'; font-size:10pt; color:#000000;\">AL BAYT STADIUM, AL KHOR MF2Q+V4Q, AL KHOR, QATAR </span></p><p align=\"center\"><img src=\"C:/world_cup/qr.png\" alt=\"QR code\" style=\"width:60px;height:60px;\"/></p><p align=\"center\"><br/></p></body></html>"};
{"<html><head>  <title>QATAR 2022</title></head><body>  <p align=\"center\">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 14px;          color: #a9a9a9;        \">QATAR 2022 QATAR 2022 QATAR 2022    </span>  </p>  <p align=\"center\">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 10pt;          color: #000000;        \">"+date1->toUpper()+"</span><span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 14px;          color: #000000;        \" />  </p>  <h1 align=\"center\" style=\"        margin-top: 0px;        margin-bottom: 0px;        margin-left: 37px;        margin-right: 37px;        -qt-block-indent: 0;        text-indent: 0px;        background-color: #ffffff;      \">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: xx-large;          font-weight: 700;          color: #000000;          background-color: #ffffff;        \">"+home1->toUpper()+" VS "+away1->toUpper()+"</span>  </h1>  <p align=\"center\">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 10pt;          color: #000000;          background-color: #ffffff;        \">"+"MATCH "+serial1->toUpper()+"</span>  </p>  <p align=\"center\">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 10pt;          color: #000000;        \">KICK-OF TIME: "+time1->toUpper()+":00</span>  </p>  <p align=\"center\">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 10pt;          color: #000000;        \">GATES OPEN: "+timegate+":00</span>  </p>  <p align=\"center\">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 10pt;          color: #000000;        \">Category: "+category->toUpper()+"</span>  </p>  <p align=\"center\">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 10pt;          color: #000000;        \">Price: "+price+" </span>  </p>  <p align=\"center\">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 10pt;          color: #000000;          background-color: #ffffff;        \">Tickets number: #2003022</span><span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 10pt;          color: #000000;        \" />  </p>  <p align=\"center\">    <span style=\"          font-family: 'Staatliches', 'cursive';          font-size: 10pt;          color: #000000;        \">VENUE: "+venue1->toUpper()+"    </span>  </p>  <p align=\"center\">    <img src=\"C:/world_cup/qr.png\" alt=\"QR code\" style=\"width: 60px; height: 60px\" />  </p>  <p align=\"center\"><br /></p></body></html>"};


    QTextDocument document;
    document.addResource(QTextDocument::StyleSheetResource, QUrl( "style.css" ),html);
    document.setHtml(html);
     QString s=home1->toUpper()+"_VS_"+away1->toUpper()+"_CATERGORY_"+category->toUpper();
             ;
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("C:/"+s+".pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    document.print(&printer);
    QMessageBox q;

    q.setStyleSheet("color: rgb(255, 255, 255);");
    q.setStyleSheet("background-color: rgb(255, 255, 255);");
    q.information(this,"TICKET","TICKET ISSUED");
}


}


void TICKET::on_pushButton_clicked()
{
   QString match =serial1->toUpper();
    QSqlQuery qy(QSqlDatabase::database("myconnect"));
    qy.prepare("select * from fixture where SERIAL=:match");
    qy.bindValue(":match",match);
    if(qy.exec())
    {
       while(qy.next())
       {
          float percent =qy.value(8).toFloat();
                if(ui->radioButton_1->isChecked())
                {
                    *category="A";
                     percent=80000*percent;
                    QString cat1=QString::number(percent);
                    ui->lineEdit_PRICE->setText(cat1);

                }
                if(ui->radioButton_2->isChecked())
                {
                    *category="B";
                    percent=60000*percent;
                   QString cat1=QString::number(percent);

                    ui->lineEdit_PRICE->setText(cat1);
                }
                if(ui->radioButton_3->isChecked())
                {
                    *category="C";
                    percent=40000*percent;
                   QString cat1=QString::number(percent);

                    ui->lineEdit_PRICE->setText(cat1);
                }
                if(ui->radioButton_4->isChecked())
                {
                    *category="D";
                    percent=20000*percent;
                   QString cat1=QString::number(percent);

                    ui->lineEdit_PRICE->setText(cat1);
                }
       }
    }
    else
    {
        QMessageBox::warning(this,"Login Form","UNSUCCESSFULL IN QUERY");
    }
}

