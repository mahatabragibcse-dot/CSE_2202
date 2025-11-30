#include<bits/stdc++.h>
using namespace std ;

vector<int> min_max(const vector<int> &arr , int l , int r)
{
    vector<int> result(2) ;
    if(l == r){
        result[0] = arr[l];
        result[1] = arr[l];
        return result;
    }

    if(r == l+1)
    {
        if(arr[r] > arr[l])
        {
            result[0] = arr[l] ;
            result[1] = arr[r] ;
        }
        else
        {
            result[1] = arr[l] ;
            result[0] = arr[r] ;
        }

        return result ;
    }

    int mid = (l+r)/2 ;

    vector<int> left = min_max(arr,l,mid) ;
    vector<int> right = min_max(arr,mid+1,r) ;

    result[0] = min(left[0],right[0]) ;
    result[1] = max(left[1],right[1]) ;

    return result ;
}
int main()
{
    int n ; cin >> n ;
    vector<int>arr(n) ;
    for(int i = 0  ;i < n ; i++)
        cin >> arr[i] ;

    auto it = min_max(arr,0,n-1) ;
    cout << it[0] << " " << it[1] << endl ;
}
