#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
public:
    Node() : data(0), next(NULL) {}

    Node(int data, Node* next = NULL){
        setData(data);
        setNext(next);
    }
    
    void setData(int data)      { this->data = data; }
    void setNext(Node* next)    { this->next = next; }
    int getData()               { return this->data; }
    Node* getNext()             { return this->next; }
};

class LinkedList{
private:
    Node* head;
    int length;
public:
    LinkedList() : head(NULL),length(0)   {}
    LinkedList(Node* head)      { setHead(head); }
    bool isEmpty()              { return (head == NULL); }
    void setHead(Node* head)    { this->head = head; }
    Node* getFirst()            { return head; }
    Node* getLast()             { return getNodeById(length); }
    int getLength()             { return length; }

    /* Discarding it because we no longer need this because of better option
    int getLength(){
        int count = 0;
        if (!isEmpty() ){
            Node* temp = head;
            while(temp != NULL){
                temp = temp->getNext();
                count++;
            }
        }
        return count;
    }
    */

    void print(){
        if (!isEmpty()){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->getData() << "->";
                temp = temp->getNext();
            }
        }
        cout << "NULL\n";
    }

    Node* getNodeById(int index = 1){
        Node* temp = head;
        if (!isEmpty() && (index <= length) ){
            for(int i = 0 ; i < (index - 1) ; i++){
                temp = temp->getNext();
            }
            return temp;
        }
        return NULL;
    }
    
    void deleteValue(int value){
        if (!isEmpty()){
            Node * previous = head;
            Node * current = head->getNext();
            if (head->getData() != value){    
                while (current->getNext() != NULL){
                    if (current->getData() == value){
                        Node * next = current->getNext();
                        previous->setNext(next);
                        delete current;
                    }
                    previous = previous->getNext();
                    current = current->getNext();
                }
            }
            else {
                Node * newHead = head->getNext();
                delete head;
                head = newHead;
            }
        }
    }
    
    Node* getNodeByValue(int value){
        if (!isEmpty()){
            Node* temp = head;
            while(value != temp->getData()){
                temp = temp->getNext();
            }
            return temp;
        }
        return NULL;
    }

    void insertAtBeginning(int value){
        Node* temp = new Node(value);

        if (!isEmpty()){
            temp->setNext(head);
            head = temp;
        }
        else {
            head = temp;
        }

        length++;
    }

    void insertAtLast(int value){
        Node * temp = new Node(value);

        if (!isEmpty()){
            Node * last = getLast();
            last->setNext(temp);
        }

        else {
            head = temp;
        }

        length++;
    }

    void removeFirst(){
        if (!isEmpty()){
            Node* temp = head->getNext();
            delete head;
            head = temp;
            length--;
        }
    }

    void removeLast(){
        Node * previous = head;
        Node * next = head->getNext();

        if (head->getNext() != NULL){
            while (next->getNext() != NULL){
                next = next->getNext();
                previous = previous->getNext();
            }

            delete next;
            previous->setNext(NULL);

        }

        else {
            delete head;
            head = NULL;
        }

        length--;

    }
    
    bool doesExist(int value){
        Node * temp = head;
        while (temp != NULL){
            if (value == temp->getData()){
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }

    void reverse(){
        Node * previous = NULL;
        Node * current = head;
        Node * next = NULL;
        while(current != NULL){
            next = current->getNext();
            current->setNext(previous);
            previous = current;
            current = next;
        }
        head = previous;
    }

};

int main(){
    
    LinkedList l1;
    int i = 1;
    while(i<=10){
        l1.insertAtLast(i);
        i++;
    }
    l1.insertAtBeginning(0);
    l1.print();
    l1.reverse();
    l1.print();

    
}
