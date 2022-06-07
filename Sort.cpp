#include "Sort.h"

void Sort(Vibor* Vibor1)
{
    vector<double> sort_list;
    for(int i=0;i<Vibor1->lis->size();i++){
        if (Vibor1->stolb.toStdString()=="3")
            sort_list.push_back(Vibor1->lis->at(i)._npg);
        else if (Vibor1->stolb.toStdString()=="4")
            sort_list.push_back(Vibor1->lis->at(i)._birth_rate);
        else if (Vibor1->stolb.toStdString()=="5")
            sort_list.push_back(Vibor1->lis->at(i)._death_rate);
        else if (Vibor1->stolb.toStdString()=="6")
            sort_list.push_back(Vibor1->lis->at(i)._gdw);
        else if (Vibor1->stolb.toStdString()=="7")
            sort_list.push_back(Vibor1->lis->at(i)._urbanization);
        else
            qDebug("введён не правильный столбец");
    }
    double median;
    Vibor1->drawList=sort_list;
    sort(sort_list.begin(),sort_list.end());
    double min = sort_list.at(0);
    double max = sort_list.at(sort_list.size()-1);
    if (sort_list.size()%2 == 1)
        median = sort_list.at(sort_list.size()/2);
    else
        median = (sort_list.at(sort_list.size() / 2)+ sort_list.at((sort_list.size() / 2)-1))/2;
    Vibor1->rez[0]=min;
    Vibor1->rez[1]=max;
    Vibor1->rez[2]=median;
}
