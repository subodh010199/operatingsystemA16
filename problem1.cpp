
#include<iostream>
#include<stdlib.h>

//#include<stdio>
//#include<conio>
using namespace std;
class queue
{
              int queue1[5];
              int rear,front;
      public:
              queue()
                {
                     rear=-1;
                     front=-1;
                }
              void insert(int x)
               {
                   if(rear >  4)
                    {
                       cout <<"queue over flow";
                       front=rear=-1;
                       return;
                    }
                    queue1[++rear]=x;
               }
              int delet()
               {
                   if(front==rear)
                     {
                         return 0;
                     }
                    else return queue1[++front];
                }
              
};
int main(){
queue student,teachers;
int cp[10],time_quantum=5,wait_time=0,turnaround_time=0;
int **a,n,tat=0,*rt;
cout<<"Enter no of processes.";
cin>>n;
a=new int*[n];
rt=new int[n];
for(int i=0;i<n;i++){
	a[i]=new int[3];
}
cout<<"Enter 0 for student query and 1 for teachers query. "<<endl;
for(int i=0;i<n;i++)
{
for(int j=0;j<3;j++)
{
	if(a[0][0]==1)
	teachers.insert(i);
	else
	student.insert(i);
if(j==0)
cout<<"Enter query status for process "<<i+1<<"  ";
else if(j==1)
cout<<"Enter arrival time for process  "<<i+1<<"  ";
else
cout<<"Enter burst time for process  "<<i+1<<"  ";
cin>>a[i][j];
rt[i]=a[i][2];
}
cout<<endl;
}
for(int i=0;i<n;i++)
tat=tat+a[i][2];
int time,count,remain=n,flag=0;
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
      cout<<count+1<<"   "<<time-a[count][1]<<"    "<<time-a[count][1]-a[count][2]<<endl;
      //("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]); 
      wait_time+=time-a[count][1]-a[count][2]; 
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
}




