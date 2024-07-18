#include <stdio.h>
#include "Linked_List.hpp"

int main()
{
    ll::Linked_List<int> list;
    list.insert_at_start(1);
    list.insert_at_start(2);
    list.insert_at_start(4);
    list.insert_at_end(9);
    list.insert_at_pos(5, 3);
    list.print();
}
