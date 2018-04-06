
#include<iostream>
#include<stdlib.h>

//#include<stdio>
//#include<conio>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int cp[10],time_quantum,wait_time=0,turnaround_time=0,total_time=0;
int **a,n,tat=0,*rt,q1[10],q2[10],q3[10],q4[10],rear1,rear2,front1=0,front2=0,q5[10],front3=0,rear3=0,priority[10];
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
for(int j=0;j<2;j++)
{
 if(j==0)
cout<<"Enter arrival time for process-   "<<i+1<<"  ";
else
cout<<"Enter burst time for process-     "<<i+1<<"  ";
cin>>a[i][j];
cout<<endl;
}
q3[l++]=i;
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
priority[q3[i]]=0;
total_time+=a[q3[0]][1]+a[q3[0]][2];
for(int i=1;i<n;i++)
{
if(a[q3[i]][1]>total_time)
total_time=a[q3[i]][1];
total_time+=a[q3[i]][2];
}
int time,count,remain=n,flag=0;
time_quantum=1;
for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      //printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
	  cout<<count+1<<"		"<<time-a[count][1]<<"		"<<time-a[count][1]-a[count][2]<<endl ;
      wait_time +=time-a[count][1]-a[count][2]; 
      turnaround_time+=time-a[count][1]; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(a[count+1][1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
}
