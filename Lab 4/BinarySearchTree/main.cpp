#include <iostream>
#include "include/BinaryTree.h"


using namespace std;

int main()
{
    BinaryTree l;
    l.add(50);
    l.add(30);
    l.add(70);
    l.add(20);
    l.add(40);
    l.add(60);
    l.add(80);
    l.add(75);
    l.add(85);
    l.add(45);


    try{
        //cout<< l.findDataInTree(99)<<endl;
        //cout<<l.findParent(20)<<endl;
        //cout<<l.getMaxRightByData(99)<<endl;
        l.removeNode(70);
        //l.findDataInTree(70);
        cout<<l.findParent(60)<<endl;
    }catch(char const* msg){
        cout<<msg;
    }


    return 0;
}
