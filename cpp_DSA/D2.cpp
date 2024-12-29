#include <iostream>
#include "Node.cpp"
using namespace std;
class Clist
{
private:
    Node *head;
    Node *prevNode;
    Node *currNode;
    int size;

public:
    Clist()
    {
        head = new Node();
        head->setNext(NULL);
        currNode = NULL;
        prevNode = NULL;
        size = 0;
    }

    void add(int val)
    {
        Node *newNode = new Node();
        newNode->set(val);
        if (currNode == NULL)
        {
            newNode->setNext(head->getNext());
            newNode->setprev(head);
            if (head->getNext() != NULL)
            {
                (head->getNext())->setprev(newNode);
            }
            head->setNext(newNode);
            currNode = newNode;
            prevNode = head;
        }
        else
        {
            newNode->setNext(currNode->getNext());
            newNode->setprev(currNode);
            if (currNode->getNext() != NULL)
            {
                (currNode->getNext())->setprev(newNode);
            }
            currNode->setNext(newNode);
            prevNode = currNode;
            currNode = newNode;
        }
        size++;
    }

    void display(){
        currNode = head ->getNext();
        while (currNode!=head)
        {
            cout<<currNode->get()<<" ";
            currNode = currNode->getNext();
        }
        cout<<endl;
    }
};
int main(){
    Clist cl;
    cl.add(1);
    cl.add(2);
    cl.add(3);
    cl.add(4);
    cl.display();
}