
#include <iostream>

using namespace std;
void LargeCalc(char* num, int bytes)
{
    cout << "Big-Endian:";
    for (int i = bytes - 1; i >= 0; i--) //Считаем по количеству байтов
    {
        for (int k = 0; k < 8; k++)
        {
            cout << ((*(num + i) >> (7 - k)) & 1);
        }
    }
    cout << endl;
}
void MiniCalc(char* num, int bytes)
{
    cout << "Little-Endian:";
    for (int i = 0; i < bytes; i++) //Считаем по количеству байтов
    {
        for (int k = 0; k < 8; k++)
        {
            cout << ((*(num + i) >> (7 - k)) & 1);
        }
    }
    cout << endl;
}
int main()
{
    //Ввод числа
    cout << "Input your number: ";
    double num;

    //Считывание числа
    cin >> num;

    //Конвертация числа
    int numInt = (int)num;
    int numInt2 = (int)num;
    float numFloat = (float)num;
    float numFloat2 = (float)num;

    //Вывод числа в разных типах данных
    cout << "int:" << endl;
    LargeCalc((char*)&numInt, 4);
    MiniCalc((char*)&numInt2, 4);
    cout << "float:" << endl;
    LargeCalc((char*)&numFloat, 4);
    MiniCalc((char*)&numFloat2, 4);
    cout << "double:" << endl;
    LargeCalc((char*)&num, 8);
    MiniCalc((char*)&num, 8);
}
