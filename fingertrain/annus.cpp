#include "annus.h"
#include "ui_annus.h"

annus::annus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::annus)
{
    ui->setupUi(this);
}

annus::~annus()
{
    delete ui;
}
