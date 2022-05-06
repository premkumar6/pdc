#include<stdio.h>
#include<omp.h>

int main()
{

int a[]={5,4,3,2,1},c[5],b[5];
#pragma omp parallel for
        for(int i=0;i<5;i++)
        {
                c[i]=0;
                for(int j=0;j<5;j++)
                {
                        if((a[i]>a[j])||(i<j && a[i]==a[j]))
                                c[i]+=1;
                        else
                                c[i]+=0;
                }
                b[c[i]]=a[i];
        }
for(int i=0;i<5;i++)
        printf(" %d\n", i, b[i]);
return 0;
}




