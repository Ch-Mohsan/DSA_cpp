#include<iostream>
#include "TreeNode.cpp"
#include <stack>


using namespace std;
void insert(TreeNode<int>*root,int*info){
TreeNode<int>*node=new TreeNode<int>(info);
TreeNode<int>*p,*q;

p=q=root;
while(*info<*(p->getInfo())&&q!=nullptr){
if(*info<*(p->getInfo())){
    q=p->getLeft();
}
else{
    q=p->getRight();
}
}
if(*info==*(p->getInfo())){
    cout<<"you are trying to add doublicate "<<endl;
    
}
else if(*info<*(p->getInfo())){
    p->setLeft(node);

}
else 
p->setRight(node);
}
void inorder(TreeNode<int>*root){
if(root==nullptr){
return;
}
 stack<TreeNode<int>*> s;
TreeNode<int>*curr=root;
while(!s.empty()&&curr!=nullptr){
 while(curr!=nullptr){
    s.push(curr);
    curr=curr->getLeft();
 }
 if(!s.empty()){
curr=s.top();
s.pop();
cout<<curr->getInfo();
curr=curr->getRight();

 }
}
}
void preorder(TreeNode<int>*root){
    if(root==nullptr){
        return;
        }
    
    stack<TreeNode<int>*>s;
    s.push(root);
    while(!s.empty()){
        TreeNode<int>*node=new TreeNode<int>();
        node=s.top();
        s.pop();
        if(node->getLeft()){
            s.push(node->getLeft());
        }
        if(node->getRight()){
            s.push(node->getRight());
        }
        
    }
}
void postorder(TreeNode<int>*root){
    if(root==nullptr){
        return;
    }
    stack<TreeNode<int>*>s1,s2;
     s1.push(root);
while(!s1.empty()){
    TreeNode<int>*node=s1.top();
s1.pop();
if(node->getLeft()){
    s1.push(node->getLeft());
}
if(node->getRight()){
    s1.push(node->getRight());
}


}
  while(!s2.empty()){
    TreeNode<int>*node=s2.top();
s2.pop();
cout<<node->getInfo()<<"";
  }
}
int main(){
    int x[]={14,15,4,9,7,18,3,5,16,4,20,17,9,14,5,-1};
    TreeNode<int>*root=new TreeNode<int>();
    root->setInfo(&x[0]);
    for(int i=1;&x[i]>0;i++){
        insert(root,&x[i]);

    }
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    
    return 0;
}