#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}

void update(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        v[i] += 100;
    }
}

int main(){
    vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    for(int i = 1; i <= 5; i++){
        v.push_back(i);
        cout << "After inserting " << i << ", size: " << v.size() << ", capacity: " << v.capacity() << endl;
    }

    update(v);
    print(v);
}