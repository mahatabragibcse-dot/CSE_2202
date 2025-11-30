#include<bits/stdc++.h>
using namespace std ;
void LCS(vector<vector<int>> &arr , string s1 , string s2)
{
    int n = s1.size();
    int m = s2.size() ;
    for(int i = 0 ; i <= n ; i++)
        for(int j = 0 ; j <= m ; j++)
    {
        if(i == 0 || j == 0)
            arr[i][j] = 0 ;
        else if(s1[i-1] == s2[j-1])
            arr[i][j] = 1+arr[i-1][j-1] ;
        else
            arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
    }
    cout << "Longest common subsequence size = " << arr[n][m] << endl ;



    string s;
    int i = n , j = m ;
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1]){
            s+=s1[i-1] ;
            i-- ; j-- ;
            }
        else if(arr[i-1][j] > arr[i][j-1] )
            i-- ;
        else
            j-- ;

    }
    reverse(s.begin(),s.end()) ;
    cout << s << endl ;
}
int main()
{
    string s1,s2 ;
    cin >> s1 >> s2 ;
    vector<vector<int>> arr(s1.size()+1 , vector<int>(s2.size() + 1)) ;
    LCS(arr,s1,s2) ;
}
