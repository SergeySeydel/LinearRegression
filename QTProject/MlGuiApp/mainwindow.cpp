#include "mainwindow.h"//Подключение библиотеки mainwindow.h
#include "ui_mainwindow.h"//Подключение библиотеки ui_mainwindow.h
#include <linearregression.h>//Подключение библиотеки c++, которая работает с прямыми, генерирует рандомные числа
#include <gradientdescent.h>
#include <stochasticgradientdescent.h> //Библиотека c рандомными числами и работа с прямой

#include <QGridLayout> // Класс с сеткой, для работы с
#include <QPushButton> // Класс, который предоставляет кнопку
#include <QtCharts> //Позволяет рисовать линии, диаграммы
#include <QtCharts/QLineSeries> // Позволяет рисовать линии
#include <assert.h>



MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{

    QGroupBox *randomizerSettingsGroupBox = new QGroupBox(tr("Randomizer settings"));
	
    QGridLayout *randomizerSettingsLayout = new QGridLayout();  ///Layout
    randomizerSettingsLayout->addWidget(new QLabel(tr("Min value")), 0, 0); 
    randomizerSettingsLayout->addWidget(new QLabel(tr("Max value")), 1, 0); 
    m_minLineEdit = new QLineEdit(); 
    m_maxLineEdit = new QLineEdit(); 
    randomizerSettingsLayout->addWidget(m_minLineEdit,0, 1);
    randomizerSettingsLayout->addWidget(m_maxLineEdit,1, 1); 
    randomizerSettingsGroupBox->setLayout(randomizerSettingsLayout);


    QGroupBox *generatedDataSettingsGroupBox = new QGroupBox(tr("Generated data settings")); 
    QGridLayout *generatedDataLayout = new QGridLayout(); 
    generatedDataLayout->addWidget(new QLabel(tr("Start")), 0, 0); 
    generatedDataLayout->addWidget(new QLabel(tr("End")), 1, 0); 
    m_datafromLineEdit = new QLineEdit(); //Окно, Text box
    m_datatoLineEdit = new QLineEdit(); //Окно, Text box
    generatedDataLayout->addWidget(m_datafromLineEdit, 0,1);
    generatedDataLayout->addWidget(m_datatoLineEdit, 1, 1);
    generatedDataSettingsGroupBox->setLayout(generatedDataLayout);

	
    QPushButton* generatePointsPushButton = new QPushButton("Generate data", this); 
    connect(generatePointsPushButton, &QPushButton::clicked, this, &MainWindow::generateDataPushButtonSlot); 
    QPushButton* drawPlotPushButton = new QPushButton("Draw plot", this); // Кнопка Draw plot
    connect(drawPlotPushButton, &QPushButton::clicked, this, &MainWindow::drawPlotPushButtonSlot); 
    m_chart = new QChart(); 


    QChartView *chartView = new QChartView(m_chart);

    QGridLayout *mainLayout = new QGridLayout(); ///Установка сетки
    mainLayout->addWidget(chartView, 0, 0, 1, 2); ///Двумя последними параметрами растягиваем 1 окно на два
    mainLayout->addWidget(randomizerSettingsGroupBox, 1, 0); 
    mainLayout->addWidget(generatedDataSettingsGroupBox, 1, 1);
    mainLayout->addWidget(generatePointsPushButton, 2, 0);
    mainLayout->addWidget(drawPlotPushButton, 3, 0);

    QWidget* mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);
    resize(800, 600);


}

MainWindow::~MainWindow()
{

}

void MainWindow::generateDataPushButtonSlot() //Слот создания кнопки
{
    RandomGenerator rg; ///Генератор рандомных чисел из библиотеки
    double from = m_datafromLineEdit->text().isEmpty()? 0: m_datafromLineEdit->text().toDouble(); ///Если диапазон чисел не выбран, то по умолчанию выбираем 0
    double to = m_datatoLineEdit->text().isEmpty()? 0: m_datatoLineEdit->text().toDouble();
    qDebug() << from; ///QDebug, который использовал для отладки
    double step = 0.2; /// В планах доделать шаг, с которым шагает цикл
    for (double i = from; i < to;i+=step)
    {
        m_data.push_back(MultiPoint(2.4 + 1.3 * i + rg.generateRandomInRange(-7.0, 7.0),
                                    { static_cast<double>(i)}));
    }

    drawInputData(m_data);
}

void MainWindow::drawInputData(const std::vector<MultiPoint>& data)
{
    QScatterSeries *series = new QScatterSeries();
    series->setName("scatter1");
    series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(10.0);

    for (const auto& point: data)
    {
        series->append(point.getXs()[0], point.getY());
    }

    m_chart->addSeries(series);

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, 100);
    axisX->setTickCount(10);
    axisX->setLabelFormat("%.2f");
    m_chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);


    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 100);
    axisY->setTickCount(10);
    axisY->setLabelFormat("%.2f");
    m_chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}

void MainWindow::drawPlotPushButtonSlot()
{
    LinearRegression<GradientDescent> lr;
    auto th = lr.calculateParameters(m_data, 0.0001);
    QLineSeries *series = new QLineSeries();
    for (const auto& point: m_data)
    {
        auto x = point.getXs()[0];
        auto y = th[0] + th[1]*x;
        series->append(x, y);
    }

    m_chart->addSeries(series);
    series->attachAxis(m_chart->axes()[0]);
    series->attachAxis(m_chart->axes()[1]);


}
