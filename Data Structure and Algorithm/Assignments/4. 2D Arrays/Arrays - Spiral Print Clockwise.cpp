#include<iostream>
using namespace std;
int main(){
    int n, m;
    cin >> m >> n;

    int a[m][n];
    int r = 0, total = m / 2;
    int i = 0, j = 0;
    
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    int k = 0, l = 0;
    i=0;
    while(k < m && l < n){
        for(i = l; i < n; ++i){
            cout << a[k][i] << ", ";
        }
        k++;

        for(i = k; i < m; ++i){
            cout << a[i][n-1] << ", ";
        }
        n--;

        if(k < m){
            for (i = n-1; i >= l; --i){
                cout << a[m-1][i] << ", ";
            }
            m--;
        }

        if(l < n){
            for(i = m-1; i >= k; --i){
                cout << a[i][l] << ", ";
            }
            l++;
        }
    }
    
    cout << "END";
}