#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head = NULL;

public:

    void insertBeginning(int x)
    {
        Node *newNode = new Node{x, head};
        head = newNode;
    }

    void insertEnd(int x)
    {
        Node *newNode = new Node{x, NULL};

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    void insertPosition(int x, int pos)
    {
        if (pos == 1)
        {
            insertBeginning(x);
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Invalid position\n";
            return;
        }

        Node *newNode = new Node{x, temp->next};
        temp->next = newNode;
    }

    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;

        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    void deletePosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1)
        {
            deleteBeginning();
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
            temp = temp->next;

        if (temp->next == NULL)
        {
            cout << "Invalid position\n";
            return;
        }

        Node *del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void deleteAll()
    {
        while (head != NULL)
            deleteBeginning();
    }

    void search(int key)
    {
        Node *temp = head;
        int pos = 1;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Found at position " << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Not Found\n";
    }

    void display()
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        cout << "List: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    LinkedList l;
    int choice, x, pos;

    do
    {
        cout << "\n1.Insert Beginning";
        cout << "\n2.Insert End";
        cout << "\n3.Insert Position";
        cout << "\n4.Delete Beginning";
        cout << "\n5.Delete End";
        cout << "\n6.Delete Position";
        cout << "\n7.Delete All";
        cout << "\n8.Search";
        cout << "\n9.Display";
        cout << "\n0.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            l.insertBeginning(x);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> x;
            l.insertEnd(x);
            break;

        case 3:
            cout << "Enter value and position: ";
            cin >> x >> pos;
            l.insertPosition(x, pos);
            break;

        case 4:
            l.deleteBeginning();
            break;

        case 5:
            l.deleteEnd();
            break;

        case 6:
            cout << "Enter position: ";
            cin >> pos;
            l.deletePosition(pos);
            break;

        case 7:
            l.deleteAll();
            break;

        case 8:
            cout << "Enter value to search: ";
            cin >> x;
            l.search(x);
            break;

        case 9:
            l.display();
            break;
        }

    } while (choice != 0);

    return 0;
}
