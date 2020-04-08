//
// Created by Ryan Simas on 2/18/20.
//

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include "craps.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CrapsMainWindow crapsApp;
    crapsApp.updateUI();
    crapsApp.show();
    return app.exec();
}

