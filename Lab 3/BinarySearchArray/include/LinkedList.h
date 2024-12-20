#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
using namespace std;


class LinkedList
{
    public:
        Node* head;
        Node* tail;
        int size=0;
        LinkedList(){
            head=NULL;
            tail=NULL;
        };

        void add(int data){
            Node* newNode = new Node(data);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
            size++;
        }
        void display(){
            Node* current=head;
            while(current != NULL){
                cout << "Data is: " << current->data << endl;
                current=current->next;
            }
            cout << endl;
        }

        Node* getNodeByIndex(int index){
            Node* current = head;
            int start=0;
            while(start != index){
                current=current->next;
                start++;
            }
            return current;
        }

        int binarySearch(int target){
            int start = 0;
            int end = size-1;
            int mid;
            int counter=0;
            Node* midNode;

            while(start <= end){
                counter++;
                mid=(end+start)/2;
                Node* midNode=getNodeByIndex(mid);
                if(target == midNode->data){
                    cout<<"Number of Iterations is: "<<counter<<endl;
                    return mid;
                }
                else if(target>midNode->data){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
            return -1;
        }
};


#endif // LINKEDLIST_H
