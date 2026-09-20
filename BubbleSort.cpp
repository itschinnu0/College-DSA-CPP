#include <iostream>
using namespace std;

class BubbleSort
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
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
            }
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
    BubbleSort b;
    b.input();
    b.sort();
    b.display();

    return 0;
}