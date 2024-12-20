#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList l;
    l.add(50);
    l.add(40);
    l.add(10);
    l.add(99);
    l.add(30);


    l.display();

    l.bubbleSortNode();

    l.display();

    return 0;
}
