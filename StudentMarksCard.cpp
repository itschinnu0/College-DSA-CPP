#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name, usn, sub[5];
    int marks[5];

    string getGrade(int m)
    {
        if (m >= 90)  return "O";
        if (m >= 80)  return "A+";
        if (m >= 70)  return "A";
        if (m >= 60)  return "B+";
        if (m >= 50)  return "B";
        if (m >= 40) return "C+";
        if (m >= 35)  return "C";
        return "F";
    }

public:
    void input()
    {
        cout << "Enter Name & USN: ";
        cin >> name >> usn;
        for (int i = 0; i < 5; i++)
        {
            cout << "Subject " << i + 1 << " Name & Marks: ";
            cin >> sub[i] >> marks[i];
        }
    }

    void display()
    {
        float total = 0;
        bool pass = true;

        cout << "\n========================================\n";
        cout << "Name: " << name << "\tUSN: " << usn << "\n";
        cout << "----------------------------------------\n";
        cout << "Subject\t\tMarks\tGrade\n";
        cout << "----------------------------------------\n";

        for (int i = 0; i < 5; i++)
        {
            string g = getGrade(marks[i]);
            if (g == "F")
                pass = false;
            total += marks[i];
            cout << sub[i] << "\t\t" << marks[i] << "\t" << g << "\n";
        }

        cout << "----------------------------------------\n";
        cout << "Average : " << total / 5.0 << "\n";
        cout << "CGPA    : " << total / 50.0 << "\n";
        cout << "Result  : " << (pass ? "PASS" : "FAIL") << "\n";
        cout << "========================================\n";
    }
};

int main()
{
    Student s;
    s.input();
    s.display();
    return 0;
}