#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Infix {
private:
    stack<char> s;
public:
    char applyOperator(char op, char op1, char op2) {
        switch (op) {
            case '+': return op1 + op2;
            case '-': return op1 - op2;
            case '*': return op1 * op2;
            case '/': return op1 / op2;
            // Add cases for other operators as needed
            default:
                cout << "Invalid operator: " << op << endl;
                return '\0';
        }
    }

    char evaluate(string input) {
        for (char e : input) {
            if (isdigit(e)) {
                s.push(e);
            }
             else {
                char op2 = s.top();
                s.pop();
                char op1 = s.top();
                s.pop();
                char value = applyOperator(e, op1, op2);
                s.push(value);
            }
        }
        return s.top();
    }
};

int main() {
    string expression = "52+3*";
    Infix infix;
    char result = infix.evaluate(expression);
    cout << "Result: " << result << endl;
    return 0;
}
