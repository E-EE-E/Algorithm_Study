//https://programmers.co.kr/learn/courses/30/lessons/1837
#include "iostream"
#include "map"
#include <vector>
using namespace std;

vector<vector<int>> cache;
map<int, map<int, bool>> way;

int dp(int cnt, int po, vector<int> &gps_log){
    if(cache[cnt][po]!=-2) return cache[cnt][po];
    for(auto x : way[po]){
        int temp = dp(cnt-1, x.first, gps_log);
        if(temp!=-1 && x.first!=gps_log[cnt-1]) temp++;
        if(cache[cnt][po]<0 || (temp>-1 && cache[cnt][po]>temp)) cache[cnt][po]=temp;
    }
    return cache[cnt][po];
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    cache.clear();
    way.clear();
    for(int i=0;i<edge_list.size();i++){
        edge_list[i][0]--;
        edge_list[i][1]--;
    }
    for(int i=0;i<gps_log.size();i++) gps_log[i]--;

    for(int i=0;i<n;i++) way[i][i]=true;
    for(auto x : edge_list){
        way[x[0]][x[1]]=true;
        way[x[1]][x[0]]=true;
    }
    cache.assign(n,{});
    cache[0].assign(n, -1);
    cache[0][gps_log[0]]=0;
    for(int i=1;i<cache.size();i++) cache[i].assign(n, -2);

    int answer = dp(gps_log.size()-1, gps_log[gps_log.size()-1], gps_log);
    return answer;
}

int main(){
    /*
    int n=7, m=10, k=6;
    vector<int> gps_log={1, 2, 3, 3, 6, 7};
    vector<vector<int>> edge_list = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
    */
    int n=7, m=10, k=6;
    vector<int> gps_log={1, 2, 3, 3, 6, 7};
    vector<vector<int>> edge_list = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
    cout<<solution(n, m, edge_list, k, gps_log);
    return 0;
}