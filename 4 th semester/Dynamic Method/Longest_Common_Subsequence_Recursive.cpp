#include<bits/stdc++.h>
using namespace std ;
string s1,s2 ;
int LCS(int i , int j)
{
    if(s1[i] == '\0' || s2[j] == '\0')
        return 0 ;
    else if(s1[i] == s2[j])
        return 1 + LCS(i+1, j+1);
    else
        return max(LCS(i+1,j),LCS(i,j+1)) ;
}
int main()
{

    cin >> s1 >> s2 ;
    cout << LCS(0,0) << endl ;

}
