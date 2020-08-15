#include "List.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"

void test_List() 
{
    cout << "=================================\n";
    cout << "           LIST TESTING\n";
    cout << "=================================\n";

    List<int> list;
    list.Insert(0, 21);
    list.Insert(1, 47);
    list.Insert(2, 87);
    list.Insert(3, 35);
    list.Insert(4, 92);

    cout << "List before insert:\n";
    for (uint32_t i = 0; i < list.Count(); ++i)
    {
        cout << list.Get(i) << " ";
    }
    cout << "\n\n";
   
    list.Insert(2, 25);
    list.Insert(2, 71);
   
    cout << "List after insert:\n";
    for (uint32_t i = 0; i < list.Count(); ++i)
    {
        cout << list.Get(i) << " ";
    }
    cout << "\n\n";


    cout << "Looking for 71\n";
    uint32_t result = list.Search(71);
    cout << "Element 71 find at " << result << "\n\n";

    list.Remove(2);
    cout << "List after remove:\n";
    for (uint32_t i = 0; i < list.Count(); ++i)
    {
        cout << list.Get(i) << " ";
    }
    cout << "\n\n";
}

void test_LinkedList() 
{
    cout << "=================================\n";
    cout << "       LINKED LIST TESTING\n";
    cout << "=================================\n";
    LinkedList<int> linkedList = LinkedList<int>();
    linkedList.InsertHead(43);
    linkedList.InsertHead(76);
    linkedList.InsertTail(15);
    linkedList.InsertTail(44);

    cout << "Print before insert:\n";
    linkedList.PrintList();
    cout << "\n";
    
    linkedList.Insert(4, 100);
    linkedList.Insert(3, 48);
    linkedList.Insert(0, 22);
    
    cout << "Print after insert:\n";
    linkedList.PrintList();
    cout << "\n";
    

    cout << "Get value at index 2:\n";
    Node<int>* get = linkedList.Get(2);
    cout << get->value;
    cout << "\n\n";


    cout << "Index of value 15:\n";
    int srch = linkedList.Search(15);
    cout << srch << "\n\n";
   
    cout << "Remove first element:\n";
    linkedList.Remove(0);
    linkedList.PrintList();
    cout << "\n";
    
    cout << "Remove fifth element:\n";
    linkedList.Remove(4);
    linkedList.PrintList();
    cout << "\n";

    cout << "Remove tenth element:\n";
    linkedList.Remove(9);
    linkedList.PrintList();
    cout << "\n";
}

void test_DoublyLinkedList()
{
    cout << "=================================\n";
    cout << "  DOUBLY LINKED LIST TESTING\n";
    cout << "=================================\n";

    DoublyLinkedList<int> linkedList = DoublyLinkedList<int>();

    linkedList.InsertHead(43);
    linkedList.InsertHead(76);
    linkedList.InsertTail(15);
    linkedList.InsertTail(44);

    cout << "List before insert:\n";
    linkedList.PrintListBackward();
    cout << "\n";

    linkedList.Insert(4, 100);
    linkedList.Insert(3, 48);
    linkedList.Insert(0, 22);

    cout << "List after insert:\n";
    linkedList.PrintListBackward();
    cout << "\n";
}