#include<stdio.h>
#include<iostream>
#include<omp.h>
#include<time.h>

using namespace std;

void serial_bubble_sort(int arr[], int n)
{
        clock_t start = clock();
        int i,j;
        for(i=0; i<n-1; i++)
        {
                for(j=0; j<n; j++)
                {
                        if(arr[j] > arr[j+1])
                        {
                                int temp;
                                temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                        }
                }
        }

        double duration = (double)(clock() - start)/CLOCKS_PER_SEC;
        cout<<"\nExecution duration:\t:"<<duration;

        cout<<"\nFinal array after sorting is \n";
        for(i=0; i<n; i++)
        {
                cout<<arr[i]<<"\t";
        }
}

void parallel_bubble_sort(int arr[], int n)
{
        int i,j;
        //double start_time, end_time;
	clock_t start_time = clock();

        #pragma omp parallel for
        for(i=0; i<n-1; i++)
        {
                for(j=0; j<n; j++)
                {
                        if(arr[j] > arr[j+1])
                        {
                                int temp;
                                temp = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = temp;
                        }
                }
        }

        double duration = (double)(clock() - start_time)/CLOCKS_PER_SEC;
        cout<<"\nParallel algorithm:\n";
        //cout<<"\nStart time: \t"<<start_time<<"\n";
	//cout<<"\nEnd time: \t"<<end_time<<"\n";
        cout<<"\nDuration: \t"<<duration;

        cout<<"\nFinal array after sorting is \n";
        for(i=0; i<n; i++)
        {
                cout<<arr[i]<<"\t";
        }

}

int main()
{
        int arr[] = {54,3,31,2,12,5,67,7,87,89,86,95,90};
        int n;
        n = sizeof(arr)/sizeof(arr[0]);
        cout<<"\nSerial sorting:\n";
        serial_bubble_sort(arr,n);
        cout<<"\nParallel sorting:\n";
        parallel_bubble_sort(arr,n);
	  return 0;
}
