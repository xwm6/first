#include "userchoose.h"
#include "ui_userchoose.h"
#include "annus.h"
#include "ui_annus.h"

userchoose::userchoose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userchoose)
{
    ui->setupUi(this);
    annus *a=new annus();
    ui->scrollArea->setWidget(a);
}

userchoose::~userchoose()
{
    delete ui;
}
