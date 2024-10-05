#include "choosewindow.h"
#include "ui_choosewindow.h"
#include "male_cal_body_fat.h"
#include "female_cal_body_fat.h"

chooseWindow::chooseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chooseWindow)
{
    ui->setupUi(this);
}

chooseWindow::~chooseWindow()
{
    delete ui;
}


void chooseWindow::on_MalepushButton_clicked()
{
    male_cal_body_fat *male = new male_cal_body_fat;  // Allocate on heap
    male->setAttribute(Qt::WA_DeleteOnClose);  // Delete when closed
    male->setWindowTitle("體脂計算(男)-美國海軍估測法(US Navy method)");
    male->resize(this->size());
    male->show();  // Show the window
    this->close(); // hide()
}

void chooseWindow::on_FemalepushButton_clicked()
{
    female_cal_body_fat *female = new female_cal_body_fat;  // Allocate on heap
    female->setAttribute(Qt::WA_DeleteOnClose);  // Delete when closed
    female->setWindowTitle("體脂計算(女)-美國海軍估測法(US Navy method)");
    female->resize(this->size());
    female->show();  // Show the window
    this->close(); // hide()
}
