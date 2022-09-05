#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node * next;
    Node * prev;
public:
    Node(int data = 0 , Node * next = NULL , Node * prev = NULL){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
    
    void setData(int data)      { this->data = data; }
    void setPrev(Node * prev)   { this->prev = prev; }
    void setNext(Node * next)   { this->next = next; }
    int getData()               { return this->data; }
    Node * getPrev()            { return this->prev; }
    Node * getNext()            { return this->next; }
};

class LinkedList{
protected:
    Node * head = NULL;
    int length;
public:
    int getLength()                 { return this->length; }
    bool isEmpty()                  { return this->head == NULL; }
    // virtual functions
    virtual void insertAtHead(int) = 0;
    virtual void insertAtLast(int) = 0;
    virtual void print() = 0;
    virtual Node * getHead() = 0;

};

class Singly : public LinkedList{
public:
    Node * getHead()                { return this->head; }

    void insertAtHead(int value){
        Node * temp = new Node(value,this->head);
        this->head = temp;
        this->length++;
    }
    
    void insertAtLast(int value){
        Node * temp = new Node(value);
        if (this->isEmpty()){
            this->head = temp;
        }
        else {
            Node * previous = NULL; // second Last ptr
            Node * current = this->head;
            while (current->getNext() != NULL){
                previous = current;
                current = current->getNext();
            }
            previous->setNext(temp);
        }
        this->length++;
    }
    
    void print(){
        Node * temp = this->head;
        while (temp){
            cout << temp->getData() << "->";
            temp = temp->getNext();
        }
        cout << "NULL\n";
    }
    
    
};

int main(){
    LinkedList * l1 = new Singly;
    l1->insertAtLast(3);
    l1->insertAtHead(1);
    l1->insertAtHead(1);
    l1->insertAtHead(1);
    l1->insertAtHead(2);
    l1->print();
    cout << l1->getLength();
    cout << endl;
    return 0;
}
