#include <stdio.h>
#include "Linked_List.hpp"
using namespace std;

int main()
{
    ll::Linked_List<int> list;
    list.print();
    list.insert_at_start(1);
    list.print();
    list.insert_at_start(2);
    list.print();
    list.insert_at_start(4);
    list.print();
    list.insert_at_end(9);
    list.print();
    list.insert_at_pos(5, 3);
    list.print();
    cout << list[2].val << endl << list[2].next << endl;
    list.delete_at_end();
    list.print();
    list.delete_at_start();
    list.print();
    list.delete_at_pos(1);
    list.print(); 
}
