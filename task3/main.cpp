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
    tstruct = *localtime(&now);                             //����������� ��� �������� ����� ����� - ���������� ���� � �������

    strftime(buf, sizeof(buf), "%Y-%m-%dT%X", &tstruct);

    return buf;
}


int main(int argc, char* argv[])
{
    setlocale(0,"Russian");
    string path,str,lb,rb;
    int vol, success;
    float sucvoln =0,failvoln=0, attn=0, fattn=0;   //��������� ��� ������ � �������
    float sucvolz=0,failvolz=0,attz=0, fattz=0;
    float rn,rz;
    cout << "������� ���� � �����" << endl;
    cin >> path;
    cout << "������� ������ ������� ����� ����������" <<endl;
    cin >> lb;
    cout << "������� ����� ������� ����� ����������" <<endl;
    cin >> rb;
    ifstream txt(path);
    fstream fout;
    if (txt.is_open())
        {
            cout << "���� ������ \n" << endl;
           for (int i = 0; !txt.eof() ; i++)        //���� ������ ������ �� ���� � ������� ������ ������
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

    rn = fattn/attn*100;        // ������� ������� ��������
    rz = fattz/attz*100;
        }
    else
        {
            cout << "���� �� ������ \n"<< endl;
        }
    txt.close();
    fout.open ("task3.csv", ios::app);                                  //���������� ������ � .csv
    fout << "���������� ������� ������ ����= " << attn << ","
    << "���������� ���������� ������� ������ ���� = " << rn << "%,"
    << " ���������� ������� ���� = " << sucvoln << ","
    << "���������� ��������� ���� = " << failvoln << ","
    << "���������� ������� ������ ����= " << attz << ","
    << "���������� ���������� ������� ������ ���� = " << rz << "%,"
    << " ���������� ������� ���� = " << sucvolz << ","
    << "���������� ��������� ���� = " << failvolz << "\n";


    return 0;
}
