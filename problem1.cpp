

#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int cp[10],time_quantum,wait_time=0,turnaround_time=0,total_time=0;
int **a,n,tat=0,*rt,q1[10],q2[10],q3[10],q4[10],rear1,rear2,front1=0,front2=0,q5[10],front3=0,rear3=0;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main(){
//int cp[10],time_quantum=5,wait_time=0,turnaround_time=0,total_time=0;
//int **a,n,tat=0,*rt,q1[10],q2[10],q3[10],q4[10],rear1,rear2,front1=0,front2=0;
cout<<"---------------FAIR SHARE ROUND ROBIN------------------"<<endl<<endl<<endl;
cout<<"Enter no of processes-   ";
cin>>n;
a=new int*[n];
rt=new int[n];
for(int i=0;i<n;i++){
	a[i]=new int[3];
}
int k=0,m=0,l=0,temp,o=0;
cout<<"Enter 0 for student query and 1 for teachers query. "<<endl;
for(int i=0;i<n;i++)
{
for(int j=0;j<3;j++)
{
if(j==0)
cout<<"Enter query status for process-   "<<i+1<<"  ";
else if(j==1)
cout<<"Enter arrival time for process-   "<<i+1<<"  ";
else
cout<<"Enter burst time for process-     "<<i+1<<"  ";
cin>>a[i][j];
cout<<endl;
}
q3[l++]=i;
/*if(a[i][0]==0)
q1[k++]=i;
else if(a[i][0]==1)
q2[m++]=i;
cout<<endl;*/
}
//q4.sort();
for(int i=0;i<n;i++)
q4[i]=a[i][1];
for(int i=0;i<n;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(q4[j+1]<q4[j])
{
	swap(&q4[j],&q4[j+1]);
	swap(&q3[j],&q3[j+1]);
}

}
}
for(int i=0;i<n;i++)
{
	if(a[q3[i]][0]==0)
	q1[k++]=q3[i];
	else if(a[q3[i]][0]==1)
	q2[m++]=q3[i];
}
/*for(int i=0;i<n;i++)
{
	cout<<q3[i]<<endl;
}*/
/*for(int i=0;i<3;i++)
{
	cout<<q1[i]<<"   ";
	cout<<q2[i]<<"   ";
}*/
/*for(int i=0;i<n;i++)
cout<<q3[i]<<endl;*/
//for(int i=0;i<2;i++)
//{
total_time+=a[q3[0]][1]+a[q3[0]][2];
for(int i=1;i<n;i++)
{
if(a[q3[i]][1]>total_time)
total_time=a[q3[i]][1];
total_time+=a[q3[i]][2];
}
rear1=k;
rear2=m;
rt=new int[10];
for(int i=0;i<n;i++)
rt[i]=a[i][2];
int time_quantum1,time_quantum2;
if(k>0)
time_quantum1=60/k;
if(m>0)
 time_quantum2=60/m;
int time=0,count,remain1=k,flag=0,remain2=m;
time=a[q2[0]][1];
float ttat=0,twat=0;
cout<<"PRO"<<"	"<<"TAT"<<"	"<<"WT"<<endl;
for(int i=0;i<m;i++)
{
	time=time+(min(time_quantum2,a[q2[i]][2]));
	if(a[q2[i]][1]+a[q2[i]][2]<=time && a[q2[i]][2]<time_quantum2)
	{
	cout<<q2[i]+1<<"	"<<(max(a[q2[i]][1],time-(min(time_quantum2,a[q2[i]][2])))+a[q2[i]][2])-a[q2[i]][1]<<"		"<<((max(a[q2[i]][1],time-(min(time_quantum2,a[q2[i]][2])))+a[q2[i]][2])-a[q2[i]][1])-a[q2[i]][2]<<endl;
    ttat=ttat+(max(a[q2[i]][1],time-time_quantum2)+a[q2[i]][2])-a[q2[i]][1];
    twat=twat+((max(a[q2[i]][1],time-time_quantum2)+a[q2[i]][2])-a[q2[i]][1])-a[q2[i]][2];
	}
	else 
		cout<<q2[i]+1<<"		"<<"Process incompleted"<<endl;
}
for(int i=0;i<k;i++)
{
	time=time+(min(time_quantum1,a[q1[i]][1]));
	if(a[q1[i]][1]+a[q1[i]][2]<time && a[q1[i]][2]<time_quantum1)
	{
	cout<<q1[i]+1<<"	"<<(max(a[q1[i]][1],time-(min(time_quantum1,a[q1[i]][2])))+a[q1[i]][2])-a[q1[i]][1]<<"		"<<((max(a[q1[i]][1],time-(min(time_quantum1,a[q1[i]][2])))+a[q1[i]][2])-a[q1[i]][1])-a[q1[i]][2]<<endl;
	 ttat=ttat+(max(a[q1[i]][1],time-time_quantum1)+a[q1[i]][2])-a[q1[i]][1];
    twat=twat+((max(a[q1[i]][1],time-time_quantum1)+a[q1[i]][2])-a[q1[i]][1])-a[q1[i]][2];
}
	
	else 
		cout<<q1[i]+1<<"		"<<"Process incompleted"<<endl;
}
cout<<endl<<endl;
cout<<"Total TurnAround Time-"<<ttat<<endl;
cout<<"Total Waiting Time-"<<twat<<endl;
cout<<"Average TurnAroundTime Time-"<<ttat/3<<endl;
cout<<"Average Waiting Time-"<<twat/3;

}
