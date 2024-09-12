#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include <QMainWindow>
#include <QTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QTimer *timer=new QTimer(this);
    QTime *displayTime = new QTime;
    QString *q= new QString;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_group_clicked();

    void on_pushButton_lineup_clicked();

    void on_pushButton_ticket_clicked();
    void show1();

    void on_pushButton_roadmap_clicked();

    void on_pushButton_venue_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAIN_MENU_H
