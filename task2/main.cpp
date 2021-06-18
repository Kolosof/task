#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <locale.h>

using namespace std;
struct point
{
    float x,y,z;
};
point circle, pointer1, pointer2;
float rad, A, B, C, D;

 /* int parcer (string txt, float answer, ifstream file, string rx)
{
  int pos = 0;
    smatch result;
    file >> txt;
    regex_search(txt, result, rx);
    cout << result[0] << endl;                     // Я не понял почему он не желает принемать smatch в regex_search
    txt = result[0];
    cout << txt << endl;
    pos = txt.find ('.');
    if (pos !=0) {txt.replace(pos,1,",");};
    cout << txt << endl;
    answer = stof(result[0]);
    cout << answer << endl;
    return 1;

} */

int main()
{
    setlocale(0,"Russian");
    string txt, path;
    cout << "Введите путь к файлу" << endl;  //ручной ввод пути к файлу для считывания данных
    cin >> path;
    ifstream file (path);
    regex rx ("[-]?""[0-9]+""([\\.]?)""([0-9])*");
    smatch result;
    int pos = 0;

    if (file.is_open())
        {
            cout << "Файл открыт \n\n" << endl;
        }
    else
        {
            cout << "Файл не открыт \n\n" << endl;
        }

           for (file >> txt; !file.eof(); file >> txt) // считываем данные и ищем ключевые слова, если находим, то при помощи парсера regex очищаем цифры от прочих символов
            {                                          // и меняем '.' на ',' для конвертирование цифры в float
             cout << txt << endl;
             if (txt == "{center:")
                {
                file >> txt;
                regex_search(txt, result, rx);                              // зато тут и далее прекрасно работает
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,","); pos = 0;};
                circle.x = stof(txt);
                cout << circle.x << endl;
                file >> txt;
                regex_search(txt, result, rx);
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,","); pos = 0;};
                circle.y = stof(txt);
                cout << circle.y << endl;
                file >> txt;
                regex_search(txt, result, rx);
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,","); pos = 0;};
                circle.z = stof(txt);
                cout << circle.z << endl;
                }
              if (txt == "radius:")
              {
                file >> txt;
                regex_search(txt, result, rx);
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,","); pos = 0;};
                rad = stof(txt);
                cout << rad << endl;
              }
              if (txt == "line:")
              {
                file >> txt;
                regex_search(txt, result, rx);
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,","); pos = 0;};
                pointer1.x = stof(txt);
                cout << pointer1.x << endl;
                file >> txt;
                regex_search(txt, result, rx);
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,","); pos = 0;};
                pointer1.y = stof(txt);
                cout << pointer1.y << endl;
                file >> txt;
                regex_search(txt, result, rx);
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,",");pos = 0;};
                pointer1.z = stof(txt);
                cout << pointer1.z << endl;
                file >> txt;
                regex_search(txt, result, rx);
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,",");pos = 0;};
                pointer2.x = stof(txt);
                cout << pointer2.x << endl;
                file >> txt;
                regex_search(txt, result, rx);
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,","); pos = 0;};
                pointer2.y = stof(txt);
                cout << pointer2.y << endl;
                file >> txt;
                regex_search(txt, result, rx);
                txt = result[0];
                pos = txt.find ('.');
                if (pos >0) {txt.replace(pos,1,","); pos = 0;};
                pointer2.z = stof(txt);
                cout << pointer2.z << endl;
              }
            }
    cout << "circle center = "  << circle.x << " " << circle.y << " " << circle.z << " " << endl;
    cout << "circle radius = "  << rad << endl;
    cout << " line 1 point = "  << pointer1.x << " " << pointer1.y << " " << pointer1.z << " " << endl;
    cout << " line 2 point = "  << pointer2.x << " " << pointer2.y << " " << pointer2.z << " " << endl;

    float vx = pointer2.x - pointer1.x, vy = pointer2.y - pointer1.y, vz= pointer2.z - pointer1.z;  // решаем систему уровнений чтобы проверить количество пересечений
    float px = pointer1.x, py = pointer1.y, pz = pointer1.z;
    float cx = circle.x, cy = circle.y, cz = circle.z;

    A = vx * vx + vy * vy + vz * vz;
    B = 2 *(px * vx + py * vy + pz * vz - vx * cx - vy * cy - vz * cz);
    C = px * px - 2 * px * cx + cx * cx + py * py - 2 * py * cy + cy * cy + pz * pz - 2 * pz * cz + cz * cz - rad * rad;
    D = B * B - 4 * A * C;
    if (D < 0){cout << "коллизий нет";}     //ищем координаты пересечений с окружностью
    if (D == 0)
    {
    float t1 = (-B - D*D) / (2*A);
    float t1x = pointer1.x *(1-t1) + t1 *pointer2.x;
    float t1y = pointer1.y *(1-t1) + t1 *pointer2.y;
    float t1z = pointer1.z *(1-t1) + t1 *pointer2.z;
    cout << "Первое пересечение Х = " <<t1x <<" Y = " << t1y << " Z = " << t1z << endl;
    }
    if (D > 0)
    {
    float t2 = (-B + D*D) / (2*A);
    float t2x = pointer1.x *(1-t2) + t2 *pointer2.x;
    float t2y = pointer1.y *(1-t2) + t2 *pointer2.y;
    float t2z = pointer1.z *(1-t2) + t2 *pointer2.z;
    cout << "Второе пересечение Х = " <<t2x <<" Y = " << t2y << " Z = " << t2z << endl;
    }

    return 0;
}
