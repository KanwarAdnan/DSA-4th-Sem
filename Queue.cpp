#include "linkedlist.h"

class Queue{
    private:
        LinkedList list;
        int limit;
        int size;
    public:
        Queue(int limit = 100){
            this->limit = limit; 
        }
        bool isFull()       { return (list.getLength()==limit); }
        bool isEmpty()      { return (list.isEmpty()); }
        int peek()           { return (list.getFirst()->getData()); }
        int getLength()     { return (list.getLength()); }
        void print()        { list.print(); }
        
        void enqueue(int value){
            if (!isFull()){
                list.insertAtLast(value);
            }
        }
        
        void dequeue(){
            if (!isEmpty()){
                list.removeFirst();
            }
        }
};

int main(){
    Queue q1;
    q1.enqueue(0);
    q1.enqueue(2);
    q1.enqueue(4);
    q1.dequeue();
    q1.print();
    cout << "Peek : " << q1.peek() << endl;
}
