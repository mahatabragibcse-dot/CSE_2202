#include<bits/stdc++.h>
using namespace std;

string s1, s2;

string LCS()
{
    int n = s1.size();
    int m = s2.size();
    int arr[1001][1001];

    // Fill DP table
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(i == 0 || j == 0)
                arr[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                arr[i][j] = 1 + arr[i-1][j-1];
            else
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }

    // Reconstruct LCS string
    string s;
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            s += s1[i-1];
            i--; j--;
        }
        else if(arr[i-1][j] > arr[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(s.begin(), s.end());   // LCS is built backwards
    return s;
}

int main()
{
    cin >> s1 >> s2;
    cout << LCS() << endl;
}
