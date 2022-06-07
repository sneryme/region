#ifndef REGION_H
#define REGION_H
#include <QString>
#include <QList>
#include <vector>

#pragma once

struct Region{
    int _year;
    QString _region;
    double _npg;
    double _birth_rate;
    double _death_rate;
    double _gdw;
    double _urbanization;
    Region(int year, QString region,double npg,double birth_rate,double death_rate,double gdw, double urbanization);
};

enum Enter{
    Reaed_ffile = 0,
    Sortt
};

struct Vibor{
    QString stolb;
    QList<Region>* lis;
    double* rez;
    QString file_path;
    QString region;
    QString Region;
    std::vector<double> drawList;
    int8_t check;

    Enter enum_variant;
};

#endif // REGION_H
