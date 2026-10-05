#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List class
class DoublyLinkedList
{
private:
    Node* head;

public:

    // Constructor
    DoublyLinkedList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertBeginning(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;
    }

    // Insert at end
    void insertEnd(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete from beginning
    void deleteBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;
    }

    // Delete from end
    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp->prev != NULL)
        {
            temp->prev->next = NULL;
        }
        else
        {
            head = NULL;
        }

        delete temp;
    }

    // Display forward
    void displayForward()
    {
        Node* temp = head;

        if (temp == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        cout << "Forward: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Display backward
    void displayBackward()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        cout << "Backward: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    int choice, value;

    do
    {
        cout << "\n--- Doubly Linked List ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display Forward\n";
        cout << "6. Display Backward\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;

        case 3:
            list.deleteBeginning();
            break;

        case 4:
            list.deleteEnd();
            break;

        case 5:
            list.displayForward();
            break;

        case 6:
            list.displayBackward();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}
