#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <boost/signals2/signal.hpp>
#include <string>

typedef struct {
    std::string message;
} CalculationStarted;

typedef struct {
    std::string message;
} CalculationFailed;

typedef struct {
    std::string outcome;
} CalculationFinished;

class Calculator
{
public:
    Calculator() = default;

    void add(double a, double b);
    void sub(double a, double b);
    void mul(double a, double b);
    void div(double a, double b);

    boost::signals2::signal<void (const CalculationStarted&)> onStarted;
    boost::signals2::signal<void (const CalculationFailed&)> onError;
    boost::signals2::signal<void (const CalculationFinished&)> onCalculated;


};

#endif // CALCULATOR_H
