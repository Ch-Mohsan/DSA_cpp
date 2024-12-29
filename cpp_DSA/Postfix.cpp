#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int evaluateExpression(const string &expression) {
    stack<int> s;
    int num = 0;
    bool isNum = false;

    for (char c : expression) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Multiply by 10 to shift digits and add the new digit
            isNum = true;
        } else if (c == ' ' && isNum) {
            s.push(num);
            num = 0;
            isNum = false;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (!s.empty()) {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();
                switch (c) {
                    case '+':
                        s.push(op1 + op2);
                        break;
                    case '-':
                        s.push(op1 - op2);
                        break;
                    case '*':
                        s.push(op1 * op2);
                        break;
                    case '/':
                        s.push(op1 / op2);
                        break;
                }
            }
        }
    }

    return s.top();
}

int main() {
    string expression = "12 10 + 3 *";
    int result = evaluateExpression(expression);
    cout << "Result: " << result << endl;
    return 0;
}
