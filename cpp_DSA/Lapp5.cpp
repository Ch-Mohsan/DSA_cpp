#include <iostream>
#include<stack>
#include<cstdlib>
#include<cctype> // isdigit
using namespace std;
int EvaluatePostfix(string & expression)
{
stack<int> s;
int op1, op2;
for(int i=0; i<expression.length(); i++){
char c=expression[i];
if(isdigit(c))
{
s.push(c-'0');
}
else
if (c==' ')
{
/* code */
}
else{
op1=s.top();
s.pop();
op2=s.top();
s.pop();
switch (c)
{
case '+' :
s.push(op1+op2);
cout<<"\n"<<op1+op2;
/* code */
break;
case '-':
s.push(op1-op2);
break;
case '*':
s.push(op1*op2);
cout<<"\n"<<op1+op2;
break;
case '/':
s.push(op1/op2);
default:
cout<<"invaid expression";
break;
}
}
}
if (s.size()==1)
{
return s.top();/* code */
}
else
{
cout<<"invalid expression";
return ;
}
}
int main(){
string a="12+3*";
cout<<EvaluatePostfix(a);
return 1;
}