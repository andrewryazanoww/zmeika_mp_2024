#include <menu.h>
#include <QApplication>
#include "mainwindow.h"
#include "authorization2.h"
#include "application.h"
#include "playerinfo.h"
#include <QFile>
#include "splashscreen.h"

int main(int argc, char *argv[])
{
    QString filename = "C:/Qt/project/build-jsonclient-Desktop_Qt_6_6_2_MinGW_64_bit-Debug/score.txt";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        file.close();
    } else {
        qDebug() << "Ошибка при открытии файла для очистки";
        return 1;
    }
    Application::getSocket();
    QApplication a(argc, argv);
    SplashScreen menu;
    authorization2 auth;
    qDebug() << "Connecting menuFinished() signal to authorization2::show() slot";

    QObject::connect(&menu, &SplashScreen::menuFinished, &auth, &authorization2::show);
    menu.show();
    return a.exec();

}
