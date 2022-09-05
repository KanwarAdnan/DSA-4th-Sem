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
    int length = 0;
public:
    int getLength()             { return this->length; }
    bool isEmpty()              { return this->head == NULL; }
    bool isIndex(int index)     { return ( (index <= this->getLength()) && (index > 0) ); }

    Node * getNodeById(int id){
        if ((!isEmpty()) && (isIndex(id))){
            Node * temp = head;
            int count = 1;
            while (count != id){
                temp = temp->getNext();
                count++;
            }
            return temp;
        }
        return NULL;
    }


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
            return;
        }
        else {
            Node * temp = new Node(value);
            Node * last = this->getNodeById(this->getLength()); // last node
            last->setNext(temp);
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
                return;
            }
            else {
                Node * secLast = this->getNodeById(this->getLength() - 1); // second node
                Node * last = secLast->getNext(); // last node
                secLast->setNext(NULL);
                delete last;
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
            return;
        }
        else {
            Node * last = this->getNodeById(this->getLength());
            Node * temp = new Node(value,NULL,last); // last will be previous of new last 
            last->setNext(temp);
            this->length++;
        }
    }
    void removeAtLast(){
        if (!this->isEmpty()){
            if (this->getLength() == 1){
                this->removeAtHead();
                return;
            }
            else {
                Node * secLast = this->getNodeById(this->getLength() - 1); // second last ptr
                Node * last = secLast->getNext();
                secLast->setNext(NULL);
                delete last;
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

class CircularSingly : public LinkedList{
public:
    void insertAtHead(int value){
        Node * temp = new Node(value);
        if (this->isEmpty()){
            temp->setNext(temp);
            this->head = temp;
            this->length++;
            return;
        }
        Node * last = this->getNodeById(this->getLength());
        last->setNext(temp);
        temp->setNext(this->head);
        this->head = temp;
        this->length++;
    }
    void insertAtLast(int value){
        if (this->isEmpty()){
            this->insertAtHead(value);
            return;
        }
        else {
            Node * last = this->getNodeById(this->getLength()); // last node
            Node * temp = new Node(value); // new last
            last->setNext(temp);
            temp->setNext(this->head); 
            this->length++;
        }
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
                return;
            }
            else {
                Node * secLast = this->getNodeById(this->getLength() - 1); // second node
                Node * last = secLast->getNext(); // last node
                secLast->setNext(this->head);
                delete last;
                this->length--;
            }
        }
    }

    void print(){
    Node * temp = this->head;
    do{
        cout << temp->getData() << "->"; 
        temp = temp->getNext(); 
    } while (temp != this->head); 
    cout << "Head\n";
    }
};

void display(LinkedList * obj){
    obj->insertAtLast(1);
    obj->insertAtLast(2);
    obj->insertAtHead(0);
    obj->removeAtLast();
    obj->removeAtHead();
    obj->insertAtLast(2);
    obj->insertAtHead(0);
    obj->print();
    cout << "Length : " << obj->getLength();
    cout << endl;
}

int main(){
    LinkedList * l1 = new Singly;
    LinkedList * l2 = new Doubly;
    LinkedList * l3 = new CircularSingly;
    display(l1);
    display(l2);
    display(l3);
}
