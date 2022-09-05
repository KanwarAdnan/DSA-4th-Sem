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


    // virtual functions
    virtual void print() = 0;
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

    void print(){
        Node * temp = this->head;
        while (temp != NULL){
            cout << temp->getData() << "->";
            temp = temp->getNext();
        }
        cout << "NULL\n";
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
        if (!this->isEmpty()){
            if (this->getLength() == 1){
                this->removeAtHead();
            }
            else {
                Node * previous = NULL; // second last ptr
                Node * current = this->head; // null ptr in the end
                
                while (current->getNext() != NULL){
                    previous = current;
                    current = current->getNext();
                }
                previous->setNext(NULL);
                delete current;
                this->length--;
            }
        }
    }
    void removeAtHead(){
        if (!this->isEmpty()){
            if (this->getLength() == 1){
                delete this->head;
                this->head = NULL;
            }
            else {
                Node * temp = this->head; // to delete
                this->head = this->head->getNext();
                delete temp;
                this->head->setPrev(NULL);
            }
            this->length--;
        }
    }

    void print(){
        Node * temp = head;
        cout << "NULL<->";
        while (temp != NULL){
            cout << temp->getData() << "<->";
            temp = temp->getNext();
        }
        cout << "NULL\n";
    }
};

int main(){
    LinkedList * l1 = new Singly;
    l1->insertAtLast(1);
    l1->insertAtLast(2);
    l1->insertAtHead(0);
    l1->removeAtLast();
    l1->removeAtHead();
    l1->print();
    cout << "SLL Length : " << l1->getLength();
    cout << endl;

    LinkedList * l2 = new Doubly;
    l2->insertAtLast(1);
    l2->insertAtLast(2);
    l2->insertAtHead(0);
    l2->removeAtLast();
    l2->removeAtHead();
    l2->print();
    cout << "DLL Length : " << l1->getLength();
    cout << endl;
    return 0;
}
