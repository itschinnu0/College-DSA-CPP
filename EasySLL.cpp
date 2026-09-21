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
    void insertBegin(int x)
    {
        Node *n = new Node{x, head};
        head = n;
    }

    void insertPos(int x, int pos)
    {
        if (pos == 1)
        {
            insertBegin(x);
            return;
        }

        Node *t = head;
        for (int i = 1; i < pos - 1; i++)
            t = t->next;

        Node *n = new Node{x, t->next};
        t->next = n;
    }

    void deleteBegin()
    {
        Node *t = head;
        head = head->next;
        delete t;
    }

    void deletePos(int pos)
    {
        if (pos == 1)
        {
            deleteBegin();
            return;
        }

        Node *t = head;
        for (int i = 1; i < pos - 1; i++)
            t = t->next;

        Node *d = t->next;
        t->next = d->next;
        delete d;
    }

    void deleteEnd()
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *t = head;
        while (t->next->next != NULL)
            t = t->next;

        delete t->next;
        t->next = NULL;
    }

    void search(int x)
    {
        Node *t = head;
        int pos = 1;

        while (t != NULL)
        {
            if (t->data == x)
            {
                cout << "Found at position " << pos << endl;
                return;
            }
            t = t->next;
            pos++;
        }

        cout << "Not Found\n";
    }

    void display()
    {
        Node *t = head;

        while (t != NULL)
        {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList l;

    l.insertBegin(30);
    l.insertBegin(20);
    l.insertBegin(10);       // 10 20 30

    l.insertPos(25, 3);      // 10 20 25 30
    l.display();

    l.deleteBegin();         // 20 25 30
    l.deletePos(2);          // 20 30
    l.deleteEnd();           // 20

    l.display();
    l.search(20);

    return 0;
}
