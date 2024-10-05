#include "male_cal_body_fat.h"
#include "ui_male_cal_body_fat.h"
#include "choosewindow.h"
#include <math.h>
#include "func.h"
#include <QDoubleValidator>

male_cal_body_fat::male_cal_body_fat(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::male_cal_body_fat)
{
    ui->setupUi(this);

    QDoubleValidator* double_validator = new QDoubleValidator();

    ui->lineEditHeight->setValidator(double_validator);
    ui->lineEditNeck->setValidator(double_validator);
    ui->lineEditWaist->setValidator(double_validator);
}

male_cal_body_fat::~male_cal_body_fat()
{
    delete ui;
}

void male_cal_body_fat::on_pushButtonCal_clicked()
{
    height = ui->lineEditHeight->text().toDouble(); // [cm]
    neck = ui->lineEditNeck->text().toDouble(); // [inch]
    waist = ui->lineEditWaist->text().toDouble(); // [inch]

    height = cm2inch(height); // [cm]->[inch]

    // US Navy method
    calculateMaleBodyFat(height, neck, waist, &body_fat_value);
    body_fat_value = round(body_fat_value*10.e0)/10.e0;
    ui->labelOutputBdyFat->setText(QString::number(body_fat_value) + "%");
}

void male_cal_body_fat::on_pushButtonGoBack_clicked()
{
    chooseWindow *choose = new chooseWindow;  // Allocate on heap
    choose->setAttribute(Qt::WA_DeleteOnClose);  // Delete when closed
    choose->setWindowTitle("體脂計算-美國海軍估測法(US Navy method)");
    choose->show();  // Show the window
    this->close();
}
