#include<bits/stdc++.h>
using namespace std ;

void Insrt_sort(int arr[] , int n)
{
    for(int i = 1 ; i < n ; i++)
    {
        int j = i-1 ;
        int key = arr[i] ;
        for(;j >= 0 && arr[j] > key; j--)
        {
           arr[j+1]  = arr[j] ;
        }
        arr[j+1] = key ;
    }
}
int main()
{
    int n ; cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    Insrt_sort(arr,n) ;
    for(int i = 0 ; i < n ; i++)
        cout << arr[i]<< " ";
}
