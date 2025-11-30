#include<bits/stdc++.h>
using namespace std ;

int max_cross(vector<int> &arr , int l , int m , int r)
{
    ///left max_sum
    int left_sum = INT_MIN , sum = 0 ;
    for(int i = m ; i >= l ; i--)
    {
        sum += arr[i] ;
        left_sum = max(left_sum, sum) ;
    }
    ///right max_sum ;
    int right_sum = INT_MIN ;
    sum = 0 ;
    for(int i = m+1 ; i <= r ; i++)
    {
        sum += arr[i] ;
        right_sum = max(right_sum , sum) ;
    }
    return left_sum + right_sum ;
}


int max_subarray(vector<int> &arr , int l , int r)
{
    if(l == r)
        return arr[l] ;
    int m = (l+r)/2 ;
    int left = max_subarray(arr,l,m);
    int right = max_subarray(arr,m+1, r) ;
    int cross = max_cross(arr,l,m,r) ;

    return max({left,right , cross}) ;
}
int main()
{
    int n ;
    cin >> n ;
    vector<int> arr(n) ;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
    cout << "Maximum Subarray Sum = " << max_subarray(arr,0,n-1) << endl ;
}
