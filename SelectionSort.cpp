#include <iostream>
using namespace std;

class SelectionSort
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
            int min = i;

            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < a[min])
                    min = j;
            }

            swap(a[i], a[min]);
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
    SelectionSort s;
    s.input();
    s.sort();
    s.display();

    return 0;
}