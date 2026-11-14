
#include <iostream>
using namespace std;

// Structure for creating a tree node
struct Node
{
    int data;
    Node *left, *right;
};

// Class for BST operations
class BST
{
    Node *root;

    Node* insert(Node *r, int value)
    {
        if (r == NULL)
        {
            Node *temp = new Node;
            temp->data = value;
            temp->left = temp->right = NULL;
            return temp;
        }

        if (value < r->data)
            r->left = insert(r->left, value);
        else
            r->right = insert(r->right, value);

        return r;
    }

    bool search(Node *r, int value)
    {
        if (r == NULL)
            return false;

        if (r->data == value)
            return true;

        if (value < r->data)
            return search(r->left, value);

        return search(r->right, value);
    }

    void inorder(Node *r)
    {
        if (r != NULL)
        {
            inorder(r->left);
            cout << r->data << " ";
            inorder(r->right);
        }
    }

    void preorder(Node *r)
    {
        if (r != NULL)
        {
            cout << r->data << " ";
            preorder(r->left);
            preorder(r->right);
        }
    }

    void postorder(Node *r)
    {
        if (r != NULL)
        {
            postorder(r->left);
            postorder(r->right);
            cout << r->data << " ";
        }
    }

    Node* minimum(Node *r)
    {
        while (r->left != NULL)
            r = r->left;

        return r;
    }

    Node* deleteNode(Node *r, int value)
    {
        if (r == NULL)
            return NULL;

        if (value < r->data)
            r->left = deleteNode(r->left, value);

        else if (value > r->data)
            r->right = deleteNode(r->right, value);

        else
        {
            if (r->left == NULL)
            {
                Node *temp = r->right;
                delete r;
                return temp;
            }

            else if (r->right == NULL)
            {
                Node *temp = r->left;
                delete r;
                return temp;
            }

            Node *temp = minimum(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }

        return r;
    }

public:

    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void search(int value)
    {
        if (search(root, value))
            cout << "Element found\n";
        else
            cout << "Element not found\n";
    }

    void deletion(int value)
    {
        root = deleteNode(root, value);
    }

    void display()
    {
        cout << "\nInorder: ";
        inorder(root);

        cout << "\nPreorder: ";
        preorder(root);

        cout << "\nPostorder: ";
        postorder(root);

        cout << endl;
    }
};

int main()
{
    BST tree;
    int choice, value;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Delete";
        cout << "\n4. Display Traversals";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.insert(value);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                tree.search(value);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deletion(value);
                break;

            case 4:
                tree.display();
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while (choice != 5);

    return 0;
    }
