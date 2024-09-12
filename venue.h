#ifndef VENUE_H
#define VENUE_H

#include <QDialog>

namespace Ui {
class venue;
}

class venue : public QDialog
{
    Q_OBJECT

public:
    explicit venue(QWidget *parent = nullptr);
    ~venue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::venue *ui;
};

#endif // VENUE_H
