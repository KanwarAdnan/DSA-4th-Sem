/*
    LinkedList Header File : Made by Kanwar Adnan
    List of Methods :
        1)  isEmpty()
        2)  isIndex()
        3)  isValid()
        4)  insertAtBeginning(int value)
        5)  insertAtLast(int value)
        6)  removeFirst()
        7)  removeLast()
        8)  insertAtId(int id, int value)
        9)  removeAtId(int id)
        10) getLength()
        11) getFirst()
        12) getLast()
        13) getElementById(int id)
        14) getElementByValue(int value)
        15) getElementIdByValue(int value)
        16) deleteElementById(int id)
        17) deleteElementByValue(int value)
        18) doesExist(int value)
        19) doesExistRet(int value , int * index)
        20) reverse()
        21) print()
        22) printWithIndex()
        23) printRev(Node * current)
        24) getFirstElement()
        25) getLastElement()
        26) getNodeById(int id)
        27) swapElements(int x , int y)
        28) swap(int id1 , int id2)
        29) sort()
        30) remDup()
*/
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
    Node * getNext()            { return next; }
    int getData()               { return data; }
    void setNext(Node * next)   { this->next = next; }
    void setData(int data)      { this->data = data; }
};

class LinkedList{
private:
    Node * head;
    int length;
public:
    LinkedList() : length(0) , head(NULL) {}
    bool isEmpty()              { return (head == NULL); }
    bool isIndex(int index)     { return ( (index <= length) && (index > 0) ); }
    bool isValid(int index)     { return ( (!isEmpty()) && (isIndex(index)) ); }
    Node * getFirst()            { return getNodeById(1); }
    Node * getLast()            { return getNodeById(length); }
    int getFirstElement()       { return getFirst()->getData(); }
    int getLastElement()        { return getLast()->getData(); }
    int getLength()             { return length; }

    // Insertion Methods ------------------------------

    void insertAtBeginning(int value){
        Node * temp = new Node(value); // New node to add at the head
        temp->setNext(head);        // setting head as the next of the node
        head = temp;                // it will be okay if the head is null
        length++;                   // as the next of node will also will be null
    }

    void insertAtLast(int value){
        if (isEmpty())              // if the head is null then add at the head first
            insertAtBeginning(value);
        else {
            Node * temp = new Node(value); // new node to add at the last
            Node * temp2 = getNodeById(length); // getting the last node
            temp2->setNext(temp);           // setting it's next to the new node
        }                                   // the next of new last will be pointing at
        length++;                           // null automatically
    }

    void insertAtId(int id,int value){
        if (!isEmpty() && isIndex(id) ){  // making sure index is correct
            if (id == 1){               // if index is 1 adding node at the head
                insertAtBeginning(value);
            }
            else {
                Node * temp = new Node(value); // new node to be added
                Node * prevId = getNodeById(id-1); // getting previous node from the index
                Node * currentId = prevId->getNext();   // current index using prev->next
                prevId->setNext(temp);              // setting prev-next as new node
                temp->setNext(currentId);           // setting new node's next as current node
                length++; 
            }
        }
    }
        // Comment it if does not need this
        else if (!isEmpty() && (id > length) ){     // this is just an extra function to add a
            insertAtLast(value);                    // node at the end of the list if is out ouf bound
        }
     }

    // Displaying Methods ------------------------------
    // These methods will print the linkedlist in ascending and decending orders

    void print(){
        Node * temp = head;
        while (temp != NULL){
            cout << temp->getData() << "->";
            temp = temp->getNext();
        }
        cout << "NULL\n";
    }

    void printWithIndex(){
        Node * temp = head;
        int index = 1;
        while (temp != NULL){
            cout << index << " : " << temp->getData() << '\n';
            index++;
            temp = temp->getNext();
        }
        cout << '\n';
    }

    // These below two functions are overloaded

    void printRev(Node * current){
        if (current == NULL)
            return;
        printRev(current->getNext());
        cout << "<-" << current->getData();
    }
    
    void printRev(){
        cout << "NULL";
        printRev(getFirst());
    }


    // deletion Methods ------------------------------

    void removeFirst(){
        if (isEmpty())      // if list is empty then return
            return;
        else if (head->getNext() == NULL) { // if length is one then delete head
            delete head;
            head = NULL;
        }
        else {
            Node * temp = head->getNext(); // getting head-next for assinging it
            delete head;                    // as the new head of the list
            head = temp;                    // then deleted the head
        }
        length--;
    }

    void removeLast(){
        if (isEmpty())              // if empty return
            return;
        else if(head->getNext() == NULL){   // if length is 1 then remove head
            removeFirst();
        }
        else {
            Node * temp = getNodeById( length - 1 ); // getting 2nd last element
            Node * temp2 = temp->getNext();         // last element from 2nd last
            delete temp2;                           // deleted the last element
            temp->setNext(NULL);                    // closed the chain by setting null
        }                                           // to the next of 2nd last
        length--;
    }
    
    // It's also same as deleteElementById
    void removeAtId(int id){
        if (!isEmpty() && isIndex(id)){
            if (id == 1){                   // if id is 1 remove head
                removeFirst();
            }
            else if (id == length){         // if id is equal to length remove last
                removeLast();
            }
            else {
                Node * prevId = getNodeById(id-1);      // getting previous from id
                Node * currentId = prevId->getNext();   // getting current from previou
                Node * nextId = currentId->getNext();   // getting next from current
                prevId->setNext(nextId);                // setting previous-next as nextId
                delete currentId;                       // deleting the given index node
                length--;                               
            }
        }
    }

    void deleteElementByValue(int value){
        if (!isEmpty()){
            if ( (head->getData() == value) && (length <= 2) )
                removeFirst();
            else {
                Node * temp = head;
                Node * temp2 = head->getNext();
                while (temp2->getNext() != NULL){
                    if (temp2->getData() == value){
                        Node * next = temp2->getNext();
                        temp->setNext(next);
                        delete temp2;
                        length--;
                        return;
                    }
                    temp2 = temp2->getNext();
                    temp = temp->getNext();
                }
                // If the last member is to delete
                if (temp2->getData() == value){
                    removeLast();
                }
            }
        }
    }
    
    // Getters ------------------------------


    int getElementById(int id){
        Node * temp = getNodeById(id);
        if (temp != NULL)
            return temp->getData();
        return -9999;
    }

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


    Node * getNodeByValue(int value){
        if (!isEmpty()){
            Node * temp = head;
            while (temp != NULL){
                if (value == temp->getData())
                    return temp;
                temp = temp->getNext();
            }
        }
        return NULL;
    }

    int getElementIdByValue(int value){
        if (!isEmpty()){
            Node * temp = head;
            int count = 1;
            while (temp != NULL){
                if (value == temp->getData())
                    return count;
                count++;
                temp = temp->getNext();
            }
        }
        return -9999;
    }

    // Some More Methods ------------------------------

    bool doesExist(int value){
        Node * temp = head;
        while (temp != NULL){
            if (value == temp->getData())
                return true;
            temp = temp->getNext();
        }
        return false;
    }

    // This method returns the index of the element if it exists
    Node * doesExistRet(int value, int* index){
        Node * temp = head;
        int count = 1;
        while (temp != NULL){
            if (value == temp->getData()){
                *index = count;
                return temp;
            }
            temp = temp->getNext();
            count++;
        }
        *index = -1; // -1 incase element not found
        return NULL;
    }

    void reverse(){
        if (!isEmpty()){
            if (length == 1){
                return;
            }
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
    }

    void swapElements(int x, int y){
        // Copied from geeeksforgeeks
        // Nothing to do if x and y are same
        if (x == y)
            return;
     
        // Search for x (keep track of prevX and CurrX
        Node *prevX = NULL, *currX = head;
        while (currX && currX->data != x) {
            prevX = currX;
            currX = currX->next;
        }
     
        // Search for y (keep track of prevY and CurrY
        Node *prevY = NULL, *currY = head;
        while (currY && currY->data != y) {
            prevY = currY;
            currY = currY->next;
        }
     
        // If either x or y is not present, nothing to do
        if (currX == NULL || currY == NULL)
            return;
     
        // If x is not head of linked list
        if (prevX != NULL)
            prevX->next = currY;
        else // Else make y as new head
            head = currY;
     
        // If y is not head of linked list
        if (prevY != NULL)
            prevY->next = currX;
        else // Else make x as new head
            head = currX;
     
        // Swap next pointers
        Node* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;     
    }
    
    void sort(){
        Node* cur1 = head;
        Node* cur2 = head;

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length - 1; j++) {
                if (cur1->data < cur2->data) {
                    int temp = cur1->data;
                    cur1->data = cur2->data;
                    cur2->data = temp;
                }
                cur2 = cur2->next;
            }
            cur2 = head;
            cur1 = head->next;
            for (int k = 0; k < i; k++) {
                cur1 = cur1->next;
            }
        }        
    }

    // Mine but inspired from above code
    void swap(int id1, int id2){
        if (isIndex(id1) && isIndex(id2)){
            if (id1 == id2)
                return;
            else {
                Node * prevId1 = NULL , * currId1 = head;
                Node * prevId2 = NULL , * currId2 = head;
                
                int count = 1;
                while (count != id1){
                    prevId1 = currId1;
                    currId1 = currId1->getNext();
                    count++;
                }
                
                count = 1;
                while (count != id2){
                    prevId2 = currId2;
                    currId2 = currId2->getNext();
                    count++;
                }
                
                if (currId1 == NULL || currId2 == NULL){
                    return;
                }
                
                if (prevId1 != NULL){
                    prevId1->setNext(currId2);
                }
                else {
                    head = currId2;
                }

                if (prevId2 != NULL){
                    prevId2->setNext(currId1);
                }
                else {
                    head = currId1;
                }
                Node * nextId2 = currId2->getNext();
                currId2->setNext(currId1->getNext());
                currId1->setNext(nextId2);
            }
        }
    }

    void removeDuplicates(){
        LinkedList l1;
        l1.insertAtLast(head->getData());
        Node * toDelete = head;
        head = head->getNext();
        delete toDelete;
        
        while (head != NULL){
            if (!l1.doesExist(head->getData())){
                l1.insertAtLast(head->getData());
            }
            toDelete = head;
            head = head->getNext();
            delete toDelete;
        }
        delete head;
        head = l1.getFirst();
        length = l1.getLength();
    }
    
};


int main(){
    LinkedList l1;
    l1.insertAtLast(8);
    l1.insertAtLast(8);
    l1.insertAtLast(6);
    l1.insertAtLast(6);
    l1.insertAtLast(4);
    l1.insertAtLast(4);
    l1.insertAtLast(2);
    l1.insertAtLast(2);
    l1.print();
    l1.sort();
    l1.removeDuplicates();
    l1.print();
}
/*
Output: 
    8->6->4->2->NULL
    2->4->6->8->NULL
*/
