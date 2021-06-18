#include <iostream>
#include <cmath>
#include <string>
#include <locale.h>

using namespace std;

string itoBase(unsigned int nb, string base)                // перевод числа из 10-тичной в нужную
    {
        int j=0 ,sbase = base.length();
        string answer;
        char t;

        while (nb != 0)
        {
          j = nb % sbase;
          t = base[j];
          answer.insert(0,1,t);
          nb = nb / sbase;
        }
        cout << "new number=" << answer << endl;
        return 0;
    }

string itoBase(string nb, string baseSrc, string baseDst)   // перевод числа в 10-тичную систему и вызов функции на перевод из 10-тичной в нужную
    {
        unsigned int num =0;
        for (int i=0; i<nb.length(); i++)
        {

            num += (nb[i]-48)* (pow(baseSrc.length(),nb.length()-i-1));


        }
        itoBase(num,baseDst);
        return 0;
    }

int main()
{
    setlocale(0,"Russian");
    string enter, number, base, tobase;
    unsigned int nb,j = 0;
    cout << "Введите число и систему счисления,число и системы счисления необходимо разделять ';'." << endl
    << "Если вы хотите перевести десятичное число, то укажите число и систему в которую  необходимо переводить."<<endl
    << "Если вы хотите перевести из другой системы счисления в другую, то укажите сначала число, потом система счисления из которой переводить число в которую систему счисления." << endl;
    cin >> enter;
    for (int i = 0; i < enter.length();i++)
        {
            if (enter[i]!= ';'){
               switch(j){
                case 0:
                    number.push_back(enter[i]);
                    break;
                case 1:
                    base.push_back(enter[i]);       //проверки на корректный ввод данных
                    break;
                case 2:
                    tobase.push_back(enter[i]);
                    break;
               }
               }
               else {j++;}

        }
        switch (j)
            {
                case 1:{
                    string testn(10, ' ');
                    for (int i = 0; i < 10 ; i++){testn[i] = i+48;};
                    cout << testn << " number lenght" << number.length() << endl;       //если ';' одна, то мы переводим 10-тичное число в другую систему
                    int count =0;
                    for (int i = 0; i < number.length() ; i++)
                    {
                        for (int k = 0; k < testn.length(); k++)
                        {

                            if(number[i] == testn[k]) {count++;}
                        }

                    }
                    if (count != number.length()) {cout << "Ошибка при вводе числа или системы счисления"<<endl; break;};
                    nb = stoi (number);
                    itoBase(nb,base);
                    break;
                }
                case 2:{                                                //Если мы переводим число из системы в систему, то там будет 2 ';'
                    int count = 0;
                    for (int i = 0; i <number.length() ; i++)
                    {
                        for (int k = 0; k < base.length(); k++)
                        {

                            if(number[i] == base[k]) {count++;}
                        }

                    }
                    if (count != number.length()) {cout << "Ошибка при вводе числа или систем счисления"<<endl; break;};
                    itoBase(number,base,tobase);
                    break;
                }
                default: {cout << "Ошибка что-то пошло не так";}    // если ';' неправильное количество

            }


    return 0;
}
