#include <iostream>
#include <cmath>
#include <string>
#include <locale.h>

using namespace std;

string itoBase(unsigned int nb, string base)                // ������� ����� �� 10-������ � ������
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

string itoBase(string nb, string baseSrc, string baseDst)   // ������� ����� � 10-������ ������� � ����� ������� �� ������� �� 10-������ � ������
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
    cout << "������� ����� � ������� ���������,����� � ������� ��������� ���������� ��������� ';'." << endl
    << "���� �� ������ ��������� ���������� �����, �� ������� ����� � ������� � �������  ���������� ����������."<<endl
    << "���� �� ������ ��������� �� ������ ������� ��������� � ������, �� ������� ������� �����, ����� ������� ��������� �� ������� ���������� ����� � ������� ������� ���������." << endl;
    cin >> enter;
    for (int i = 0; i < enter.length();i++)
        {
            if (enter[i]!= ';'){
               switch(j){
                case 0:
                    number.push_back(enter[i]);
                    break;
                case 1:
                    base.push_back(enter[i]);       //�������� �� ���������� ���� ������
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
                    cout << testn << " number lenght" << number.length() << endl;       //���� ';' ����, �� �� ��������� 10-������ ����� � ������ �������
                    int count =0;
                    for (int i = 0; i < number.length() ; i++)
                    {
                        for (int k = 0; k < testn.length(); k++)
                        {

                            if(number[i] == testn[k]) {count++;}
                        }

                    }
                    if (count != number.length()) {cout << "������ ��� ����� ����� ��� ������� ���������"<<endl; break;};
                    nb = stoi (number);
                    itoBase(nb,base);
                    break;
                }
                case 2:{                                                //���� �� ��������� ����� �� ������� � �������, �� ��� ����� 2 ';'
                    int count = 0;
                    for (int i = 0; i <number.length() ; i++)
                    {
                        for (int k = 0; k < base.length(); k++)
                        {

                            if(number[i] == base[k]) {count++;}
                        }

                    }
                    if (count != number.length()) {cout << "������ ��� ����� ����� ��� ������ ���������"<<endl; break;};
                    itoBase(number,base,tobase);
                    break;
                }
                default: {cout << "������ ���-�� ����� �� ���";}    // ���� ';' ������������ ����������

            }


    return 0;
}
