#include <iostream>
#include <locale>
#include <time.h>
#include <regex>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);                             //использовал для создания файла логов - записывает дату в функцию

    strftime(buf, sizeof(buf), "%Y-%m-%dT%X", &tstruct);

    return buf;
}


int main(int argc, char* argv[])
{
    setlocale(0,"Russian");
    string path,str,lb,rb;
    int vol, success;
    float sucvoln =0,failvoln=0, attn=0, fattn=0;   //параметры для вывода в таблицу
    float sucvolz=0,failvolz=0,attz=0, fattz=0;
    float rn,rz;
    cout << "Введите путь к файлу" << endl;
    cin >> path;
    cout << "Введите начало периода сбора статистики" <<endl;
    cin >> lb;
    cout << "Введите конец периода сбора статистики" <<endl;
    cin >> rb;
    ifstream txt(path);
    fstream fout;
    if (txt.is_open())
        {
            cout << "Файл открыт \n" << endl;
           for (int i = 0; !txt.eof() ; i++)        //ищем нужные записи по дате и считаем нужные данные
           {
               txt >> str;
               if(lb < str && str < rb)
                {
                    txt >> str;
                    vol = stoi(str);
                    txt >> str;
                    success = stoi(str);
                    if (vol > 0)
                    {
                        if (success > 0) {attn++; sucvoln +=vol;}
                        else {attn++; failvoln += vol; fattn++;}
                    }
                    if (vol < 0)
                    {
                        if (success > 0) {attz++; sucvolz +=vol;}
                        else {attz++; failvolz += vol; fattz++;}
                    }

                }

           }

    rn = fattn/attn*100;        // считаем процент провалов
    rz = fattz/attz*100;
        }
    else
        {
            cout << "Файл не открыт \n"<< endl;
        }
    txt.close();
    fout.open ("task3.csv", ios::app);                                  //записываем данные в .csv
    fout << "Количество попыток налить воду= " << attn << ","
    << "Количество провальных попыток налить воду = " << rn << "%,"
    << " Количество налитой воды = " << sucvoln << ","
    << "Количество неналитой воды = " << failvoln << ","
    << "Количество попыток вылить воду= " << attz << ","
    << "Количество провальных попыток вылить воду = " << rz << "%,"
    << " Количество вылитой воды = " << sucvolz << ","
    << "Количество невылитой воды = " << failvolz << "\n";


    return 0;
}
