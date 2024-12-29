#include<iostream>
#include "Node.cpp"
using namespace std;

class Dlist {
public:
    Node* currNode;
    Node* prevNode;
    Node* headNode;
    int size;

    Dlist() {
        headNode = new Node();
        headNode->setNext(NULL);
        currNode = NULL;
        prevNode = NULL;
        size = 0;
    }

    void add(int data) {
        Node* newNode = new Node();
        newNode->set(data);

        if (currNode != NULL) {
            newNode->setNext(currNode->getNext());
            newNode->setprev(currNode);
            if (currNode->getNext() != NULL)
                (currNode->getNext())->setprev(newNode);
            currNode->setNext(newNode);
        } else {
            newNode->setNext(NULL);
            newNode->setprev(NULL);
            headNode->setNext(newNode);
        }

        currNode = newNode;
        size++;
    }

    void print() {
        Node* tempNode = headNode->getNext();
        while (tempNode != NULL) {
            cout << tempNode->get() << " ";
            tempNode = tempNode->getNext();
        }
        cout << endl;
    }
};

int main() {
    Dlist dl;
    dl.add(2);
    dl.add(3);
    dl.add(4);
    dl.print();

    return 0;
}
