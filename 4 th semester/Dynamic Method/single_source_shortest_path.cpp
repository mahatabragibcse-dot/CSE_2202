#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m; // number of vertices and edges
    vector<Edge> edges(m);

    for(int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    int source;
    cin >> source;

    const int INF = 1e9;
    vector<int> dp(n, INF);
    dp[source] = 0;

    // Relax edges n-1 times
    for(int i = 0; i < n-1; i++) {
        for(auto e : edges) {
            if(dp[e.u] + e.w < dp[e.v]) {
                dp[e.v] = dp[e.u] + e.w;
            }
        }
    }

    // Output shortest distances
    for(int i = 0; i < n; i++) {
        if(dp[i] == INF) cout << "INF ";
        else cout << dp[i] << " ";
    }
}

