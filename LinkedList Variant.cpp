#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node() : data(0), next(NULL) {}

    Node(int data, Node * next = NULL){
        setData(data);
        setNext(next);
    }
    Node * getNext()            { return this->next; }
    int getData()               { return this->data; }
    void setNext(Node * next)   { this->next = next; }
    void setData(int data)      { this->data = data; }
};

class LinkedList{
    private:
        Node * head;
        Node * last;
    public:
        LinkedList(){
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

int main(){
    LinkedList l1;
    l1.insertAtLast(1);
    l1.insertAtLast(2);
    l1.insertAtBeginning(0);
    l1.print();
    
}
