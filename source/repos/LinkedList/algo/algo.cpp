#include "DoublyLinkedList.h"
using namespace std;


int main()
{
    List list1;

    List list;

    for (int i = 0; i < 10; i++)
        list1.push_back(i);
    cout << "Showing the list 1: ";
    cout << list1 << endl;
    list.push_front(3);
    list.push_front(4);
    cout << "Showing the list 2: ";
    cout << list << endl;
    list1.set(10, 0);
    cout << "List after function set: ";
    cout << list1 << endl;

    cout << "List after function pop_back: ";
    list1.pop_back();

    cout << list1 << endl;

    cout << "List after function pop_back: ";
    list1.pop_front();

    cout << list1 << endl;

    cout << "List after function remove ( deleting an element by index 2): ";
    list1.remove(2);

    cout << list1 << endl;

    cout << "Adding a list to the end of another: ";
    list1.push_back(list);
    cout << list1;

    return 0;
}
