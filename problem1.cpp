
#include<iostream>
#include<queue>
//#include<stdio>
//#include<conio>
using namespace std;
int main(){
queue <int> st,t;

int **a,n;
cout<<"Enter no of processes.";
cin>>n;
a=new int*[n];
for(int i=0;i<n;i++){
	a[i]=new int[4];
}
cout<<"Enter 0 for student query and 1 for teachers query. "<<endl;
for(int i=0;i<n;i++)
{
for(int j=0;j<4;j++)
{
if(j==0)
cout<<"Enter query status for process "<<i+1;
cin>>a[i][j];
}
cout<<endl;
}
for(int i=0;i<n;i++)
{
	if(a[i][0]==0)
	st.push(i);
	else
	t.push(i);
}
for(int i=0;i<n;i++)
{
for(int j=0;j<4;j++)
cout<<a[i][j]<<"      ";
cout<<endl;
}
/*for(int i=0;i<st.size();i++)
cout<<st.pop();
for(int i=0;i<t.size();i++)
cout<<t.pop();*/
}


