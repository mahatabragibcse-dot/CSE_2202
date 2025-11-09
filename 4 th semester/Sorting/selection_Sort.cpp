#include<bits/stdc++.h>
using namespace std ;

void Selection_Sort(int arr[],int n )

{
    for(int i = 0 ; i < n ; i++)
    {
        int min_idx = i ;
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j ;
            }
        }
        swap(arr[i] , arr[min_idx]) ;
    }
}

void swap(int *a , int *b)
{
    int t = *a ;
    *a = *b ;
    *b = t;
}
int main()
{
    int n ; cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
    Selection_Sort(arr,n);

    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " " ;
}
