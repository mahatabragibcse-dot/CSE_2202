#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int n ; cin >> n ;
    vector<vector<int>> cost(n, vector<int>(n)) ;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
         cin >> cost[i][j] ;

    int N = 1 << n ;
    int const inf = 1e9 ;
    vector<vector<int>> dp(N ,vector<int> (n,inf)) ;
    dp[1][0] = 0 ;


    for(int mask = 1 ; mask < N ; mask++)
        for(int i = 0 ; i < n ; i++)
          if(mask & (1 << i))
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(i != j && (mask & (1 << j)))
            {
                int prevMask = mask ^ (1 << i) ;
                dp[mask][i] = min(dp[mask][i] , dp[prevMask][j]+cost[j][i]) ;
            }
        }
    }

    int ans = inf ;
    for(int i = 0 ; i < n ; i++)
    {
        ans = min(ans, dp[N-1][i] + cost[i][0] ) ;

    }
    cout << "Minimum TSP cost = " << ans << "\n";
}
