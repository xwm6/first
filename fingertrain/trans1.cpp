#include "trans1.h"
#include "ui_trans1.h"

trans1::trans1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::trans1)
{
    ui->setupUi(this);
}

trans1::~trans1()
{
    delete ui;
}
