#include "female_cal_body_fat.h"
#include "ui_female_cal_body_fat.h"
#include "choosewindow.h"
#include <math.h>
#include "func.h"
#include <QDoubleValidator>

female_cal_body_fat::female_cal_body_fat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::female_cal_body_fat)
{
    ui->setupUi(this);

    QDoubleValidator* double_validator = new QDoubleValidator();

    ui->lineEditHeight2->setValidator(double_validator);
    ui->lineEditNeck2->setValidator(double_validator);
    ui->lineEditWaist2->setValidator(double_validator);
    ui->lineEditHip2->setValidator(double_validator);
}

female_cal_body_fat::~female_cal_body_fat()
{
    delete ui;
}

void female_cal_body_fat::on_pushButtonCal_2_clicked()
{
    height = ui->lineEditHeight2->text().toDouble(); // [cm]
    neck = ui->lineEditNeck2->text().toDouble(); // [inch]
    waist = ui->lineEditWaist2->text().toDouble(); // [inch]
    hip = ui->lineEditHip2->text().toDouble(); // [inch]

    height = cm2inch(height); // [cm]->[inch]

    // US Navy method
    calculateFemaleBodyFat(height, neck, waist, hip, &body_fat_value);
    body_fat_value = round(body_fat_value*10.e0)/10.e0;
    ui->labelOutputBdyFat_2->setText(QString::number(body_fat_value) + "%");
}

void female_cal_body_fat::on_pushButtonGoBack_2_clicked()
{
    chooseWindow *choose = new chooseWindow;  // Allocate on heap
    choose->setAttribute(Qt::WA_DeleteOnClose);  // Delete when closed
    choose->setWindowTitle("體脂計算-美國海軍估測法(US Navy method)");
    choose->show();  // Show the window
    this->close();
}
