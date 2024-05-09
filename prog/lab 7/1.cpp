#include <iostream>

using namespace std;

void zero_between_min(int arr[], int size)
{

    int min1 = 0, min2 = 1;
    if (arr[min1] > arr[min2])
    {
        min1 = 1;
        min2 = 0;
    }

    for (int i = 2; i < size; i++)
    {
        if (arr[i] < arr[min1])
        {
            min2 = min1;
            min1 = i;
        }
        else if (arr[i] < arr[min2])
        {
            min2 = i;
        }
    }

    if (min2 < min1)
    {
        int temp = min2;
        min2 = min1;
        min1 = temp;
    }

    for (int i = min1 + 1; i < min2; i++)
    {
        arr[i] = 0;
    }
}

int main()
{
    const int size = 10;
    int arr[size] = {2, 4, 7, 6, 1, 8, 5, 2, 9, 3};

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    zero_between_min(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
