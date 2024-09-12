#ifndef LINEUP_H
#define LINEUP_H

#include <QDialog>

namespace Ui {
class lineup;
}

class lineup : public QDialog
{
    Q_OBJECT

public:
    explicit lineup(QWidget *parent = nullptr);
    ~lineup();

private slots:
    void on_pushButton_clicked();

private:
    Ui::lineup *ui;
};

#endif // LINEUP_H
