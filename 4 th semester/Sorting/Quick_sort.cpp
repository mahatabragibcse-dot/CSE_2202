#include<bits/stdc++.h>
using namespace std ;
int partation(int arr[],int st,int end)
{
    int idx = st-1 ,pivot = arr[end] ;
    for(int j = st ; j < end ; j++)
    {
        if(arr[j] <= pivot)
        {
            idx++ ;
            int t = arr[idx] ;
            arr[idx] = arr[j] ;
            arr[j] = t ;
        }
    }
    idx++ ;
            int t = arr[idx] ;
            arr[idx] = arr[end] ;
            arr[end] = t ;
            return idx ;
}


void quick_sort(int arr[],int st,int end)
{
    if(st < end)
    {
       int pivIdx =  partation(arr,st,end) ;
       quick_sort(arr,st,pivIdx-1) ;
       quick_sort(arr,pivIdx+1,end) ;
    }
}





int main()
{
    int n ; cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; i++)
    cin >> arr[i] ;
    quick_sort(arr,0,n-1) ;
    for(int  i = 0 ; i < n ; i++)
    cout << arr[i] << " ";
}

