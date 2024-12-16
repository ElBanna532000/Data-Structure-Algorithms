#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
using namespace std;

class LinkedList
{
    public:
        Node* head;
        Node* tail;
        int counter;
        LinkedList(){
            head=NULL;
            tail=NULL;
            counter=0;
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
            counter++;
        }
        void display(){
            Node* current=head;
            while(current != NULL){
                cout << current->data << " ";
                current=current->next;
            }
            cout << endl;
        }

        void insertAfter(int data, int target){

            //if LinkedList is empty
            if(head==NULL){
                cout<<"Empty LinkedList"<<endl;
                return;
            }

            Node* newNode = new Node(data);
            Node* current = head;

            //Inserting a Node before the only Node existing inside the LinkedList
            if(tail->data==target){
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
                return;
            }
            while(current != NULL){
                if(current->data == target){
                    current->next->prev=newNode;
                    newNode->next=current->next;

                    current->next=newNode;
                    newNode->prev=current;
                    counter++;

                    return;
                }else{
                    current=current->next;
                }
            }
        }

        void insertBefore(int data, int target){

            //if LinkedList is empty
            if(head==NULL){
                cout<<"Empty LinkedList"<<endl;
                return;
            }

            Node* newNode = new Node(data);
            Node* current = head;

            //Inserting a Node before the only Node existing inside the LinkedList
            if(head->data==target){
                newNode->next=head;
                head->prev=newNode;
                head=newNode;
                return;
            }

            while(current != NULL){
                if(current->data == target){
                    current->prev->next=newNode;
                    newNode->prev = current->prev;

                    current->prev=newNode;
                    newNode->next=current;
                    counter++;
                    return;
                }else{
                    current=current->next;
                }
            }
        }

        int getByIndex(int index){
            Node* current = head;
            int start=0;
            while(start != index){
                current=current->next;
                start++;
            }
            return current->data;
        }



        int getCount(){
            return counter;
        }
        ~LinkedList(){};













    protected:

    private:
};

#endif // LINKEDLIST_H
