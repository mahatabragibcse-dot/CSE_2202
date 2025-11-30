#include<bits/stdc++.h>
using namespace std ;

vector<vector<int>> add(const vector<vector<int>> &A,
                             const vector<vector<int>> &B)
                             {
                                 int n = A.size() ;
                                 vector<vector<int>> C(n,vector<int>(n)) ;
                                 for(int i = 0 ; i < n ; i++)
                                    for(int j = 0 ; j < n ; j++)
                                    C[i][j] = A[i][j] + B[i][j] ;

                                    return C ;

                             }


vector<vector<int>> sub(const vector<vector<int>> &A,
                             const vector<vector<int>> &B)
                             {
                                 int n = A.size() ;
                                 vector<vector<int>> C(n,vector<int>(n)) ;
                                 for(int i = 0 ; i < n ; i++)
                                    for(int j = 0 ; j < n ; j++)
                                    C[i][j] = A[i][j] - B[i][j] ;

                                    return C ;

                             }





vector<vector<int>> strassen(const vector<vector<int>> &A,
                             const vector<vector<int>> &B)
                             {
                                 int n = A.size() ;
                                 if(n == 1)
                                    return {{A[0][0]*B[0][0]}} ;
                                 int k = n/2 ;
                                 vector<vector<int>> a(k , vector<int>(k)),
                                                     b(k , vector<int>(k)),
                                                     c(k , vector<int>(k)),
                                                     d(k , vector<int>(k)),
                                                     e(k , vector<int>(k)),
                                                     f(k , vector<int>(k)),
                                                     g(k , vector<int>(k)),
                                                     h(k , vector<int>(k));


                               /// alocate matrix ;
                               for(int i = 0 ; i < k ; i++)
                                for(int j = 0 ; j < k ; j++)
                               {
                                   a[i][j] = A[i][j] ;
                                   b[i][j] = A[i][j+k] ;
                                   c[i][j] = A[i+k][j] ;
                                   d[i][j] = A[i+k][j+k] ;

                                   e[i][j] = B[i][j] ;
                                   f[i][j] = B[i][j+k] ;
                                   g[i][j] = B[i+k][j] ;
                                   h[i][j] = B[i+k][j+k] ;
                               }


                                 /// Seven recursive multiplications
                                      auto M1 = strassen(add(a,d),add(e,h));
                                      auto M2 = strassen(add(c,d) , e);
                                      auto M3 = strassen(a , sub(f,h));
                                      auto M4 = strassen(d , sub(g,e));
                                      auto M5 = strassen(add(a,b),h);
                                      auto M6 = strassen(sub(c,a),add(e,f));
                                      auto M7 = strassen(sub(b,d),add(g,h));

                        ///result submetrix ;
                        auto c11 = add(sub(add(M1,M4),M5),M7);
                        auto c12 = add(M3,M5);
                        auto c21 = add(M2,M4);
                        auto c22 = add(sub(add(M1,M3),M2),M6);


                        vector<vector<int>> C(n , vector<int>(n)) ;
                        for(int i = 0 ; i < k ; i++)
                            for(int j = 0 ; j < k ; j++)
                        {
                            C[i][j] = c11[i][j] ;
                            C[i][j+k] = c12[i][j] ;
                            C[i+k][j] = c21[i][j] ;
                            C[i+k][j+k] = c22[i][j] ;
                        }



                        return C;


                             }

int main()
{
    int n ; cin >> n ;
    vector<vector<int>> A(n, vector<int>(n)) ;
    vector<vector<int>> B(n, vector<int>(n)) ;

    ///take input ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
        cin >> A[i][j] ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
        cin >> B[i][j] ;


    auto c = strassen(A,B) ;
    cout << "\nResult (A x B):\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << "\n";
}
}
