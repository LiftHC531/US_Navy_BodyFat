#include "choosewindow.h"

#include <QApplication>
#include <QFile>
#include <QString>
#include <QDoubleValidator>

/*
 *References:
 * https://linwebs.tw/course/qt/bmi-calculator
 * https://www.youtube.com/watch?v=oMMp9nFLrPk
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile(":/src/style/Combinear.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);

    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1.5");
    chooseWindow w;
    w.setWindowTitle("體脂計算-美國海軍估測法(US Navy method)");
    w.show();
    return a.exec();
}
