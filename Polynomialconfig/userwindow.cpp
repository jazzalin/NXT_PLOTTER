//James Azzalini (c) - window implementation
#include <QApplication>
#include <QtWidgets>
#include "userinterface.h"

int main(int argc, char *argv[])
{
    QApplication usrinput(argc, argv);

    userinterface uiWindow;
    uiWindow.setWindowTitle("NXT Plotter - Polynomial Configuration");
    uiWindow.show();

    return usrinput.exec(); // runs user interface window
}




