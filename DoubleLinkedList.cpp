#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
    Node *START;

public:
    DoublyLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        Node *nodeBaru = new Node;

        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "Duplicate roll numbers not allowed" << endl;
                return;
            }

            nodeBaru->next = START;

            if (START != NULL)
                START->prev = nodeBaru;

            nodeBaru->prev = NULL;
            START = nodeBaru;
            return;
        }

        Node *current = START;

        while (current->next != NULL && current->next->noMhs < nim)
        {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->noMhs)
        {
            cout << "Duplicate roll numbers not allowed" << endl;
            return;
        }

        nodeBaru->next = current->next;
        nodeBaru->prev = current;

        if (current->next != NULL)
            current->next->prev = nodeBaru;

        current->next = nodeBaru;
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number of the student whose record is to be deleted: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->prev = NULL;
        }
        else
        {
            if (current->next != NULL)
                current->next->prev = current->prev;

            current->prev->next = current->next;
        }

        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *currentNode = START;

        cout << "Records in ascending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " ";
            currentNode = currentNode->next;
        }
        cout << endl;
    }

    void reverse()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *currentNode = START;

        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }

        cout << "Records in descending order of roll number are:\n";
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << " ";
            currentNode = currentNode->prev;
        }
        cout << endl;
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        int rollNo;
        cout << "Enter the roll number to search: ";
        cin >> rollNo;

        Node *current = START;

        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        if (current == NULL)
            cout << "Record not found" << endl;
        else
            cout << "Record found, roll number is " << current->noMhs << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    char choice;

    do
    {
        cout << "\nMenu\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. Traverse (Ascending)\n";
        cout << "4. Traverse (Descending)\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.reverse();
            break;
        case '5':
            list.searchData();
            break;
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";
        }

        cout << "\nPress enter to continue...";
        cin.ignore();
        cin.get();

    } while (choice != '6');

    return 0;
}