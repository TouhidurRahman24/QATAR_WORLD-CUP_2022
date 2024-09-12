#include "lineup.h"
#include "ui_lineup.h"
#include<QSqlQuery>
#include<QMessageBox>

lineup::lineup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lineup)
{

    ui->setupUi(this);
}

lineup::~lineup()
{
    delete ui;
}

void lineup::on_pushButton_clicked()
{


QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE","myconnect");
  db.setDatabaseName("C:/world_cup/world_cup.sqlite");
if(db.open())
{
QSqlQuery qy(QSqlDatabase::database("myconnect"));
QString team=ui->lineEdit->text().toUpper();
 qDebug()<<team;
qy.prepare("select * from lineup where UPPER(Team)='"+team+"'");
if(qy.exec())
{
  if(qy.next())
   {
      qDebug()<<qy.value(1).toString();
      ui->label_TEAM->setText(qy.value(1).toString());
      ui->label_m->setText(qy.value(2).toString());
      ui->label_p1->setText(qy.value(3).toString());
      ui->label_p1n->setText(qy.value(4).toString()+"  "+qy.value(3).toString());
      ui->label_p2->setText(qy.value(5).toString());
      ui->label_p2n->setText(qy.value(6).toString()+"  "+qy.value(5).toString());
      ui->label_p3->setText(qy.value(7).toString());
      ui->label_p3n->setText(qy.value(8).toString()+"  "+qy.value(7).toString());
      ui->label_p4->setText(qy.value(9).toString());
      ui->label_p4n->setText(qy.value(10).toString()+"  "+qy.value(9).toString());
      ui->label_p5->setText(qy.value(11).toString());
      ui->label_p5n->setText(qy.value(12).toString()+"  "+qy.value(11).toString());
      ui->label_p6->setText(qy.value(13).toString());
      ui->label_p6n->setText(qy.value(14).toString()+"  "+qy.value(13).toString());
      ui->label_p7->setText(qy.value(15).toString());
      ui->label_p7n->setText(qy.value(16).toString()+"  "+qy.value(15).toString());
      ui->label_p8->setText(qy.value(17).toString());
      ui->label_p8n->setText(qy.value(18).toString()+"  "+qy.value(17).toString());
      ui->label_p9->setText(qy.value(19).toString());
      ui->label_p9n->setText(qy.value(20).toString()+"  "+qy.value(19).toString());
      ui->label_p10->setText(qy.value(21).toString());
      ui->label_p10n->setText(qy.value(22).toString()+"  "+qy.value(21).toString());
      ui->label_p11->setText(qy.value(23).toString());
      ui->label_p11n->setText(qy.value(24).toString()+"  "+qy.value(23).toString());
      ui->label_p12->setText(qy.value(25).toString());
      ui->label_p13->setText(qy.value(27).toString());
      ui->label_p14->setText(qy.value(29).toString());
      ui->label_p15->setText(qy.value(31).toString());
   }

}
else
{

    QMessageBox::warning(this,"world cup","QUERY NOT HAPPENED");
}

}
else
{
    QMessageBox::warning(this,"world cup","DATABASE NOT OPENED");
}



}

