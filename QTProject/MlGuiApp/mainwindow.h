#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <multipoint.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <QtCharts>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

	/*! @brief Объявление переменных с дальнейшей их реализацией в mainwindow.cpp
	Объявление m_chart'a, реализация в .cpp файле
	Объявление m_maxLineEdit'a, реализация в .cpp файле
	Объявление m_datafromLineEdit'a, реализация в .cpp файле
	Объявление m_datatoLineEdit'a, реализация в .cpp файле
	*/
    QChart* m_chart; 
    QLineEdit* m_minLineEdit; 
    QLineEdit* m_maxLineEdit; 
    QLineEdit* m_datafromLineEdit;
    QLineEdit* m_datatoLineEdit;
    std::vector<MultiPoint> m_data;
    void drawInputData(const std::vector<MultiPoint>& data);
	
private slots:
    void generateDataPushButtonSlot();
    void drawPlotPushButtonSlot();
};
#endif // MAINWINDOW_H
