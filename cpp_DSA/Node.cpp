class Node{
    public:
     int get(){
        return obj;
    }
    void set(int obj){
        this->obj=obj;
    }
    Node* getNext(){
        return nextNode;
    }
    void setNext(Node *nextNode){
        this->nextNode=nextNode;
        
    }
    Node* getprevs(){
        return prevNode;
    }
    void setprev(Node *prevNode){
        this->prevNode=prevNode;
        }

    private:
    int obj;
    Node *nextNode;
     Node *prevNode;
   
};