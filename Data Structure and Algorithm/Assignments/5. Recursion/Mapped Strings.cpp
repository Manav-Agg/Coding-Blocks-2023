#include<iostream>
using namespace std;
string map = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void solve(string s, int i, string t){
    //base case....
    if(s[i] == '\0'){
        t[i] = '\0';
        cout << t << endl;
        return;
    }

    int digit = s[i] - '0';
    solve(s, i + 1, t + map[digit]);

    if(i < s.size() - 1){
        int number = (s[i] - '0') * 10 + s[i+1] - '0';
        if(number <= 26){
            solve(s, i + 2, t + map[number]);
		}
    }
}

int main(){
    string s;
    cin >> s;
    solve(s, 0, "");
}