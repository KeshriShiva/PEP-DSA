// You are using GCC
#include <iostream>
using namespace std;

int power(int a,int b){
    if(b==0) return 1;
    return a*power(a,b-1);
}

int binary(int deci){
    if(deci==0) return 0;
    return deci%2+10*binary(deci/2);
}
void print(int n){
    if(n==0) return;
    cout << n << " ";
    print(n-1);
}

int main(){
    cout << power(2,3) << " " << binary(5) << endl;
    print(5);
}
