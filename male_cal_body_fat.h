#ifndef MALE_CAL_BODY_FAT_H
#define MALE_CAL_BODY_FAT_H

#include <QWidget>

namespace Ui {
class male_cal_body_fat;
}

class male_cal_body_fat : public QWidget
{
    Q_OBJECT

public:
    explicit male_cal_body_fat(QWidget *parent = nullptr);
    ~male_cal_body_fat();

private slots:
    void on_pushButtonCal_clicked();

    void on_pushButtonGoBack_clicked();

private:
    Ui::male_cal_body_fat *ui;
    double height, neck, waist;
    double body_fat_value;
};

#endif // MALE_CAL_BODY_FAT_H
