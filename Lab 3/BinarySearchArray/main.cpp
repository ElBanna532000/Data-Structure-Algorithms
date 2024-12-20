#include <iostream>
#include "LinkedList.h"

using namespace std;

int binarySearchArray(int target, int size, int *arr){
    int start = 0;
    int end = size-1;
    int counter=0;
    int mid;

    while(start<end){
        counter++;
        mid=(start+end)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(target>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}

int main()
{
    LinkedList l;
    l.add(5);
    l.add(10);
    l.add(15);
    l.add(20);
    l.add(25);
    l.add(30);
    l.display();

    cout<<l.binarySearch(20)<<endl;


    return 0;
}
