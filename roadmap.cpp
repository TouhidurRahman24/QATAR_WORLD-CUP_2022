#include "roadmap.h"
#include "ui_roadmap.h"

roadmap::roadmap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::roadmap)
{
    ui->setupUi(this);
}

roadmap::~roadmap()
{
    delete ui;
}
