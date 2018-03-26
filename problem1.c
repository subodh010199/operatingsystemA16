
#include<iostream>
//#include<stdio>
//#include<conio>
using namespace std;
int main(){
int **a,n;
cout<<"Enter no of processes.";
cin>>n;
a=new int*[n];
for(int i=0;i<n;i++){
	a[i]=int new[3];
}
for(int i=0;i<n;i++)
{
for(int j=0;j<3;j++)
cin>>a[i][j]<<"      ";
cout<<endl;
}
for(int i=0;i<n;i++)
{
for(int j=0;j<3;j++)
cout<<a[i][j]<<"      ";
cout<<endl;
}

}
