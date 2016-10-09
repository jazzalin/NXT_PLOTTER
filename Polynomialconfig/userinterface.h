//James Azzalini (c) - userinterface class declaration
#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QDialog>
#include <QTextStream>
#include <QFile>

namespace Ui {
class userinterface;
}

class userinterface : public QDialog
{
    Q_OBJECT

public:
    explicit userinterface(QWidget *parent = 0);
    ~userinterface();

private slots:
    void plot();
    void enableButton(int value);

private:
    Ui::userinterface *ui;
};

#endif // USERINTERFACE_H
