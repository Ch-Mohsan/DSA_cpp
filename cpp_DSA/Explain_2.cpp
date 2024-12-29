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

string infixToPostfix(const string &input) {
    string postfix = "";
    stack<char> s;

    for (char c : input) {
        if (isalnum(c)) {
            postfix += c; 
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                char op = s.top();
                s.pop();
                postfix += op; 
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        char op = s.top();
        s.pop();
        postfix += op; 
    }

    return postfix;
}

int main() {
    string input = "a+b*c-d/e";
    string postfix = infixToPostfix(input);
    cout << "Infix expression: " << input << endl;
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
