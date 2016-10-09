//James Azzalini (c) - userinterface class implementation
#include "userinterface.h"
#include "ui_userinterface.h"
#include <QtWidgets>
#include <QFile>
#include <QTextStream>

userinterface::userinterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userinterface)
{
    //Getting values from ui
    ui->setupUi(this);

    //Enable coefficient configuration --> default configuration
    ui->coeffA->setEnabled(true);
    ui->coeffB->setEnabled(false);
    ui->coeffC->setEnabled(false);
    ui->coeffD->setEnabled(false);
    ui->coeffE->setEnabled(false);
    ui->coeffF->setEnabled(false);

    ui->quintic->setVisible(false);
    ui->quartic->setVisible(false);
    ui->cubic->setVisible(false);
    ui->quadratic->setVisible(false);
    ui->linear->setVisible(false);
    ui->constant->setVisible(true);

    //Signal - slots connexions: plotButton --> outputs to text file; orderSlider --> enanble coefficients/change value
    connect(ui->plotButton, SIGNAL(clicked()), this, SLOT(plot()));
    connect(ui->orderSlider, SIGNAL(valueChanged(int)), this, SLOT(enableButton(int)));
}

//Slot (responds to signal): coefficients ouput to file
void userinterface::plot()
{
    //Open file for output
    QString outputFilename = "Polynomials.txt";
    QFile outputFile(outputFilename);
    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);

    // Point a QTextStream object at the file
    QTextStream outStream(&outputFile);

    int order = ui->u_orderPoly->text().toInt();//here order refers to the degree of the polynomial
    float coeffA = ui->coeffA->text().toFloat();
    float coeffB = ui->coeffB->text().toFloat();
    float coeffC = ui->coeffC->text().toFloat();
    float coeffD = ui->coeffD->text().toFloat();
    float coeffE = ui->coeffE->text().toFloat();
    float coeffF = ui->coeffF->text().toFloat();

    outStream << order << " ";

    //Outut in reverse order
    switch(order)
    {
    case 0:
        outStream << coeffA << endl;
        break;

    case 1:
        outStream << coeffB <<" "<< coeffA << endl;
        break;

    case 2:
        outStream << coeffC <<" "<< coeffB <<" "<< coeffA << endl;
        break;

    case 3:
        outStream << coeffD <<" "<< coeffC <<" "<< coeffB <<" "<<coeffA << endl;
        break;

    case 4:
        outStream << coeffE << " " << coeffD <<" "<< coeffC <<" "<< coeffB <<" "<<coeffA << endl;
        break;

    case 5:
        outStream << coeffF << " " << coeffE << " " << coeffD <<" "<< coeffC <<" "<< coeffB <<" "<<coeffA << endl;
        break;
    }

    outputFile.close();
}

//Enables or disables the coeffcients according to the degree chosen
void userinterface::enableButton(int value)
{
    switch(value)
    {
    case 0://if user decides to move the slider back to zero
        ui->coeffA->setEnabled(true);
        ui->coeffB->setEnabled(false);
        ui->coeffC->setEnabled(false);
        ui->coeffD->setEnabled(false);
        ui->coeffE->setEnabled(false);
        ui->coeffF->setEnabled(false);

        ui->quintic->setVisible(false);
        ui->quartic->setVisible(false);
        ui->cubic->setVisible(false);
        ui->quadratic->setVisible(false);
        ui->linear->setVisible(false);
        ui->constant->setVisible(true);
        break;


    case 1:
        ui->coeffA->setEnabled(true);
        ui->coeffB->setEnabled(true);
        ui->coeffC->setEnabled(false);
        ui->coeffD->setEnabled(false);
        ui->coeffE->setEnabled(false);
        ui->coeffF->setEnabled(false);

        ui->quintic->setVisible(false);
        ui->quartic->setVisible(false);
        ui->cubic->setVisible(false);
        ui->quadratic->setVisible(false);
        ui->linear->setVisible(true);
        ui->constant->setVisible(false);
        break;

    case 2:
        ui->coeffA->setEnabled(true);
        ui->coeffB->setEnabled(true);
        ui->coeffC->setEnabled(true);
        ui->coeffD->setEnabled(false);
        ui->coeffE->setEnabled(false);
        ui->coeffF->setEnabled(false);

        ui->quintic->setVisible(false);
        ui->quartic->setVisible(false);
        ui->cubic->setVisible(false);
        ui->quadratic->setVisible(true);
        ui->linear->setVisible(false);
        ui->constant->setVisible(false);
        break;

    case 3:
        ui->coeffA->setEnabled(true);
        ui->coeffB->setEnabled(true);
        ui->coeffC->setEnabled(true);
        ui->coeffD->setEnabled(true);
        ui->coeffE->setEnabled(false);
        ui->coeffF->setEnabled(false);

        ui->quintic->setVisible(false);
        ui->quartic->setVisible(false);
        ui->cubic->setVisible(true);
        ui->quadratic->setVisible(false);
        ui->linear->setVisible(false);
        ui->constant->setVisible(false);
        break;

    case 4:
        ui->coeffA->setEnabled(true);
        ui->coeffB->setEnabled(true);
        ui->coeffC->setEnabled(true);
        ui->coeffD->setEnabled(true);
        ui->coeffE->setEnabled(true);
        ui->coeffF->setEnabled(false);

        ui->quintic->setVisible(false);
        ui->quartic->setVisible(true);
        ui->cubic->setVisible(false);
        ui->quadratic->setVisible(false);
        ui->linear->setVisible(false);
        ui->constant->setVisible(false);
        break;

    case 5:
        ui->coeffA->setEnabled(true);
        ui->coeffB->setEnabled(true);
        ui->coeffC->setEnabled(true);
        ui->coeffD->setEnabled(true);
        ui->coeffE->setEnabled(true);
        ui->coeffF->setEnabled(true);

        ui->quintic->setVisible(true);
        ui->quartic->setVisible(false);
        ui->cubic->setVisible(false);
        ui->quadratic->setVisible(false);
        ui->linear->setVisible(false);
        ui->constant->setVisible(false);
        break;
    }
}

userinterface::~userinterface()
{
    delete ui;
}
