#include<iostream>
#include<omp.h>
#include<time.h>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
        int s1 = mid - left + 1;
        int s2 = right - mid;
        int *l = new int[s1];
        int *r = new int[s2];

        for(int i=0; i<s1; i++)
        {
                l[i] = arr[left + i];
        }

        for(int i=0; i<s2; i++)
        {
                r[i] = arr[mid + i + 1];
        }

        int index_l = 0, index_r = 0, index_merge = left;

        while(index_l < s1 && index_r < s2)
        {
                if(l[index_l] <= r[index_r])
                {
                        arr[index_merge] = l[index_l];
                        index_l++;
                }
                else
                {
                        arr[index_merge] = r[index_r];
                        index_r++;
                }
                index_merge++;
        }
        while(index_l < s1)
        {
                arr[index_merge] = l[index_l];
                index_l++;
                index_merge++;
        }

        while(index_r < s2)
        {
                arr[index_merge] = r[index_r];
                index_r++;
                index_merge++;
        }

}

void merge_sort(int arr[], int left, int right)
{
        if(left >= right)
        {
                return;
        }

        int mid = left + (right - left)/2;

        #pragma omp task shared(arr)
        merge_sort(arr, left, mid);

        #pragma omp task shared(arr)
        merge_sort(arr, mid+1, right);

        #pragma omp taskwait
        merge(arr, left, mid, right);
}

int main()
{
        int arr[] = {10,14,2,13,20,40,30,25};
        int n = sizeof(arr)/sizeof(arr[0]);

        clock_t start = clock();
        merge_sort(arr, 0, n-1);

        double duration = (double)(clock() - start)/CLOCKS_PER_SEC;
        cout<<"\nDuration:\t"<<duration;
        cout<<"\nAfter sorting:\n";

        for(int i=0; i<n; i++)
        {
                cout<<arr[i]<<"\t";
        }

        return 0;
}
