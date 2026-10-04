#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;
};

// Queue class
class Queue
{
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Enqueue operation
    void enqueue(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = NULL;

        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted into queue.\n";
    }

    // Dequeue operation
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;

        cout << front->data << " deleted from queue.\n";

        front = front->next;

        delete temp;

        if (front == NULL)
        {
            rear = NULL;
        }
    }

    // Display operation
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty.\n";
            return;
        }

        Node* temp = front;

        cout << "Queue: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

// Main function
int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n--- Queue Using Linked List ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
