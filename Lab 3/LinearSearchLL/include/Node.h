#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        int data;
        int index;
        Node* next;
        Node* prev;
        Node(int data, int index){
            this->data=data;
            this->index=index;
            next=NULL;
            prev=NULL;
        };
        ~Node(){};

    protected:

    private:
};

#endif // NODE_H
