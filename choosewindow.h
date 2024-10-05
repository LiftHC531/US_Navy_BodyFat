#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class chooseWindow; }
QT_END_NAMESPACE

class chooseWindow : public QMainWindow
{
    Q_OBJECT

public:
    chooseWindow(QWidget *parent = nullptr);
    ~chooseWindow();

private slots:
    void on_MalepushButton_clicked();

    void on_FemalepushButton_clicked();

private:
    Ui::chooseWindow *ui;
};
#endif // CHOOSEWINDOW_H
