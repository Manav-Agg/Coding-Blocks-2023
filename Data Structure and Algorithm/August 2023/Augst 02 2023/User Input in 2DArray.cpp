#include<iostream>
using namespace std;
int main(){
    int a[100][100];
    int n, m;
    cout << "Enter rows and cols: ";
    cin >> n >> m;
    int number = 1;

    for(int row = 0; row < n; row++){
        for(int cols = 0; cols < m; cols++){
            // cin >> a[row][cols];
            a[row][cols] = number;
            number++;
        }
    }

    for(int row = 0; row < n; row++){
        for(int cols = 0; cols < m; cols++){
            cout << a[row][cols] << " ";
        }
        cout << endl;
    }
}