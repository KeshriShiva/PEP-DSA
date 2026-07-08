#include<iostream>
using namespace std;

int binarySearch(int arr[],int low,int high){
		int low=0;
	int high=n-1;
	while(high>=l){
		int mid=low*(high-l)/2;
		if(arr[mid]==s){
			return mid;
		}
		if(arr[mid]==s){
			high=mid-1;
		}
		else{
			low=mid-1;
		}
	}
}
int deleteElement(int arr[],int n,int key){
	int pos = binarySearch(arr,0,n-1,key);
	if(pos== -1){
		cout<<"Element not found"<<endl;
		return -1;
	}
	int i;
	for(i=pos;i<n-1;i++){
		return n-1;
	}
}
int main(){
	int arr[]={1,2,3,4,5}
}
