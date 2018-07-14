#include "../headers/guicalcview.h"
#include "ui_guicalcview.h"
#include <map>
#include <functional>

GuiCalcView::GuiCalcView(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::GuiCalcView)
{
    ui->setupUi(this);
}

GuiCalcView::GuiCalcView(std::shared_ptr<Calculator> calc, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiCalcView),
    _calc(calc)
{
    _calc->onStarted.connect(boost::bind(&GuiCalcView::handle_caluclation_started, this, boost::placeholders::_1));
    _calc->onCalculated.connect(boost::bind(&GuiCalcView::handle_caluclation_finished, this, boost::placeholders::_1));
    _calc->onError.connect(boost::bind(&GuiCalcView::handle_caluclation_failed, this, boost::placeholders::_1));

    ui->setupUi(this);
}

void GuiCalcView::run()
{
    this->show();
}

GuiCalcView::~GuiCalcView()
{
    delete ui;
}


void GuiCalcView::handle_caluclation_started(const CalculationStarted &ev)
{
    ui->eventList->addItem(QString("Event: ") + QString(ev.message.c_str()));
}

void GuiCalcView::handle_caluclation_finished(const CalculationFinished &ev)
{
    ui->eventList->addItem(QString("Event: ") + QString("Calculation fished"));
    ui->outcome->setText(QString("Outcome: ") + QString(ev.outcome.c_str()));
}

void GuiCalcView::handle_caluclation_failed(const CalculationFailed &ev)
{
    ui->eventList->addItem(QString("Event: ") + QString(ev.message.c_str()));
}

void GuiCalcView::on_executeButton_clicked()
{
        double a = ui->numberA->text().toDouble();
        double b = ui->numberB->text().toDouble();
        QString operation = ui->operation->text();

        if (operation == "+") {
            _calc->add(a, b);
        } else if (operation == "-") {
            _calc->sub(a, b);
        } else if (operation == "*") {
            _calc->mul(a, b);
        } else if (operation == "/") {
            _calc->div(a, b);
        } else {
            ui->eventList->addItem(QString("Wrong operation!"));
        }
}

void GuiCalcView::on_exitButton_clicked()
{
    exit(0);
}
