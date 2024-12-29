#include <iostream>
#include "Node.cpp"
using namespace std;
class Q{
    private:
    Node*front;
    Node*rear;
    public:
    Q(){
 front=NULL;
 rear=NULL;

    }
int dequeue()
{
    int x = front->get();
    Node* p = front;
    front = front->getNext();
    delete p;
    return x;
}
void enqueue(int x)
{
    Node* newNode = new Node();
    newNode->set(x);
    newNode->setNext(NULL);
    if (rear == NULL) {
        front = rear = newNode; // if queue is empty
    } else {
        rear->setNext(newNode);
        rear = newNode;
    }
}
void display() {
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->get() << " ";
        temp = temp->getNext();
    }
    cout << endl; 
}

};
int main (){
    Q q;
    q.enqueue(1);
        q.enqueue(2);
            q.enqueue(3);
                q.enqueue(4);
                q.display();
                q.dequeue();
                q.display();

    return 0;
}
