#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;
};

// Circular Linked List class
class CircularLinkedList
{
private:
    Node* head;

public:

    // Constructor
    CircularLinkedList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertBeginning(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
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

        if (head->next == head)
        {
            head = NULL;
            delete temp;
            return;
        }

        Node* last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        head = head->next;
        last->next = head;

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

        if (head->next == head)
        {
            head = NULL;
            delete temp;
            return;
        }

        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        Node* last = temp->next;

        temp->next = head;

        delete last;
    }

    // Display circular linked list
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        cout << "Circular Linked List: ";

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

// Main function
int main()
{
    CircularLinkedList list;

    int choice, value;

    do
    {
        cout << "\n--- Circular Linked List ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Delete from End\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

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
            list.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}
