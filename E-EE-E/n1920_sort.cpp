#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main(){
    vector<int> arr;
    vector<pair<int, int>> comp;
    int n, m, temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>temp;
        comp.push_back(make_pair(temp, i));
    }

    sort(arr.begin(), arr.end());
    sort(comp.begin(), comp.end(), compare);
    int inda=0, indc=0;
    vector<int> result(m, 0);
    while(indc<m && inda<n){
        if(comp[indc].first==arr[inda]){result[comp[indc++].second]=1;}
        else if(comp[indc].first>arr[inda]){inda++;}
        else {result[comp[indc++].second]=0;}
    }
    for(int x : result){
        cout << x << '\n'; 
    }
}