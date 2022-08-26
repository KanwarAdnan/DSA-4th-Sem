/*
    Queue using singly linked list variant
*/

#include <iostream>
using namespace std;
class Node{
private:
        int data;
        Node * next;
public:
    Node() : next(NULL),data(0) {}

    Node(int data, Node* next = NULL){
        setData(data);
        setNext(next);
    }
    
    void setData(int data)      { this->data = data; }
    void setNext(Node* next)    { this->next = next; }
    int getData()               { return this->data; }
    Node* getNext()             { return this->next; }
};

class LinkedList2{
    private:
        Node * head;
        Node * last;
    public:
        LinkedList2(){
            head = NULL;
            last = NULL;
        }
        Node* getFirst(){
            return head;
        }
        int getLength(){
            int count = 0;
            if (!isEmpty() ){
                Node * temp = head;
                while(temp != NULL){
                    temp = temp->getNext();
                    count++;
                }
            }
            return count;
        }

    
        void insertAtBeginning(int x){
            Node * temp = new Node(x);
            temp->setNext(head);
            last = head;
            head = temp;
        }

        void insertAtLast(int x){
            Node * n = new Node(x);
            if (!isEmpty()){
                Node * temp = head;
                while( temp->getNext() != NULL){
                    temp = temp->getNext();
                }
                temp->setNext(n);
                last = n;
            }
            else {
                head = n;
            }
            }
        void removeFirst(){
            if (isEmpty()){
                return;
            }
            else if (head->getNext() == NULL) {
                delete head;
                head = NULL;
            }
            else {
                Node * temp = head->getNext();
                delete head;
                head = temp;
            }
        }

        void print(){
            if (!isEmpty()){
                Node* temp = head;
                while(temp != NULL){
                    cout << temp->getData() << "->";
                    temp = temp->getNext();
                }
            }
            cout << "NULL";
        }
        bool isEmpty()              { return (head == NULL); }    
};

class Queue{
    private:
        LinkedList2 list;
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
    cout << "Printing Queue\n";
    q1.print();
    q1.dequeue();
    cout << "\nQueue Methods : ";
    cout << "\n\tPeek : " << q1.peek();
    cout << "\n\tLength : " << q1.getLength();
    cout << "\n\tIsFull : " << q1.isFull();
    cout << "\n\tIsEmpty : " << q1.isEmpty();
    cout << "\nAfter dequeue Queue\n";
    q1.print();
}

/*
Output :
    Printing Queue
    0->2->4->NULL
    Queue Methods : 
        Peek : 2
        Length : 2
        IsFull : 0
        IsEmpty : 0
    After dequeue Queue
    2->4->NULL

*/
