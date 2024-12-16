#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main()
{
    LinkedList l;
    l.add(5);
    l.add(10);
    l.add(15);
    l.add(20);

    //l.insertAfter(999, 20);
    l.insertBefore(99,5);
    //cout<< l.getByIndex(3)<< endl;

    //cout << l.getCount()<<endl;

    l.display();
    return 0;
}
