#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> fileCopy;
vector<string> fCopy;
string temp, path = "1.txt";
void readInArr()

{

    fileCopy.clear();
    ifstream fin(path);
    getline(fin, temp);
    while (temp != "")
    {
        fileCopy.push_back(temp);
        getline(fin, temp);
    }
    fin.close();
}
void writeToFile(vector<string> fCopy)
{
    ofstream fout(path);
    for (int i = 0; i < (int)fCopy.size(); i++)
        fout << fCopy[i] << endl;
    fout.close();
}
int main()
{
    setlocale(0, "");
    int N, var;
    string FIO, quantity, weight;
    while (true)
    {
        cout << "Выберите из вариантов:\n(0) Выход\n(1) Создать файл из N записей\n(2) Просмотреть файл\n(3) Добавить в конец файла новую запись\n(4) Удалить записи о пассажирах, общий вес вещей которых меньше 10 килограмм\n(5) Изменить вес по фамилии\n";
        getline(cin, temp);
        var = stoi(temp);
        if (var == 0)
        {
            return 0;
        }
        else if (var == 1)
        {
            cout << "Введите количество записей:\n";
            getline(cin, temp);
            N = stoi(temp);
            ofstream fout(path);
            for (int i = 0; i < N; i++)
            {
                cout << "Введите " << i + 1 << "ую запись:\n";
                getline(cin, temp);
                fout << temp << endl;
            }
            fout.close();
        }
        else if (var == 2)
        {
            ifstream fin(path);
            getline(fin, temp);
            while (temp != "")
            {
                cout << temp << endl;
                getline(fin, temp);
            }
        }
        else if (var == 3)
        {
            readInArr();
            cout << "Введите запись, которую хотите добавить в конец:\n";
            getline(cin, temp);
            fileCopy.push_back(temp);
            writeToFile(fileCopy);
        }
        else if (var == 4)
        {
            fCopy.clear();
            readInArr();
            for (auto a : fileCopy)
            {
                weight = a.substr(a.rfind(',') + 2, a.length() - a.rfind(',') - 1);
                if (stoi(weight) >= 10)
                    fCopy.push_back(a);
            }
            writeToFile(fCopy);
        }
        else if (var == 5)
        {
            readInArr();
            cout << "Введите фамилию:\n";
            getline(cin, temp);
            cout << "Введите вес:\n";
            getline(cin, weight);
            fCopy.clear();
            for (auto a : fileCopy)
            {
                if (a.find(temp) == -1)
                {
                    fCopy.push_back(a);
                }
                else
                {
                    fCopy.push_back(a.substr(0, a.rfind(',') + 1) + " " + weight);
                }
            }
            writeToFile(fCopy);
        }
    }
}