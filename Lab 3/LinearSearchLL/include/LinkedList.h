#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;
#include "Node.h"

class LinkedList
{
    public:
        Node* head;
        Node* tail;
        LinkedList(){
            head=NULL;
            tail=NULL;
        };

        void add(int data, int index){
            Node* newNode = new Node(data,index);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
        }
        void display(){
            Node* current=head;
            while(current != NULL){
                cout << "Index " << current->index << ": " << current->data <<endl;
                current=current->next;
            }
            cout << endl;
        }

        void linearSearch(LinkedList &l, int size, int arr[], int target){
            if(size < 1){
                throw "Empty Array!";
                return;
            }
            for(int i= 0; i<size; i++){
                if(arr[i]==target){
                    l.add(arr[i], i);
                }
            }
        }

    protected:

    private:
};

#endif // LINKEDLIST_H

