#include<bits/stdc++.h>
using namespace std;

int main(){
	ofstream fout;
	fout.open("D:\\File\\country.txt");
	fout<<"India"<<endl;
	fout<<"USA"<<endl;
	fout<<"UK"<<endl;
	fout.close();
	fout.open("D:\\File\\capital.txt");
	fout<<"Delhi"<<endl;
	fout<<"Washington"<<endl;
	fout<<"London"<<endl;
	fout.close();
	const int n=80;
	char s[n];
	ifstream fin;
	fin.open("D:\\File\\country.txt");
	while(fin){
		fin.getline(s,n);
		cout<<s<<endl;
	}
	fin.close();
	cout<<"!Done";
	return 0;
}
