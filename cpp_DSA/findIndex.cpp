#include <iostream>
using namespace std;

int main() {
    int *A = new int[5];
    int p,i;
    
    // Input phase
    cout << "Enter 3 numbers: ";
    
    for( i = 0; i < 3; i++) 
        cin >> A[i];
    
    

    cout << "Enter index to retrieve value: ";
    cin >> p;
    
    
    if(A[i]==p) {

        cout << "Value at index " << p << ": " << A[p] << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
    
    
    return 0;
}
