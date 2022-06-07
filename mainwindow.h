#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QDebug>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>

#include <string>
#include <fstream>
#include <string>

#include "variant.h"
#include "Region.h"
#include "Reade_file.h"
#include "Sort.h"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Btn_file_clicked();

    void on_Btn_stolb_clicked();


private:
    QList<double> sort_list;
    Ui::MainWindow *ui;
    Vibor Vibor1;
    void DrawGrid(QPainter *paint,double shag);
    void DrawGraf(QPainter *paint,double shag);
    void DrawRez();
    void DrawInscription(QPainter *paint,double shag);
    void drawValue(QPainter *paint,double shag);
    int Create_table(QList<Region>* list);
};
#endif // MAINWINDOW_H
