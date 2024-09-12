#ifndef TICKET_H
#define TICKET_H

#include <QDialog>

namespace Ui {
class TICKET;
}

class TICKET : public QDialog
{
    Q_OBJECT
public:
    QString *serial1=new QString;
    QString *day1=new QString;
    QString *date1=new QString;
    QString *time1=new QString;
    QString *home1=new QString;
    QString *away1=new QString;
    QString *venue1=new QString;
    QString *type1=new QString;
    QString *category=new QString;
    QString *price=new QString;
public:
    explicit TICKET(QWidget *parent = nullptr);
    ~TICKET();

private slots:
    void on_tableWidget_activated(const QModelIndex &index);

    void on_pushButton_back_clicked();
    void on_pushButton_TICKET_clicked();


    void on_pushButton_clicked();

private:
    Ui::TICKET *ui;
};

#endif // TICKET_H
