#include <iostream>
using namespace std;

class LinearSearch
{
    int a[50], n, key;

public:
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements: ";
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << "Enter element to search: ";
        cin >> key;
    }

    void search()
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == key)
            {
                cout << "Element found at position " << i + 1;
                return;
            }
        }

        cout << "Element not found";
    }
};

int main()
{
    LinearSearch l;
    l.input();
    l.search();

    return 0;
}