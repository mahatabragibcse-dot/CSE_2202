#include<bits/stdc++.h>
using namespace std ;
struct activity{
int start,ed ;
};

bool cmp(activity a , activity b)
{
    return a.ed < b.ed ;
}
int main()
{
    int n ; cin >> n ;
    vector<activity> activities(n) ;

    for(int i = 0 ; i < n ; i++)
        cin >> activities[i].start >> activities[i].ed ;

    sort(activities.begin(), activities.end(),cmp) ;

    int last_ed = activities[0].ed ;
    int total = 1 ;
    cout << activities[0].start << " -> " << activities[0].ed << endl ;
    for(int i = 1 ; i < n ; i++)
    {
        if(activities[i].start >= last_ed )
        {
            cout << activities[i].start << " -> " << activities[i].ed << endl ;
            last_ed = activities[i].ed ;
            total++ ;
        }
    }
    cout << total << endl ;


}
