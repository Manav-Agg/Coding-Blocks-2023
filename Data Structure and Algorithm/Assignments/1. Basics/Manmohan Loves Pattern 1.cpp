/*
1
11
111
1001
11111
100001
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    for(int row = 1; row <= n; row++){
        for(int i = 1; i <= row; i++){
            if(i == 1 || i == row){
                cout << 1;
            }
            else{
                cout << row % 2;
            }
        }
        cout << endl;
    }
}