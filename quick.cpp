#include <iostream>
u#include <iostream>
u#include <iostream>
using namespace std;
#include <omp.h>

void swap(int *a,int *b)
{
        int t=*a;
        *a=*b;
        *b=t;
}

void print(int a[],int n)
{
        for(int i=0;i<n;i++)
        {
                cout<<a[i]<<" ";
        }
}

int  partition(int a[],int l,int h)
{
        int pos=0,i,j,pivot;
        pivot=a[h];
        i=l-1;
        for(j=l;j<=h-1;j++)
        {
                if(a[j]<=pivot)
                {
                        i++;
                        swap(&a[j],&a[i]);
                }

        }
        pos=i+1;
        swap(&a[i+1],&a[h]);

        return pos;
}

void quicksort(int a[],int l,int h)
{
        if(l<h)
        {
                int p=partition(a,l,h);
                #pragma omp task firstprivate(a,l,p)
                {
                        quicksort(a,l, p - 1);

                }

                {
                        quicksort(a, p + 1, h);

                }
        }
}

int main()
{

int a[]={1,70,34,200,-8,0},n=6;
#pragma omp single nowait


         quicksort(a, 0, n-1);

print(a,n);

        return 0;
}

