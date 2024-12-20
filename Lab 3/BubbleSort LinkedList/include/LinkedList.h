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
        int postNode;
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

        void swap(int &a, int &b){
            int tmp = a;
            a=b;
            b=tmp;
        }


        void bubbleSort(){
            Node* current=head;
            for(int outer = 0; outer<counter-1; outer++){
                current=head;

                for(int inner = 0; inner<counter-outer-1; inner++){

                    if(current->data > current->next->data){
                        swap(current->data, current->next->data);

                    }
                    current=current->next;
                }
            }
        }

        void display(){
            Node* current=head;
            while(current != NULL){
                cout << current->data << " ";
                current=current->next;
            }
            cout << endl;
        }

        void remove(int target){
            if(head==NULL){
                throw "LinkedList is empty!";
                return;
            }
            Node* current = head;
            while(current->data != target){
                current=current->next;
            }

            if(current == head && current == tail){
                head=tail=NULL;
            }
            else if(current == head){
                head=current->next;
                head->prev=NULL;
            }
            else if(current == tail){
                tail=current->prev;
                tail->next=NULL;
            }else{
                current->prev->next=current->next;
                current->next->prev=current->prev;
            }
            delete current;
        }


        int removeBubble(int target){
            if(head==NULL){
                throw "LinkedList is empty!";
                return NULL;
            }
            Node* current = head;
            while(current->data != target){
                current=current->next;
            }
            int returned = current->data;
            postNode=current->next->data;

            if(current == head && current == tail){
                head=tail=NULL;
            }
            else if(current == head){
                head=current->next;
                head->prev=NULL;
            }
            else if(current == tail){
                tail=current->prev;
                tail->next=NULL;
            }else{
                current->prev->next=current->next;
                current->next->prev=current->prev;
            }
            delete current;
            return returned;
        }

        void insertAfter(int target, int data){

            //if LinkedList is empty
            if(head==NULL){
                cout<<"Empty LinkedList"<<endl;
                return;
            }
            Node* newNode = new Node(data);
            Node* current = head;

            while(current->data != target){
                current=current->next;
            }
            current->next->prev=newNode;
            newNode->next=current->next;

            current->next=newNode;
            newNode->prev=current;
            counter++;

            return;
        }

        void bubbleSortNode(){
            Node* current=head;
            for(int outer = 0; outer<counter-1; outer++){
                current=head;

                for(int inner = 0; inner<counter-outer-1; inner++){

                    if(current->data > current->next->data){
                        int returned = removeBubble(current->data);
                        insertAfter(postNode, returned);
                    }
                    current=current->next;
                }
            }
        }
        ~LinkedList(){};

    protected:

    private:
};

#endif // LINKEDLIST_H

        /*void insertAfter(int target, Node *newNode){

            //if LinkedList is empty
            if(head==NULL){
                cout<<"Empty LinkedList"<<endl;
                return;
            }
            Node* current = head;

            while(current->data != target){
                current=current->next;
            }
            current->next->prev=newNode;
            newNode->next=current->next;

            current->next=newNode;
            newNode->prev=current;
            counter++;

            return;
        }*/
