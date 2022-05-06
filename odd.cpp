#include <iostream>
using namespace std;
#include <omp.h>

int main()
{
int a[]={5,4,3,2,7,8},temp,t1,i;
bool sort=false;

#pragma omp parallel
        while(!sort)
        {
                sort=true;
                for(int i=1;i<=4;i+=2)
                {
                        if(a[i]>a[i+1])
                        {
                                sort=false;
                                t1=a[i];
                                a[i]=a[i+1];
                                a[i+1]=t1;
                        }
                }
                for(int i=0;i<=4;i+=2)
                {
                        if(a[i]>a[i+1])
                        {
                                sort=false;
                                t1=a[i];
                                a[i]=a[i+1];
                                a[i+1]=t1;
                        }
                }

        }
for(i=0;i<6;i++)
        cout<<a[i]<<" ";
return 0;
}

