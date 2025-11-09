#include<bits/stdc++.h>
using namespace std ;

bool linear_search(int arr[],int n,int v)
{
   for(int i = 0 ; i < n ; i++)
   {
       if(arr[i] == v)
        return true ;
   }
   return false ;
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
    if(linear_search(arr,n,v))
        cout << "Found\n" ;
    else
        cout << "Not Find\n" ;

}
