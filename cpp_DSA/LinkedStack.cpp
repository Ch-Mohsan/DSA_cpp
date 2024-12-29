#include <iostream>
#include "Node.cpp"
using namespace std;

class Linked {
public:
    Node* headNode;
    int size;

    Linked() {
        headNode=new Node();
        headNode->setNext(NULL);
        size = 0;
    }

    void push(int obj) {
        Node* newNode = new Node();
        newNode->set(obj);
        newNode->setNext(headNode);
        headNode = newNode;
        size++;
    }

    int pop() {
        if (headNode == NULL) {
            cout << "List is empty" << endl;
            return -1; 
        }
        Node* tempNode = headNode;
        
        headNode = headNode->getNext();
        delete tempNode;
        size--;
        return tempNode->get();
    }
    int peek(){
        if(headNode!=NULL){
            cout<<headNode->get();
        }
        else{
cout<<"Stack is empty";
        }
    }

    void print() {
        Node* currNode = headNode;
        while (currNode != NULL) {
            cout << currNode->get() << " ";
            currNode = currNode->getNext();
        }
        cout << endl;
    }
};

int main() {
    Linked s;
    s.push(1);
    s.push(2);
    s.print();

     s.pop();
    s.peek();
    s.print();

    return 0;
}
