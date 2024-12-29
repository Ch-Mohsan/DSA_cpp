#include <iostream>
using namespace std;
const int MAX_SIZE = 100; // Maximum size of the stack
class Stack {
private:
int top; // Index of the top element
int arr[MAX_SIZE]; // Array to store stack elements
public:
Stack() {
top = -1; // Initialize top to -1 to indicate an empty stack
}
// Function to push an element onto the stack
void push(int val) {
if (top == MAX_SIZE - 1) {
cout << "Stack Overflow! Cannot push element " << val << endl;
return;
}
arr[++top] = val; // Increment top and insert the element at the new top 
//index
cout << "Pushed " << val << " onto the stack." << endl;
}
// Function to pop an element from the stack
int pop() {
if (isEmpty()) {
cout << "Stack Underflow! Cannot pop element from an empty stack." << 
endl;
return -1; // Return -1 to indicate stack underflow
}
return arr[top--]; // Return the top element and decrement top
}
// Function to peek at the top element of the stack
int peek() {
if (isEmpty()) {
cout << "Stack is empty. No element to peek." << endl;
return -1; // Return -1 to indicate empty stack
}
return arr[top]; // Return the top element
}
// Function to check if the stack is empty
bool isEmpty() {
return top == -1; // If top is -1, stack is empty
}
};
int main() {
Stack stack;
stack.push(5);
stack.push(10);
stack.push(15);
cout << "Top element: " << stack.peek() << endl;
cout << "Popped element: " << stack.pop() << endl;
cout << "Top element after pop: " << stack.peek() << endl;
return 0;
}