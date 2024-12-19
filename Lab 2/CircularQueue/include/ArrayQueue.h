#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H


class ArrayQueue
{
    public:
        int data;
        int size;
        int front;
        int rear;
        int* arr;

        //creation of the queue
        ArrayQueue(int size) {
            this->size=size;
            front=rear=-1;
            arr=new int[size];
        }
        // check if the queue is empty or not
        int isEmpty(){
            if(front==-1 && rear==-1)
                return 1;
            return 0;
        }
        // check if the queue is full or not
        int isFull(){
            if(front==0 && rear == size-1)
                return 1;
            else if(rear==front-1)
                return 1;
            return 0;
        }
        //push data to the circular queue
        int enqueue(int data){
            if(isFull()){
                //throw "Sorry, Queue is full!";
                return 0;
            }
            if(isEmpty()){
                rear=front=0;
            }
            else if(front != 0 && rear==size-1){
                rear=0;
            }
            else{
                rear++;
            }
            arr[rear]=data;
            return 1;
        }

        int dequeue(){
            if(isEmpty()){
                throw "Sorry, Queue is empty!";
                return 0;
            }
            int output=arr[front];
            if(front == rear){
                front=rear=-1;
            }
            else if(front==size-1){
                front=0;
            }else{
                front++;
            }
            return output;

        }

        int getFront(){
            if(isEmpty()){
                throw "Sorry, Queue is empty!";
                return 0;
            }
            return arr[front];
        }

        int getRear(){
            if(isEmpty()){
                throw "Sorry, Queue is empty!";
                return 0;
            }
            return arr[rear];
        }

        /*void display(){
            if(isEmpty()){
                throw "Sorry, Queue is empty!";
                return 0;
            }
            int current = front;
            while(current != rear+1){
                if(current==size-1 && current != rear)

                cout << arr[current]<<"/t";
                current++;
            }
        }*/




        ~ArrayQueue() {}

    protected:

    private:
};

#endif // ARRAYQUEUE_H
