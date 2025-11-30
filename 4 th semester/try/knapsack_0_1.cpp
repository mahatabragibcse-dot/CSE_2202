#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n , W ;
    cin >> n >> W ;
    vector<int> wt(n), p(n) ;


    ///input ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> wt[i] >> p[i] ;
    }


    ///create dp table ; 1 based indexing;
    vector<vector<int>> dp(n+1 , vector<int> (W+1 ,0)) ;
    for(int i = 1 ; i <= n ; i++)
        for(int w = 1 ; w <= W ; w++)
    {
        if(w >= wt[i-1])
            dp[i][w] = max(dp[i-1][w] , dp[i-1][w-wt[i-1]]+p[i-1]) ;
        else
            dp[i][w] = dp[i-1][w] ;

    }

    cout << "Maxprofit = " << dp[n][W] << endl ;



    ///show taken iteam ;
    int w = W ;
    vector<int>taken ;
    for(int i = n ; i > 0 ; i-- )
    {
        if(dp[i-1][w] != dp[i][w])
        {
            taken.push_back(i) ;
            w = w-wt[i-1] ;
        }
        if(w == 0)
            break ;
    }
    reverse(taken.begin(),taken.end()) ;
    for(auto &it : taken)
        cout << it << " " ;
    cout << endl ;
}
