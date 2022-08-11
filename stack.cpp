#include "LinkedList.h"

class Stack{
    private:
        LinkedList list;
        int limit;
    public:
        Stack(){
            this->limit = 100;
        }
        Stack(int limit){
            this->limit = limit;
        }
        bool isFull()       { return (list.getLength()==limit); }
        bool isEmpty()      { return (list.isEmpty()); }
        int top()           { return (list.getLast()->getData()); }
        int getLength()     { return (list.getLength()); }
        void print()        { list.print(); }

        bool push(int value){
            if (!isFull()){
                list.insertAtLast(value);
                return true;
            }
            return false;
        }
        int pop(){
            int value = 0;
            if (!isEmpty()){
                Node* last = list.getLast();
                Node* secondLast = list.getElementById((list.getLength()-1));
                value = last->getData();
                secondLast->setNext(NULL);
                delete last;
                return value;
            }
            return -9999;
        }

};


int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.print();
    s1.pop();
    cout << "\n";
    s1.print();
}

/*
output :
    1->2->NULL
    
    1->NULL
*/
