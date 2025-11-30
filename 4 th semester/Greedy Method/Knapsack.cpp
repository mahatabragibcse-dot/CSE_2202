#include<bits/stdc++.h>
using namespace std ;
struct Item{
double profit , weight ,p_w_ratio ;
};


bool cmp(Item a, Item b)
{
    return a.p_w_ratio > b.p_w_ratio ;
}



double Knapsack(int W, Item arr[] , int n)
{
    sort(arr,arr+n,cmp) ;///sort object ;
    double total_profit = 0.0;
    for(int i = 0 ; i < n ; i++)
    {

        if(W > 0 && W >= arr[i].weight){
            W = W-arr[i].weight ;
            total_profit += arr[i].profit ;
         }

         else
         {
           total_profit += arr[i].p_w_ratio*W;
           break ;
         }
    }
    return total_profit ;

}
int main()
{
  int W ;
  int n ;
  cout << "Enter total capacity and item number : " ;
  cin >> W >> n ;
  Item arr[n] ;
  cout << "Enter item profit and weight :\n" ;
  for(int i = 0 ; i < n ; i++)
  {
      cin >> arr[i].profit >> arr[i].weight ;
      arr[i].p_w_ratio = arr[i].profit/arr[i].weight ; /// find p/w ratio ;
  }

  cout << "Maximum Profit = " << Knapsack(W,arr,n) << endl ;

}
