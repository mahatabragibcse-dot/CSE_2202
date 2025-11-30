#include<bits/stdc++.h>
using namespace std ;


struct job{
int id , profit , dead ;
};



bool cmp(job a , job b)
{
    return a.profit > b.profit ;
}


int main()
{
    int n ; cin >> n ;
    vector<job> jobs(n) ;


    int max_dead = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> jobs[i].id >> jobs[i].profit >> jobs[i].dead ;
        max_dead = max(max_dead, jobs[i].dead) ;
    }

  sort(jobs.begin(),jobs.end(),cmp) ;

  vector<int>slot(max_dead+1 , -1);


  int count_job = 0 , max_profit = 0 ;
  for(auto &j : jobs)
  {
      for(int t = j.dead ; t > 0 ; t--)
        if(slot[t] == -1)
      {
          slot[t] = j.id ;
          count_job++ ;
          max_profit += j.profit ;
          break ;
      }
  }

   cout << "total job done = "  << count_job << " and total maximum profit = " << max_profit << endl ;
   cout << "job sequence = " ;
   for(int i = 1 ; i < max_dead+1 ; i++)
    if(slot[i] != -1)
    cout << slot[i] << " " ;
   cout << endl ;
}
