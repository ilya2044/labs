#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 17
#define MAX_EMAIL_LENGTH 50
#define MAX_ENTRIES 5

typedef struct
{
    char name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} PhonebookEntry;

typedef struct
{
    char *key;
    int index;
} IndexEntry;

void shellsort(IndexEntry arr[], int n)
{
    int gap, i, j;
    IndexEntry temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap && strcmp(arr[j - gap].key, temp.key) > 0; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void fill_and_sort_indexes(PhonebookEntry entries[], IndexEntry index1[], IndexEntry index2[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        index1[i].key = entries[i].surname;
        index1[i].index = i;
        index2[i].key = entries[i].email;
        index2[i].index = i;
    }

    shellsort(index1, n);
    shellsort(index2, n);
}

void print_phonebook(PhonebookEntry entries[], IndexEntry index1[], IndexEntry index2[], int n)
{
    int i;
    printf("%-15s%-15s%-20s%-30s\n", "Surname", "Name", "Phone", "Email");
    for (i = 0; i < n; i++)
    {
        printf("%-15s%-15s%-20s%-30s\n", entries[index1[i].index].surname, entries[index1[i].index].name,
               entries[index1[i].index].phone, entries[index1[i].index].email);
    }
    printf("\n");
    printf("Сортировка по почте \n");
    printf("%-30s%-15s%-15s%15s\n", "email", "Surname", "Name", "Phone");
    for (i = 0; i < n; i++)
    {
        printf("%-30s%-15s%-15s%-20s\n", entries[index2[i].index].email, entries[index2[i].index].surname,
               entries[index2[i].index].name, entries[index2[i].index].phone);
    }
}

int main()
{
    PhonebookEntry entries[MAX_ENTRIES] = {
        {"Afanasiy", "Ritov", "+7 993 206-69-91", "afanasiy1985@mail.ru"},
        {"Nikolay", "Tomsin", "+7 499 554-55-25", "vasiliy04081995@mail.ru"},
        {"Ilya", "Petrov", "+7 499 754-47-93", "viktor9905@mail.ru"},
        {"Philipp", "Shihirin", "+7 993 730-01-23", "denis1965@mail.ru"},
        {"Ivan", "Vlasov", "+7 901 654-23-45", "pavel22@mail.ru"}};

    IndexEntry index1[MAX_ENTRIES];
    IndexEntry index2[MAX_ENTRIES];

    printf("Контакты:\n");
    printf("%-15s%-15s%-20s%-s\n", "Surname", "Name", "Number", "Email");
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        printf("%-15s%-15s%-20s%-30s\n", entries[i].surname, entries[i].name, entries[i].phone, entries[i].email);
    }
    printf("\n");
    printf("Сортировка по фамилии \n");
    fill_and_sort_indexes(entries, index1, index2, MAX_ENTRIES);
    print_phonebook(entries, index1, index2, MAX_ENTRIES);

    printf("\n");
    printf("Index1:\n");
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        printf("%d ", index1[i].index);
    }

    printf("\nIndex2:\n");
    for (int i = 0; i < MAX_ENTRIES; i++)
    {
        printf("%d ", index2[i].index);
    }
    printf("\n");

    return 0;
}