#include "mainwindow.h"
#include "ui_mainwindow.h"

Region::Region(int year, QString region,double npg,double birth_rate,double death_rate,double gdw, double urbanization){
    _year = year;
    _region = region;
    _npg = npg;
    _birth_rate = birth_rate;
    _death_rate = death_rate;
    _gdw = gdw;
    _urbanization = urbanization;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Vibor1.lis = new QList<Region>;
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete Vibor1.lis;
    delete ui;
    free(Vibor1.rez);
}


void MainWindow::on_Btn_file_clicked()
{
    QString file_path;
    ui->table_region->setRowCount(0);
    Vibor1.lis->clear();
    if (ui->line_region->text() != ""){
        if (ui->line_path->text()=="")
            file_path = QFileDialog::getOpenFileName(this,tr("Открыть файл"),"C://","all files(*.*);;text file(*.txt);;table file(*.csv)");
        else
            file_path = ui->line_path->text();
        QMessageBox::information(this,tr("информация"),file_path);
        Vibor1.file_path = file_path;
        Vibor1.region=ui->line_region->text();
        Vibor1.enum_variant = Enter::Reaed_ffile;
        enter(&Vibor1);
        (Vibor1.check == -1) ? QMessageBox::critical(this, "информация","не удалось открыть файл"):QMessageBox::information(this, "информация","удалось открыть файл");
        (Create_table(Vibor1.lis) == -1) ? QMessageBox::critical(this, "информация", "не удалось создать таблицу"): QMessageBox::information(this, "информация","удалось создать таблицу");
    }else
        QMessageBox::critical(this, "информация","не введён регион");
}

void MainWindow::on_Btn_stolb_clicked()
{
    ui->label_rez->setText("");
    QString stolb=ui->line_stolb->text();
    int stolbb;
    if (stolb.toInt(/*0,10*/)==3 || stolb.toInt(/*0,10*/)==4 || stolb.toInt(/*0,10*/)==5 || stolb.toInt(/*0,10*/)==6 || stolb.toInt(/*0,10*/)==7){
        Vibor1.rez = (double*)calloc(sizeof(double),3);
        Vibor1.stolb=ui->line_stolb->text();
        Vibor1.enum_variant = Enter::Sortt;
        enter(&Vibor1);
        ui->label_rez->setText(QString("min: ") + QString::number(Vibor1.rez[0])+
            QString(" max: ") + QString::number(Vibor1.rez[1])+
            QString(" mediana: ") + QString::number(Vibor1.rez[2])
            );
            DrawRez();
    }else
        QMessageBox::critical(this, "информация","не верный столбец");
}




