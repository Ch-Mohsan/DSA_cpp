#include <iostream>
using namespace std;
int main(){
    int n=5;
    int arr[n];
    cout<<"Enter five element";
    for(int i=0;i<5;i++)
    cin>>arr[i];
int count=1;
while(count<n){
for(int i=0;i<count;i++){
    if(arr[i]>arr[i+1]){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
}
count++;
}
for(int i=-0;i<count;i++)
cout<<arr[i];
    return 0;
}