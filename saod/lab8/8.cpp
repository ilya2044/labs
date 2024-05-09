#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct Contact
{
    string name;
    string phone;
    string email;
    string address;
};

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printContacts(Contact *contacts, int *index1, int *index2, int size)
{
    cout << "Контакты:" << endl;
    for (int i = 0; i < size; i++)
    {
        Contact contact = contacts[i];
        cout << setw(5) << "(" << contact.name << " | " << setw(15) << contact.phone << " | " << setw(19) << contact.email << " | " << setw(11) << contact.address << ")" << endl;
    }
    cout << endl;
    cout << "Сортировка по имени:" << endl;
    for (int i = 0; i < size; i++)
    {
        Contact contact = contacts[index1[i]];
        cout << setw(5) << "(" << contact.name << " | " << setw(5) << contact.phone << " | " << setw(19) << contact.email << " | " << setw(11) << contact.address << ")" << endl;
    }
    cout << endl;
    cout << "Сортировка по номеру телефона:" << endl;
    for (int i = 0; i < size; i++)
    {
        Contact contact = contacts[index2[i]];
        cout << setw(5) << "(" << contact.name << " | " << setw(15) << contact.phone << " | " << setw(19) << contact.email << " | " << setw(11) << contact.address << ")" << endl;
    }
}

void selectionSortName(Contact *contacts, int *index)
{
    int size = 5;
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (contacts[index[i]].name < contacts[index[min_idx]].name)
                min_idx = i;
        }
        swap(index[min_idx], index[step]);
    }
}

void selectionSortNumber(Contact *contacts, int *index)
{
    int size = 5;
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (contacts[index[i]].phone < contacts[index[min_idx]].phone)
                min_idx = i;
        }
        swap(index[min_idx], index[step]);
    }
}
int main()
{
    Contact contacts[5] = {
        {"Afanasiy Ritov", "8(972)774-46-17", "afanasiy1985@hotmail.com", "Proletarskaya 15"},
        {"Nikolay Tomsin", "8(721)262-36-79", "vasiliy04081995@hotmail.com", "Lenina 20"},
        {"Ilya Petrov", "8(290)652-70-99", "viktor9905@rambler.ru", "Gurievskaya 51"},
        {"Philipp Shihirin", "8(085)553-30-34", "denis1965@gmail.com", "Pushkina 13"},
        {"Ivan Vlasov", "8(342)470-67-14", "pavel22@rambler.ru", "Dzerjinskogo 29"}};
    int size = 5;
    int index1[5] = {0, 1, 2, 3, 4};
    int index2[5] = {0, 1, 2, 3, 4};
    selectionSortName(contacts, index1);
    selectionSortNumber(contacts, index2);
    printContacts(contacts, index1, index2, size);
    printf("%d\n", index1);
    printf("%d", index2);
    return 0;
}
