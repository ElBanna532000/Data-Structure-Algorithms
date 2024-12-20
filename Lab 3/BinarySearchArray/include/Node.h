#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data=data;
            next=NULL;
            prev=NULL;
        };
        ~Node(){};

    protected:

    private:
};
#endif // NODE_H
