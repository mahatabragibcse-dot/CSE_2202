#include<bits/stdc++.h>
using namespace std ;
const int inf = 1e9;
int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<vector<int>> C(n , vector<int>(n,inf)) ;

    /// fill diagonal = 0 ;
    for(int i = 0 ; i < n ; i++)
        C[i][i] = 0 ;

    ///fill others;
    for(int i = 0 ; i < m ; i++)
    {
        int u , v ,w ;
        cin >> u >> v >> w ;
        C[u][v] = w ;
    }
    ///make shortest path ;
    for(int k = 0 ; k < n ; k++)
        for(int i = 0 ;i < n ; i++)
         for(int j = 0 ; j < n ; j++)
           if(C[i][k] < inf && C[k][j] < inf)
            C[i][j] = min(C[i][j],C[i][k]+C[k][j]) ;

 ///output ;

 for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++)
 {
     if(C[i][j] == inf)
        cout << "inf " ;
     else
        cout << C[i][j] << " " ;
 }
 cout << endl ;}

}
