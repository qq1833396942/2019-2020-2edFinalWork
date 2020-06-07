#ifndef MAINFUNCTION_H
#define MAINFUNCTION_H
#include "rkctrl.h"
#include "hkctrl.h"
#include "rinctrl.h"
#include "glctrl.h"
#include <QDialog>

namespace Ui {
class MainFunction;
}

class MainFunction : public QDialog
{
    Q_OBJECT

public:
    explicit MainFunction(QWidget *parent = nullptr);
    ~MainFunction();
    void search();

private slots:
    void on_search_clicked();

    void on_HK_clicked();

    void on_RK_clicked();

    void on_RIN_clicked();

    void on_GL_clicked();

private:
    Ui::MainFunction *ui;
    RKctrl rkctrl;
    HKctrl hkctrl;
    GLctrl glctrl;
    RINctrl rinctrl;
};

#endif // MAINFUNCTION_H
