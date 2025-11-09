#include<bits/stdc++.h>
using namespace std ;

bool binary_search(int arr[],int ub,int v,int lb)
{
   int mid = ub+(ub-lb)/2 ;
   if(arr[mid] == v)
    return true  ;
   if(lb > ub)
    return false ;
   if(arr[mid] < v)
   {
     return binary_search(arr,ub,v,mid+1);
   }
   else
   {
     return binary_search(arr,mid-1,v,lb);
   }
}
int main()
{
    int n ; cin >> n ;
    int arr[n] ;
    cout << "Enter Find value = " ;
    int v ;
    cin >> v ;
    for(int i = 0 ; i < n ; i++)
        cin >>arr[i] ;
    if(binary_search(arr,n,v,0))
        cout << "Found\n" ;
    else
        cout << "Not Find\n" ;

}
