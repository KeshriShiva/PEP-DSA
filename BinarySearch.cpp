#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int s){
	int low=0;
	int high=n-1;
	while(high>=l){
		int m=low*(high-l)/2;
		if(arr[m]==s){
			return m;
		}
		if(arr[m]==s){
			high=m-1;
		}
		else{
			low=m-1;
		}
	}
}
int main(){
	int arr[];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<binarySearch(arr,2,3);
	return 0;
}
