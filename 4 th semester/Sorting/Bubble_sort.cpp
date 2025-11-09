#include<bits/stdc++.h>
using namespace std ;


void bubble_sort(int arr[], int n)
{
   for(int i = 0 ; i < n ; i++)
   {
       int f = 0 ;
       for(int j = 0 ; j < n-i-1 ; j++)
       {
           if(arr[j] > arr[j+1])
           {
               int t = arr[j] ;
               arr[j] = arr[j+1] ;
               arr[j+1] = t ;
               f++ ;
           }
       }
       if(f == 0)
        break ;
   }
}


int main()
{
    int n ; cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
    bubble_sort(arr,n) ;
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " ";

}
