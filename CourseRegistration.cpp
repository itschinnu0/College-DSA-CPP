#include <iostream>
#include <string>
using namespace std;

class Course
{
    string code, name;
    int total = 0, registered = 0;

public:
    void input()
    {
        cout << "Enter Code, Name & Total Seats: ";
        cin >> code >> name >> total;
    }

    void display(int index)
    {
        cout << index << ".\t" << code << "\t\t" << name << "\t\t"
             << total << "\t\t" << registered << "\t\t" << (total - registered) << "\n";
    }

    void showSeats()
    {
        cout << code << " (" << name << "): " << (total - registered) << " seats left\n";
    }

    bool registerSeat()
    {
        if (registered < total)
        {
            registered++;
            cout << "Registration successful for " << name << "!\n";
            return true;
        }
        cout << "Registration failed: Course is full!\n";
        return false;
    }
};

int main()
{
    Course courses[10];
    int n, choice, totalRegistrations = 0;

    cout << "Enter number of courses (max 10): ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << ":\n";
        courses[i].input();
    }

    do
    {
        cout << "\n========================================\n";
        cout << "1. Display Courses\n";
        cout << "2. Available Seats\n";
        cout << "3. Register Course\n";
        cout << "4. Total Registrations Count\n";
        cout << "5. Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\n----------------------------------------------------------------------\n";
            cout << "No.\tCode\t\tName\t\tTotal\t\tReg.\t\tAvailable\n";
            cout << "----------------------------------------------------------------------\n";
            for (int i = 0; i < n; i++)
                courses[i].display(i + 1);
            cout << "----------------------------------------------------------------------\n";
            break;

        case 2:
            cout << "\n--- Available Seats ---\n";
            for (int i = 0; i < n; i++)
                courses[i].showSeats();
            break;

        case 3:
        {
            int num;
            cout << "Enter course number (1 to " << n << "): ";
            cin >> num;
            if (num >= 1 && num <= n)
            {
                if (courses[num - 1].registerSeat())
                    totalRegistrations++;
            }
            else
            {
                cout << "Invalid course selection!\n";
            }
            break;
        }

        case 4:
            cout << "\nTotal Successful Registrations: " << totalRegistrations << "\n";
            break;

        case 5:
            cout << "Exiting system. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please select 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}