#include <iostream>
using  namespace std;

void swap(int &a, int &b){
     int temp = a;
     a=b;
     b=temp;
}
void bubbleSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
               swap(arr[j],arr[j+1]);
            }
        }
    }
}
void selectionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i+1;i<size;i++){
            if(arr[min]>arr[j]) min=i;
        }
        swap(arr[min],arr[i]);
    }
}
int main(){
    int s;
    cin >> s;
    int ar[s];
    for(int i=0;i<s;i++) cin >> ar[i];
    cout << "Unsorted: " << endl;
    for(int i=0;i<s;i++) cout << ar[i] << " ";
    selectionSort(ar,s);
    cout << endl;
    cout << "Sorted: " << endl;
    for(int i=0;i<s;i++) cout << ar[i] << " ";
}
