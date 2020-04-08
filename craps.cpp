#include <iostream>
#include <stdio.h>
#include "die.h"
#include "craps.h"
#include "ui_CrapsMainWindow.h"

CrapsMainWindow :: CrapsMainWindow(QMainWindow *parent)
{
    setupUi(this);

    Die die1, die2;
    bool firstRoll = true;
    int winsCount = 0;

    QObject::connect(rollButton, SIGNAL(clicked()), this, SLOT(rollButtonClickedHandler()));
}

void CrapsMainWindow::printStringRep()
{
    char buffer[25];
    int length =  sprintf(buffer, "Die1: %i\nDie2: %i\n", die1.getValue(), die2.getValue());
    printf("%s", buffer);
}
void CrapsMainWindow::updateUI()
{
    std::string die1ImageName = ":/dieImages/" + std::to_string(die1.getValue());
    std::string die2ImageName = ":/dieImages/" + std::to_string(die2.getValue());
    die1UI->setPixmap(QPixmap(QString::fromStdString(die1ImageName)));
    die2UI->setPixmap(QPixmap(QString::fromStdString(die2ImageName)));
    currentBankValueUI->setText(QString::fromStdString("100"));
}

void CrapsMainWindow::rollButtonClickedHandler()
{
    printf("Roll button clicked\n");
    die1.roll();
    die2.roll();
    printStringRep();
    updateUI();
}

