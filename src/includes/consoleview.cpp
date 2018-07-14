#include "../headers/consoleview.h"
#include <iostream>
#include <thread>
#include <chrono>
#include<vector>
#include <string>

void ConsoleView::printHello()
{
    using namespace std::chrono_literals;

    std::vector<std::string> lines;
    lines.push_back("############################################################");
    lines.push_back("#                                                          #");
    lines.push_back("#            * *       **       *             * *          #");
    lines.push_back("#          *          *  *      *           *              #");
    lines.push_back("#          *         *    *     *           *              #");
    lines.push_back("#          *         * ** *     *           *              #");
    lines.push_back("#            * *     *    *     * * * *       * *          #");
    lines.push_back("#                                                          #");
    lines.push_back("#                                                          #");
    lines.push_back("############################################################");

    for(auto line : lines)
    {
        std::cout << line << std::endl;
        std::this_thread::sleep_for(200ms);
    }
}

void ConsoleView::run()
{
    while(true)
    {
        int option;

        std::cout << "1. Dodaj" << std::endl;
        std::cout << "2. Odejmij" << std::endl;
        std::cout << "3. Pomnoz" << std::endl;
        std::cout << "4. Podziel " << std::endl;
        std::cout << "5. Wyjscie " << std::endl;
        std::cout << "Wybor: ";
        std::cin >> option;
        std::cout << "-------------------------" << std::endl;

        if (option == 5) {
            exit(0);
        }

        double a;
        double b;

        std::cout << "Podaj a: ";
        std::cin >> a;
        std::cout << "Podaj b:";
        std::cin >> b;

        switch (option) {
        case 1:
            _calc->add(a, b);
            break;
        case 2:
            _calc->sub(a, b);
            break;
        case 3:
            _calc->mul(a, b);
            break;
        case 4:
            _calc->div(a, b);
            break;
        }

    }
}

void ConsoleView::handle_caluclation_started(const CalculationStarted &ev)
{
    std::cout << "Calculation started: " << ev.message << std::endl;
}

void ConsoleView::handle_caluclation_finished(const CalculationFinished &ev)
{
    std::cout << "Calculation finished: " << ev.outcome << std::endl;
}

void ConsoleView::handle_caluclation_failed(const CalculationFailed &ev)
{
    std::cout << "Error! Message: " << ev.message << std::endl;
}
