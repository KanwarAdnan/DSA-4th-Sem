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
        int top()           { return (list.getLastElement()); }
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
                value = list.getLastElement();
                list.removeLast();
                return value;
            }
            return -9999;
        }

};


int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << "Printing Stack\n";
    s1.print();
    cout << "Stack Methods : ";
    cout << "\n\tPopped : " << s1.pop();
    cout << "\n\tTop : " << s1.top();
    cout << "\n\tLength : " << s1.getLength();
    cout << "\n\tIsFull : " << s1.isFull();
    cout << "\n\tIsEmpty : " << s1.isEmpty();
    cout << "\nAfter Pop Stack\n";
    s1.print();
}

/*
Output : 
    Printing Stack
    1->2->3->NULL
    Stack Methods : 
        Popped : 3
        Top : 2
        Length : 2
        IsFull : 0
        IsEmpty : 0
    After Pop Stack
    1->2->NULL
*/
