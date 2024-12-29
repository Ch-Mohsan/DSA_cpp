 #include <iostream>
using namespace std;

template<class genType,int size=10>
class gernal{
private:
    genType array[size];
public:
    void fillarray(){
        for(int i=0;i<size;++i) {
            cout << "Enter value " << i+1 << ": ";
            cin >> array[i];
        }
    }
    
    void display(){
        for(int i=0;i<size;i++)
            cout << array[i] << endl;
    }
    
    void swap1(int idx1, int idx2){ // Modified to accept indices
        if (idx1 < 0 || idx1 >= size || idx2 < 0 || idx2 >= size) {
            cout << "Invalid indices." << endl;
            return;
        }
        
        cout << "Values before the swap: " << array[idx1] << " , " << array[idx2] << endl;
        genType temp = array[idx1];
        array[idx1] = array[idx2];
        array[idx2] = temp;
        cout << "Values after the swap: " << array[idx1] << " , " << array[idx2] << endl;
    }
};

int main(){
    cout << "Enter 3 float values: " << endl;
    gernal<float,3> obj1;
    obj1.fillarray();
    obj1.display();
    float el1, el2; // Indices
    cout << "Enter two indices to swap: ";
    cin >> el1 >> el2;
    obj1.swap1(el1, el2); // Passing indices
    
    cout << "Enter 3 integer values: " << endl;
    gernal<int,3> obj2;
    obj2.fillarray();
    obj2.display();
    int el3, el4; // Indices
    cout << "Enter two indices to swap: ";
    cin >> el3 >> el4;
    obj2.swap1(el3, el4); // Passing indices

    return 0;
}
