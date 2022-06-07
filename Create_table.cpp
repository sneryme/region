#include "ui_mainwindow.h"
#include "mainwindow.h"


int MainWindow::Create_table(QList<Region>* list){
    ui->table_region->setRowCount(list->count());
    ui->table_region->setColumnCount(7);
    ui->table_region->setHorizontalHeaderLabels(QStringList()<<"Year"<<"Region"<<"Npg"<<"Birth_rate"<<"Death_rate"<<"Gdw"<<"Urbanization");
    if (list->count() == 0)
        return -1;
    for (int i = 0; i < list->count(); i++){
        for(int j = 0; j < 7; j++){
            switch (j) {
            case 0:
                ui->table_region->setItem(i, j, new QTableWidgetItem(QString::number(list->at(i)._year)));
                break;
            case 1:
                ui->table_region->setItem(i, j, new QTableWidgetItem(list->at(i)._region));
                break;
            case 2:
                ui->table_region->setItem(i, j, new QTableWidgetItem(QString::number(list->at(i)._npg)));
               break;
            case 3:
                ui->table_region->setItem(i, j, new QTableWidgetItem(QString::number(list->at(i)._birth_rate)));
               break;
            case 4:
                ui->table_region->setItem(i, j, new QTableWidgetItem(QString::number(list->at(i)._death_rate)));
               break;
            case 5:
                ui->table_region->setItem(i, j, new QTableWidgetItem(QString::number(list->at(i)._gdw)));
               break;
            case 6:
                ui->table_region->setItem(i, j, new QTableWidgetItem(QString::number(list->at(i)._urbanization)));
               break;
            default:
                break;
            }
        }
    }
    return 0;
}

