#ifndef ICALCULATORIOHANDLER_H
#define ICALCULATORIOHANDLER_H

#include "calculator.h"

class ICalculatorIOHandler
{
public:
    ~ICalculatorIOHandler() {}
    void virtual handle_caluclation_started(const CalculationStarted& ev) = 0;
    void virtual handle_caluclation_finished(const CalculationFinished& ev) = 0;
    void virtual handle_caluclation_failed(const CalculationFailed& ev) = 0;
};

#endif // ICALCULATORIOHANDLER_H
