#ifndef ROADMAP_H
#define ROADMAP_H

#include <QDialog>

namespace Ui {
class roadmap;
}

class roadmap : public QDialog
{
    Q_OBJECT

public:
    explicit roadmap(QWidget *parent = nullptr);
    ~roadmap();

private:
    Ui::roadmap *ui;
};

#endif // ROADMAP_H
