#include<iostream>
using namespace std;
class Solution{
    public:
    bool knows(int a, int b){
        int ar[100][100];
        return ar[a][b];
    }

    bool isCeleb(int p, int n){
        for(int i = 0; i < n; i++){
            if(i == p){
                continue;
            }

            if(knows(p, i) || !knows(i, p)){
                return false;
            }
        }
        return true;
    }

    int findCelebrity(int n){
        for(int i = 0; i < n; i++){
            if(isCeleb(i, n)){
                return i;
            }
        }
        return -1;
    }
};

int main(){

}