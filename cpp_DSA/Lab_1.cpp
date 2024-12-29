#include <iostream>
#include "Node.cpp"

using namespace std;
class LinkedNode{
    private:
    Node*head;
Node*currNode;
Node*prevNode;
int size;
    public:

LinkedNode(){
    head=new Node();
    currNode=NULL;
    prevNode+NULL;
    size=0;
}

};
void add_link(Node*&head, int x){
Node *newnode = new Node();
Node*currNode=head;
while(currNode->getNext()!=NULL){
currNode=currNode->getNext();
}
currNode->setNext(newnode);

}
int remove(Node*head){
    if(head == NULL)
        return 0;
    
    Node* currnode = head;
    Node* prevnode = NULL;

    while(currnode->getNext() != NULL){
        prevnode = currnode;
        currnode = currnode->getNext();
    }
    if(prevnode != NULL)
        prevnode->setNext(NULL);
    
    delete currnode;
    return 0;
}

void display(Node*head){
    Node*currNode=head;
    while (currNode!=NULL)
    {
        currNode=currNode->getNext();
         cout<<"  ";
    
    }
    cout<<endl;
   
}
int main(){

    add_link(head,5);
    add_link(head,6);
    display(head);
    remove(head);
    display(head);
    return 0;
}
