#include "iostream"
#include "map"
using namespace std;

void select(map<int, int>::iterator it, map<int, int>::iterator end, int left_cnt, map<int, int> &ans){
    if(left_cnt==0){
        for(auto x : ans){
            for(int i=0;i<x.second;i++) printf("%d ", x.first);
        }
        printf("\n");
        return;
    }
    if(it==end) return;
    for(int i=(it->second<left_cnt?it->second:left_cnt);i>=0;i--){
        ans[it->first]=i;
        select(++it, end, left_cnt-i, ans);
        --it;
        ans[it->first]=0;
    }
}

int main(){
    int n, m;
    map<int, int> arr, ans;
    cin>>n>>m;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr[temp]++;
    }
    select(arr.begin(), arr.end(), m, ans);
}