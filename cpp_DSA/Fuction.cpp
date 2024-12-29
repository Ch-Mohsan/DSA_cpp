#include <iostream>
using namespace std;

double  f(double x){
return 2*x+6;
}
double sum(double(*f)(double), int m, int n) {
    double res = 0;
    for (int i = n; i <= m; i++) {
        res = res + f(i);
        cout << res << " ";
    }
    return res;
}



int main(){
sum(f,2,1);
return 0;
}
