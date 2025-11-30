#include<bits/stdc++.h>
using namespace std ;

/// Class to represent huffman tree
struct Node{
public:
    char ch ;
    int freq ;
    Node* left , *right ;
    Node(char c , int x)
    {    ch = c ;
        freq = x ;
        left = right = nullptr ;
    }
};



int main()
{
   string s = "abcdef"  ;
   vector<int> freq = {5, 9, 12, 13, 16, 45};
}
