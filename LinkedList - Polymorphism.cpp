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
        
        int getData(){
            return this->data;
        }
        
        void setData(int data){
            this->data = data;
        }
        
        void setPrev(Node * prev){
            this->prev = prev;
        }
        
        void setNext(Node * next){
            this->next = next;
        }
        
        Node * getPrev(){
            return this->prev;
        }
        
        Node * getNext(){
            return this->next;
        }

    
};

class LinkedList{
    protected:
        Node * head = NULL;
        int length;
    public:
        virtual void insertAtHead(int) = 0;
        virtual void print() = 0;
};

class Singly : public LinkedList{
    public:
        void insertAtHead(int x){
            Node * temp = new Node(x,this->head);
            this->head = temp;
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
    l1->insertAtHead(1);
    l1->insertAtHead(1);
    l1->insertAtHead(1);
    l1->insertAtHead(1);
    l1->print();
    return 0;
}
