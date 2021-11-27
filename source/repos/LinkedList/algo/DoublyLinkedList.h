#pragma once
#include <iostream>
#include <stdexcept> 

using namespace std;

class List
{
private:

    class Node // implementing a node in a list
    {
    public:
        Node(int data, Node* pNext = nullptr, Node* pPrev = nullptr) // constructor
        {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
        int data;
        Node* pNext;
        Node* pPrev;
    };

    Node* head; // creating a head
    Node* tail; // creating a tail
    size_t Size;
public:
    List() // initialize the first object
    {
        head = nullptr;
        tail = nullptr;
        Size = 0;
    }

    ~List() // destructor
    {
        clear();
    }

    void clear() // deleting all list items
    {
        while (Size)
        {
            pop_front();
        }
    }

    size_t GetSize() { return Size; } // getting the list size

    void push_front(int data) // inserting a node at the top of the list
    {

        if (Size > 1)
        {
            Node* temp = head;
            head = new Node(data, head);
            temp->pPrev = head;
        }
        else if (Size == 1)
        {
            head = new Node(data, head); // creating a new head element
            tail->pPrev = this->head; // at the tail, we put the previous pointer on the new element
        }
        else
        {
            head = tail = new Node(data, head, tail);
        }
        Size++;

    }

    void push_back(int data) // inserting a node at the end of the list
    {
        if (Size > 1)
        {
            Node* temp = tail;
            tail = new Node(data, nullptr, tail);
            temp->pNext = tail;
        }
        else if (Size == 1)
        {
            tail = new Node(data, nullptr, tail);
            head->pNext = this->tail;
        }
        else
        {
            head = tail = new Node(data, head, tail);
        }
        Size++;
    }

    void pop_front() // removing a node from the top of the list
    {
        if (isEmpty() == 0) {
            if (Size > 1)
            {
                Node* temp = head;
                head = head->pNext;
                delete temp;
            }
            else if (Size == 1)
            {
                Node* temp = head;
                tail = head = head->pNext;
                delete temp;
            }

            Size--;
        }
        else throw std::invalid_argument("Index is out of range");

    }

    void pop_back() // removing a node from the end of the list
    {
        if (!isEmpty()) {
            if (GetSize() == 1) {
                delete head;
                head = tail = NULL;
                Size--;
            }
            if (GetSize() > 1) {
                Node* item = tail->pPrev;
                delete tail;
                tail = item;
                tail->pNext = NULL;
                Size--;
            }
        }
        else throw std::invalid_argument("Index is out of range");
    }

    void insert(int data, size_t index) // adding an item by index
    {
        if (index <= GetSize() && index >= 0) {
            if (index == 0) push_front(data);

            else if (index == Size) push_back(data);


            else if (index <= Size / 2) // if the head is closer
            {
                Node* previous = this->head; // creating a node with the address of the head
                for (int i = 0; i < index - 1; i++)  //walk from the head to the node that points to the one we need
                {
                    previous = previous->pNext;
                }

                Node* newNode = new Node(data, previous->pNext, previous); // creating a new node

                previous->pNext = newNode;
                Node* next = newNode->pNext;
                next->pPrev = newNode;

                Size++;
            }

            else if (index > Size / 2) // if the tail is closer
            {
                Node* next = this->tail;
                for (int i = Size - 1; index < i; i--)
                {
                    next = next->pPrev;
                }

                Node* newNode = new Node(data, next, next->pPrev);

                next->pPrev = newNode;
                Node* previous = newNode->pPrev;
                previous->pNext = newNode;

                Size++;
            }
        }
        else throw std::invalid_argument("Index is out of range");
    }

    void remove(size_t index) // deleting an item by index
    {
        if (index < GetSize() && index >= 0) {
            if (index == 0) pop_front();
            else if (index == Size - 1) pop_back();


            else if (index <= Size / 2) // if the head is closer
            {
                Node* previous = this->head;
                for (int i = 0; i < index - 1; i++)
                {
                    previous = previous->pNext;
                }

                Node* toDelete = previous->pNext;
                previous->pNext = toDelete->pNext;
                Node* next = toDelete->pNext;
                delete toDelete;
                next->pPrev = previous;

                Size--;
            }

            else if (index > Size / 2) // if the tail is closer
            {
                Node* next = this->tail;
                for (int i = Size - 1; index < i; i--)
                {
                    next = next->pPrev;
                }

                Node* toDelete = next->pPrev;
                next->pPrev = toDelete->pPrev;
                Node* previous = toDelete->pPrev;
                delete toDelete;
                previous->pNext = next;

                Size--;
            }
        }
        else throw std::invalid_argument("Index is out of range");
    }

    void set(int data, size_t index)
    {
        if (index < GetSize() && index >= 0) {

            if (index <= Size) {
                Node* current = this->head;
                for (int i = 0; i < index; i++)
                {
                    current = current->pNext;
                }
                current->data = data;
            }
        }
        else throw std::invalid_argument("Index is out of range");
    }

    bool isEmpty() {
        return GetSize() == 0;
    }

    int at(size_t index) // getting an item by index
    {
        if (index < GetSize() && index >= 0) {
            Node* current = head;
            int count = 0;
            while (count != index)
            {
                count++;
                current = current->pNext;
            }
            return current->data;
        }
        else throw std::invalid_argument("Index is out of range");
    }

    void push_back(List& const list)
    {
        Node* curr = head;
        Node* curr2 = list.head;
        while (curr2 != NULL)
        {
            push_back(curr2->data);
            curr2 = curr2->pNext;
        }
    }

    friend std::ostream& operator<< (std::ostream& out, List& list);
};

std::ostream& operator<< (std::ostream& out, List& list) {
    if (list.GetSize() == 0) std::cout << "List is empty\n";
    else {
        List::Node* current = list.head;
        while (current != NULL) {
            out << current->data << " ";
            current = current->pNext;
        }

    }
    return out;
}