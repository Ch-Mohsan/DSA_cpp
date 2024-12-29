#include <iostream>
using namespace std;
class stack{
public:
int arr[4];
int curr=-1;
int size=0;
int max=5;
void push(int x){
    if(size==max){
    cout<<"list is full";
    return; }
    
arr[curr]=x;
curr++;
size++;

}
int pop(){
    if(curr==-1){
        cout<<"list is empty";

    }
return arr[curr--];
size--;


}
void display(){
for(int i=0;i<=curr;i++){
    cout<<arr[i]<<endl;
}
}
};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.push(7);
    
    s.display();

return 0;
}