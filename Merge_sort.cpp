
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int list[MAX_SIZE];
int n;

void print_list(int list[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",list[i]);
}
void selection_sort(int list[],int n)
{
    int i,j,least,temp;
    for(i=0;i<n;i++)
    {
        least=i;
        for(j=i+1;j<n;j++)
        {
            if(list[least]>list[j])
                least=j;
        }
        SWAP(list[i],list[least],temp);
    }
}

void insertion_sort(int list[],int n)
{
    int key,tem;
    for(int i=1;i<n;i++)
    {
        key=list[i];
        for(int j=i-1;j>=0;j--)
        {
            if(key<list[j])
            {
                tem=list[j];
                list[j]=list[j+1];
                list[j+1]=tem;
            }
        }
        print_list(list,n);
        printf("\n");
    }
}

void bubble_sort(int list[],int n)
{
    int tem;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(list[i]>list[j])
            {
                tem=list[j];
                list[j]=list[i];
                list[i]=tem;
            }
        }
    }
}

void inc_insertion_sort(int list[],int first,int last,int gap)
{
    int i,j,key;
    for(i=first;i<=last;i=i+gap)
    {
        key=list[i];
        for(j=i-gap;j>=first&&key<list[j];j=j-gap)
            list[j+gap]=list[j];
        list[j+gap]=key;
    }
}

void shell_sort(int list[],int n)
{
    int i,gap;
    for(gap=n/2;gap>0;gap=gap/2)
    {
        if(gap%2==0) gap++;
        for(i=0;i<gap;i++)
            inc_insertion_sort(list,i,n-1,gap);
    }
}

int sorted[MAX_SIZE];

void Merge(int list[],int left,int mid,int right)
{

    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;
    while(i<=mid && j<=right)
    {
        if(list[i]<=list[j])
        {
            sorted[k]=list[i];
            i++;
        }
        else
        {
            sorted[k]=list[j];
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        for(l=j;l<=right;l++)
            sorted[k++]=list[l];
    }
    else
    {
        for(l=i;l<=mid;l++)
            sorted[k++]=list[l];
    }

    for(l=left;l<=right;l++)
        list[l]=sorted[l];

}

void Merge_sort(int list[],int left,int right)
{
    int mid;

    if(left<right)
    {

        mid=(left+right)/2;
        printf("*%d %d %d\n", left, mid, right);
        Merge_sort(list,left,mid);

        Merge_sort(list,mid+1,right);
        printf("#%d %d %d\n", left, mid, right);
        Merge(list,left,mid,right);
    }
}

int main(void)
{
    int i;
    n=MAX_SIZE;
    srand(time(NULL));
    for(i=0;i<n;i++)
        list[i]=rand()%100;
    print_list(list,n);
    printf("\n");
    //selection_sort(list,n);
    //insertion_sort(list,n);
    //bubble_sort(list,n);
    //shell_sort(list,n);
    Merge_sort(list,0,n-1);

    print_list(list,n);
    return 0;
}
