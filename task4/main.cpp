#include <iostream>
#include <string>
#include <locale.h>

using namespace std;

string ST1, ST2;

int main()
{
    setlocale(0,"Russian");
    cout << "������� 1 �����" << endl;
    cin >> ST1;
    cout << "������� 2 �����" << endl;
    cin >> ST2;
    int correct = 0, score =0,i1 =0, i2 =0;
    for (int i = 0; i < ST1.length(); i++)
    {
        if (ST1[i1] == ST2[i2] && ST1[i1] != NULL){correct++; i1++; i2++;} // ��������� ������������������ ��������, ���������� ������ �������� ����� ������� �� ����� ��������� * � 2 �����
        else
        {
            if (ST2[i2] == '*' && i2 != ST2.length()-1)
            {
                int j = i2;
            while (ST2[j] == '*')
                {
                    j++;
                    if (ST2[j]!= '*')
                    {
                       for (int k = ST1.length(); k > i1 ; k--)
                        {
                            if (ST1[k] == ST2[j] && ST2.length()-j<=ST1.length()-k)                         // ���� ������ * �� ���������, �� ������� ������� ������� � ����� �����, ����� �������� ������� 2 �����
                            {
                                    correct += ST1.length()-i1;
                                    i1 = ST1.length()-k;
                                    i2 = ST2.length()-j;
                                    k -= ST1.length();


                            }

                        }

                    }
                    else {i2++;} // ������� ���������� *


                }
            }
            else if (ST2[i2] == '*' && i2 == ST2.length()-1) {correct += ST1.length()-correct;} // ���� * ��������� ������ � 2 �����, �� ��������� ������� ����������� ��������, ������� ���������� � 1 �����

        };
    }
    if (correct == ST1.length()) {cout << "��";}
    else {cout << "��";}
    return 0;
}
