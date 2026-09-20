#include <iostream>
using namespace std;

class BinarySearch
{
    int a[50], n, key;

public:
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter sorted elements: ";
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << "Enter element to search: ";
        cin >> key;
    }

    void search()
    {
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (a[mid] == key)
            {
                cout << "Element found at position " << mid + 1;
                return;
            }
            else if (key > a[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }

        cout << "Element not found";
    }
};

int main()
{
    BinarySearch b;
    b.input();
    b.search();

    return 0;
}