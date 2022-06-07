#include "Reade_file.h"

int Read_file(Vibor* Vibor1){
    fstream file;
    file.open(Vibor1->file_path.toStdString());
    if (file.is_open()){
            string str, str_shapka;
            getline(file, str_shapka, '\n');
            string inregion;
            while (getline(file, str, '\n')) {
                stringstream inputt(str);
                string mas[7];
                int i = 0, j=0;
                while (getline(inputt, mas[i], ','))
                    i++;
                if (mas[0] != "" && mas[2] != "" && mas[3] != "" && mas[4] != "" && mas[5] != "" && mas[6] != "" && mas[1] == Vibor1->region.toStdString()){
                    Vibor1->lis->append({stoi(mas[0]),QString::fromStdString(mas[1]),stod(mas[2]),stod(mas[3]),stod(mas[4]),stod(mas[5]),stod(mas[6])});
                    j++;
                }
            }
        }else
          return -1;
    file.close();
    return 0;
}
