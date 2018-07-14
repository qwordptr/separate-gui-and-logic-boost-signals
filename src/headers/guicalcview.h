#ifndef GUICALCVIEW_H
#define GUICALCVIEW_H

#include <QMainWindow>
#include "iapplicationflowcontroller.h"
#include "icalculatoriohandler.h"
#include "calculator.h"

namespace Ui {
class GuiCalcView;
}

class GuiCalcView : public QMainWindow, public ICalculatorIOHandler, public IApplicationFlowController
{
    Q_OBJECT

private:
    std::shared_ptr<Calculator> _calc;
    Ui::GuiCalcView *ui;

public:
    GuiCalcView(QWidget *parent = 0);
    GuiCalcView(std::shared_ptr<Calculator> calc = 0, QWidget *parent = 0);
    ~GuiCalcView();

    void virtual handle_caluclation_started(const CalculationStarted& ev);
    void virtual handle_caluclation_finished(const CalculationFinished& ev);
    void virtual handle_caluclation_failed(const CalculationFailed& ev);
    void run() override;

private slots:
    void on_executeButton_clicked();
    void on_exitButton_clicked();
};

#endif // GUICALCVIEW_H
