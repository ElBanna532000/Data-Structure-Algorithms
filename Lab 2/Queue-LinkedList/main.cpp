#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class QueueLinkedList{
    public:
    Node * front;
    Node* rear;
    QueueLinkedList(){
        front = NULL;
        rear = NULL;
    }
    void enqueue(int data){
        Node* newNode = new Node(data);
        if(front == NULL && rear == NULL){
            front = newNode;
            rear = newNode;
        }
        rear->next = newNode;
        rear = newNode;

    }

    int dequeue(){
        if(front == NULL && rear == NULL){
            throw "Sorry, Empty Queue";
        }
        int output = front->data;
        Node* tmp = front;
        front = front->next;
        delete tmp;
        if(front == NULL)
            rear == NULL;
        return output;
    }

    int getFront(){
        if(front == NULL)
            throw "Sorry, Empty Queue";
        return front->data;
    }

    int getRear(){
        if(front == NULL)
            throw "Sorry, Empty Queue";
        return rear->data;
    }

    void display(){
        if(front == NULL)
            throw "Sorry, Empty Queue";
        Node* current = front;
        while(current != NULL){
            cout << current->data<<endl;
            current = current->next;
        }
    }

};
int main()
{
    QueueLinkedList q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;


    try{
        q.display();
    }
    catch (const char* msg){
        cout << msg<<endl;
    }
    try{
        q.dequeue();
    }
    catch (const char* msg){
        cout << msg<<endl;
    }
    return 0;
}
