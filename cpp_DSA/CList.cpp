#include<iostream>
#include "Node.cpp"
using namespace std;

class cList {
    private:
    Node* head;
    Node* currNode;
    Node *prevNode;
    int size;
public:
    cList(){
        head = new Node();
        head->setNext(head);
        currNode = NULL;
        prevNode=NULL;
        size=0;
    }

    void insertF(int data) {
        Node* newNode = new Node();
        newNode->set(data) ;
        if (currNode == NULL) {
            newNode->setNext(head->getNext());
            head->setNext(head);
            currNode = newNode;
        }
        else {
            Node* temp = head;
            while (temp->getNext()!= head) {
                temp = temp->getNext();
            }
            newNode->setNext(head->getNext());
            temp->setNext(newNode);
            head = newNode;
        }
    }

        void remove(int obj)
    {
        currNode = head->getNext();
        if (currNode == NULL)
        {
            return;
        }
        while (currNode != NULL && currNode->get() != obj)
        {
            prevNode = currNode;
            currNode = currNode->getNext();
        }
        prevNode->setNext(currNode->getNext());
        delete currNode;
    }


    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->get() << " ";
            temp = temp->getNext();
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    cList cl;
    cl.insertF(5);
    cl.insertF(6);
    cl.remove(6);
    cl.display();
    return 0;
}
