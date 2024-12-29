#include <iostream>
#include <stack>
#include <string>

using namespace std;


int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0; 
    }
}

int main() {
    
    char op = '*'; 
    int op_precedence = precedence(op); 
    cout << "Precedence of " << op << " is " << op_precedence << endl;
    return 0;
}
