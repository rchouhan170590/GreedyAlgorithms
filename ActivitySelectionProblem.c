/*
You are given n activities with their start and finish times.
Select the maximum number of activities that can be performed
by a single person, assuming that a person can only
work on a single activity at a time.
*/
#include <stdio.h>
void MaxActivity(int [],int [],int);
void Sort(int [],int [],int,int []);
void swap(int*,int*);
int main() 
{
    int T;     // T is the total no. of cases
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int size;
        scanf("%d",&size);
        int S[size],F[size];
        for(int k=0;k<size;k++)
          scanf("%d",&S[k]);
        for(int k=0;k<size;k++)
           scanf("%d",&F[k]);
        MaxActivity(S,F,size);
    }
	return 0;
}
void MaxActivity(int S[],int F[],int size)
{
    int Index[size];  // which store the activity no. 
    for(int i=0;i<size;i++)
       Index[i]=i+1;
    Sort(S,F,size,Index);
    printf("%d ",Index[0]);
    int Finish=F[0];
    for(int i=1;i<size;i++)
    {
        if(S[i]>=Finish)
        {
            printf("%d ",Index[i]);
            Finish=F[i];
        }
    }  
    printf("\n");
    return ;    
}
// for sorting you can use O(nlogn) algo. 
void Sort(int S[],int F[],int size,int Index[])
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(F[j]>F[i])
            {   swap(&Index[i],&Index[j]);
                swap(&F[i],&F[j]);
                swap(&S[i],&S[j]);
            }
        }
    }
    return;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
