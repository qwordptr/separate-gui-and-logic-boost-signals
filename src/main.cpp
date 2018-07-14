#include <iostream>
#include <QApplication>
#include <boost/signals2/signal.hpp>
#include <algorithm>
#include <memory>
#include "headers/calculator.h"
#include "headers/consoleview.h"
#include "headers/iapplicationflowcontroller.h"
#include "headers/guicalcview.h"

int main(int argc, char *argv[])
{
    int choice;
    std::cout << "1. Terminal." << std::endl;
    std::cout << "2. Graficzny interfejs." << std::endl;
    std::cout << "Wybor: ";
    std::cin >> choice;

    auto calc = std::make_shared<Calculator>();

    std::system("clear");

    if (choice == 1) {
        auto cAppController = std::make_unique<ConsoleView>(calc);
        cAppController->run();
    } else {
       QApplication a(argc, argv);
       auto cAppController = std::make_unique<GuiCalcView>(calc);
       cAppController->run();
       a.exec();
    }

    return 0;
}
