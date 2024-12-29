#include <iostream>
#include "Node.cpp"
using namespace std;

class LinkList {
    Node *head;
    Node *currNode;
    Node *prevNode;
    int size;
public:
    LinkList() {
        head = new Node();
        currNode = NULL;
        prevNode = NULL;
        size = 0; 
    }
void remove(int obj) {
    currNode = head->getNext();
    prevNode = head;

    while (currNode != NULL && currNode->get() != obj) {
        prevNode = currNode;
        currNode = currNode->getNext();
    }

    if (currNode == NULL) {
        cout << "Value not found in the list." << endl;
        return;
    }

    prevNode->setNext(currNode->getNext());
    delete currNode;
    size--;
}

    void add(int obj) {
        Node *newNode = new Node();
        newNode->set(obj);
        if (currNode != NULL) {
            newNode->setNext(currNode->getNext());
            currNode->setNext(newNode);
            prevNode = head;
            currNode = newNode;
            size++;
        }
        else {
            newNode->setNext(NULL);
            head->setNext(newNode);
            currNode = newNode;
        }
    }

    void display() {
        currNode = head->getNext();
        if (currNode == NULL) {
            cout << "list is null";
            return;
        }
        while (currNode != NULL) {
            cout << currNode->get() << " ";
            currNode = currNode->getNext();
        }
    }
};

int main () {
    LinkList list;
    list.add(5);
    list.add(6);
    list.add(7);
    list.display();
list.remove(6);
list.display();
    return 0;
}
