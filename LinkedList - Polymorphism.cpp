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
    int getLength()             { return this->length; }
    bool isEmpty()              { return this->head == NULL; }
    virtual Node * getHead()    { return this->head; }

    void print(){
        Node * temp = this->head;
        while (temp != NULL){
            cout << temp->getData() << "->";
            temp = temp->getNext();
        }
        cout << "NULL\n";
    }

    // virtual functions
    virtual void insertAtHead(int) = 0;
    virtual void insertAtLast(int) = 0;
    virtual void removeAtHead() = 0;
    virtual void removeAtLast() = 0;

};

class Singly : public LinkedList{
public:
    void insertAtHead(int value){
        Node * temp = new Node(value,this->head);
        this->head = temp;
        this->length++;
    }
    
    void insertAtLast(int value){
        if (this->isEmpty()){
            this->insertAtHead(value);
        }
        else {
            Node * temp = new Node(value);
            Node * previous = NULL; // Last ptr
            Node * current = this->head; // null pointer in the end
            while (current != NULL){
                previous = current;
                current = current->getNext();
            }
            previous->setNext(temp);
        }
        this->length++;
    }

    void removeAtHead(){
        if (!(this->isEmpty())){
            if (this->getLength() == 1){
                delete this->head;
                this->head = NULL;
            }
            else {
                Node * temp = this->head; // to delete
                this->head = this->head->getNext();
                delete temp;
            }
            this->length--;
        }
    }

    void removeAtLast(){
        if (!this->isEmpty()){
            if (this->getLength() == 1){
                this->removeAtHead();
            }
            else {
                Node * previous = NULL; // Last ptr
                Node * current = this->head; // null pointer in the end
                while (current->getNext() != NULL){
                    previous = current;
                    current = current->getNext();
                }
                Node * temp = previous->getNext(); //
                previous->setNext(NULL);
                delete temp;
                this->length--;
            }
        }
    }
};

class Doubly : public LinkedList{
public:
    void insertAtHead(int value){
        Node * temp = new Node(value,this->head);
        this->head = temp;
        this->length++;
    }
    void insertAtLast(int value){
        if (this->isEmpty()){
            this->insertAtHead(value);
        }
        else {
            Node * previous = NULL;
            Node * current = this->head;
            
            while (current != NULL){
                previous = current;
                current = current->getNext();
            }
            Node * temp = new Node(value,NULL,previous);
            previous->setNext(temp);
            this->length++;
        }
    }
    void removeAtLast(){
        cout << "removeAtLast\n";
    }
    void removeAtHead(){
        cout << "removeAtHead\n";
    }

};

int main(){
    LinkedList * l1 = new Doubly;
    l1->insertAtHead(1);
    l1->insertAtHead(1);
    l1->insertAtLast(2);
    l1->print();
    cout << "DLL Length : " << l1->getLength();
    cout << endl;
    return 0;
}
