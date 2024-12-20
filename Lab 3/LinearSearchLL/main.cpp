#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList l;
    int size = 10;
    int arr [size] = {10,20,30,10,99,20,10,10,0,60};
    int target = 10;

    l.linearSearch(l, size, arr, target);

    l.display();
    return 0;
}
