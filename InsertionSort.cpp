#include <iostream>
using namespace std;

class InsertionSort
{
    int a[50], n;

public:
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void sort()
    {
        for (int i = 1; i < n; i++)
        {
            int key = a[i];
            int j = i - 1;

            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }

            a[j + 1] = key;
        }
    }

    void display()
    {
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
    }
};

int main()
{
    InsertionSort s;
    s.input();
    s.sort();
    s.display();

    return 0;
}