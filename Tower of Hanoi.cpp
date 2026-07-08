// You are using GCC
#include <iostream>
using namespace std;

void TOH(int rings,char src,char aux,char dest){
    if(rings==0) return;
    TOH(rings-1,src,dest,aux);
    cout << "Move disk " << rings << " from rod " << src << " to " << dest << endl;
    TOH(rings-1,aux,src,dest);
}

int main(){
    int rings;
    cin >> rings;
    TOH(rings,'S','A','D');
}
