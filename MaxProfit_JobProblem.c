/*
Given an array of jobs where every job has a deadline and 
associated profit if the job is finished before the deadline.
It is also given that every job takes single unit of time, 
so the minimum possible deadline for any job is 1. How to
maximize total profit if only one job can be scheduled at a time.
*/
#include <stdio.h>
void MaxProfit(int ,int [],int []);
void swap(int * ,int *);
void Sort(int ,int[],int []);
int main() 
{
	int T;
	//T is no of test case
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
	    int n;
	    // There exist n different kind of Job's.
	    scanf("%d",&n);
	    int Deadline[n],Profit[n],jobID;
	    for(int i=0;i<n;i++)
	        scanf("%d%d%d",&jobID,&Deadline[i],&Profit[i]);
	    MaxProfit(n,Deadline,Profit);
	}
	return 0;
}

void MaxProfit(int n,int Deadline[],int Profit[])
{
    Sort(n,Deadline,Profit);
    int temp[100],ProValue=0,maxJob=0;
    for(int i=0;i<100;i++)
      temp[i]=0;
      
    for(int i=0;i<n;i++)
    {
        int a=Deadline[i]-1;
        for(int j=a;j>=0;j--)
        {
           if(temp[j]==0)
           {
               temp[j]=1;
               ProValue=ProValue+Profit[i];
               maxJob=maxJob+1;
               break;
           }
        }
       
    }
    
    printf("Max job he can do : %d\n Maximum Profit He/She can get :  %d\n",maxJob,ProValue);
    return ;
}
// at place of O(N*N) algorithem we can you any other algorithem for sorting.
void Sort(int n,int Deadline[],int Profit[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Profit[i]>Profit[j])
            {
               swap(&Profit[i],&Profit[j]);
               swap(&Deadline[i],&Deadline[j]);
            }
        }
    }
    return 0;
}
void swap(int * a ,int * b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
    return ;
}
