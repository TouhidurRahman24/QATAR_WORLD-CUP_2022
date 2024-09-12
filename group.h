#ifndef GROUP_H
#define GROUP_H

#include <QDialog>

namespace Ui {
class GROUP;
}

class GROUP : public QDialog
{
    Q_OBJECT

public:
    explicit GROUP(QWidget *parent = nullptr);
    ~GROUP();

private:
    Ui::GROUP *ui;
};

#endif // GROUP_H
