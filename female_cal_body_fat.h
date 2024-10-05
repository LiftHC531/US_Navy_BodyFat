#ifndef FEMALE_CAL_BODY_FAT_H
#define FEMALE_CAL_BODY_FAT_H

#include <QWidget>

namespace Ui {
class female_cal_body_fat;
}

class female_cal_body_fat : public QWidget
{
    Q_OBJECT

public:
    explicit female_cal_body_fat(QWidget *parent = nullptr);
    ~female_cal_body_fat();

private slots:
    void on_pushButtonCal_2_clicked();

    void on_pushButtonGoBack_2_clicked();

private:
    Ui::female_cal_body_fat *ui;
    double height, neck, waist, hip;
    double body_fat_value;
};

#endif // FEMALE_CAL_BODY_FAT_H
