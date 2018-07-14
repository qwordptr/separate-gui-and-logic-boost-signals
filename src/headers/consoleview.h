#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include <memory>
#include "calculator.h"
#include "iapplicationflowcontroller.h"
#include "icalculatoriohandler.h"

class ConsoleView : public ICalculatorIOHandler, IApplicationFlowController
{
private:
    std::shared_ptr<Calculator> _calc;

    void printHello();
public:
    ConsoleView(std::shared_ptr<Calculator> calc)
        :_calc(calc)
    {
        this->printHello();
        _calc->onStarted.connect(boost::bind(&ConsoleView::handle_caluclation_started, this, boost::placeholders::_1));
        _calc->onCalculated.connect(boost::bind(&ConsoleView::handle_caluclation_finished, this, boost::placeholders::_1));
        _calc->onError.connect(boost::bind(&ConsoleView::handle_caluclation_failed, this, boost::placeholders::_1));
    }
    ~ConsoleView() {}

    void run() override;
    void handle_caluclation_started(const CalculationStarted& ev);
    void handle_caluclation_finished(const CalculationFinished& ev);
    void handle_caluclation_failed(const CalculationFailed& ev);
};

#endif // CONSOLEVIEW_H
