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

       