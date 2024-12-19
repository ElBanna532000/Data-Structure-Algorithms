#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node(int data){
        this->data=data;
        prev = NULL;
    }
};
class StackLinkedList{
    public:
        Node* top;
        StackLinkedList(){
              top = NULL;
        }
        void push(int data){
            Node * newNode = new Node(data);
            newNode->prev = top;
            top = newNode;
        }

        int pop(){
            if(top == NULL)
                throw "Stack Empty";
            int output = top->data;
            Node* tmp = top;
            top = top->prev;
            delete tmp;
            return output;
        }
        int peek(){
            if(top == NULL)
                throw "Stack is empty";
            return top->data;
        }
        void display(){
            if(top == NULL)
                throw "Stack is empty";
            Node* current = top;
            while(current != NULL){
                cout<<current->data<<endl;
                current = current->prev;
            }
        }
};

int main()
{
    StackLinkedList s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Stack contents:" << endl;
    s.display();

    try {
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;

        // Attempt to pop from empty stack
        cout << "Popped: " << s.pop() << endl;
    }
    catch (const char* error) {
        cout << "Error: " << error << endl;
    }
    return 0;
}

