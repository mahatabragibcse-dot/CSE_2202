#include<bits/stdc++.h>
using namespace std ;
void merge(int arr[],int st , int mid , int end)
{
    vector<int> t ;

    int i = st , j = mid+1 ;
    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j]){
        t.push_back(arr[i]);
        i++ ;
        }
        else
        {
        t.push_back(arr[j]);
        j++ ;
        }
    }
    while(i <= mid)
    {
        t.push_back(arr[i]);
        i++;
    }
    while(j <= end)
    {
        t.push_back(arr[j]);
        j++;
    }

    for(int k = 0 ; k < t.size() ; k++)
    {
        arr[k+st] = t[k] ;
    }
}


void merge_sort(int arr[],int st,int end)
{
    if(st < end)
    {
        int mid = (st+end)/2 ;

        merge_sort(arr,st,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,st,mid,end) ;
    }
}





int main()
{
    int n ; cin >> n ;
    int arr[n] ;
    for(int i = 0 ; i < n ; i++)
    cin >> arr[i] ;
    merge_sort(arr,0,n-1) ;
    for(int  i = 0 ; i < n ; i++)
    cout << arr[i] << " ";
}
