#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include "calculator.h"
#include <functional>
#include <boost/signals2.hpp>
#include <algorithm>
#include <iostream>

BOOST_AUTO_TEST_CASE( testCalculatorAdd )
{
   auto calc = std::make_unique<Calculator>();
   double outcomeCallback = 0;

   double x = 5;
   double y = 10;
   double expectedOutcome = x + y;

   auto lambda = [&outcomeCallback](const CalculationFinished& x){ outcomeCallback =  std::stod(x.outcome); };

   calc->onCalculated.connect(lambda);
   calc->add(x, y);

  BOOST_CHECK(outcomeCallback == expectedOutcome);
}

BOOST_AUTO_TEST_CASE( testCalculatorSub )
{
   auto calc = std::make_unique<Calculator>();
   double outcomeCallback = 0;

   double x = 5;
   double y = 10;
   double expectedOutcome = x - y;

   auto lambda = [&outcomeCallback](const CalculationFinished& x){ outcomeCallback =  std::stod(x.outcome); };

   calc->onCalculated.connect(lambda);
   calc->sub(x, y);

  BOOST_CHECK(outcomeCallback == expectedOutcome);
}

BOOST_AUTO_TEST_CASE( testCalculatorMul )
{
   auto calc = std::make_unique<Calculator>();
   double outcomeCallback = 0;

   double x = 5;
   double y = 10;
   double expectedOutcome = x * y;

   auto lambda = [&outcomeCallback](const CalculationFinished& x){ outcomeCallback =  std::stod(x.outcome); };

   calc->onCalculated.connect(lambda);
   calc->mul(x, y);

  BOOST_CHECK(outcomeCallback == expectedOutcome);
}

BOOST_AUTO_TEST_CASE( testCalculatorDiv )
{
   auto calc = std::make_unique<Calculator>();
   double outcomeCallback = 0;

   double x = 10;
   double y = 5;
   double expectedOutcome = x / y;

   auto lambda = [&outcomeCallback](const CalculationFinished& x){ outcomeCallback =  std::stod(x.outcome); };

   calc->onCalculated.connect(lambda);
   calc->div(x, y);

  BOOST_CHECK(outcomeCallback == expectedOutcome);
}

BOOST_AUTO_TEST_CASE( testCalculatorDivByZero )
{
   auto calc = std::make_unique<Calculator>();
   double outcomeCallback = 0;
   std::string expectedMessage = "Cannot divide by zero.";
   std::string failedMessage = "";

   auto lambdaOutcome = [&outcomeCallback](const CalculationFinished& x){ outcomeCallback =  std::stod(x.outcome); };
   auto lambdaFailed =  [&failedMessage](const CalculationFailed& x) { failedMessage = x.message;};

   calc->onCalculated.connect(lambdaOutcome);
   calc->onError.connect(lambdaFailed);
   calc->div(10, 0);

  BOOST_CHECK(outcomeCallback == outcomeCallback);
  BOOST_CHECK(failedMessage == expectedMessage);
}

