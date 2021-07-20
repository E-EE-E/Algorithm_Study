#include "iostream"
#include "vector"
#include "map"
using namespace std;

void select(map<int, int>::iterator begin, map<int, int>::iterator end, int left_cnt, vector<int> &ans){
    if(left_cnt==0){
        for(auto x : ans) printf("%d ", x);
        printf("\n");
        return;
    }
    for(auto i=begin;i!=end;i++){
        if(i->second==0) continue;
        i->second--;
        ans.push_back(i->first);
        select(begin, end, left_cnt-1, ans);
        ans.pop_back();
        i->second++;
    }
}
int main(){
    int n, m, temp;
    map<int, int> arr;
    vector<int> ans;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr[temp]++;
    }
    select(arr.begin(), arr.end(), m, ans);
}