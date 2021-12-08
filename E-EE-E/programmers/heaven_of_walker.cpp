//https://programmers.co.kr/learn/courses/30/lessons/1832
#include "iostream"
#include <vector>

using namespace std;

int MOD = 20170805;

vector<vector<int>> cache;

int dp(int x, int y, vector<vector<int>> &city_map){
    if(cache[x][y]>-1) return cache[x][y];
    cache[x][y]=0;
    if(city_map[x][y]==1) return cache[x][y];
    int dir[2]={0,0}, temp=1;
    while(x-temp>=0 && city_map[x-temp][y]==2) temp++;
    if(x-temp>=0) dir[0]=dp(x-temp, y, city_map);
    temp=1;
    while(y-temp>=0 && city_map[x][y-temp]==2) temp++;
    if(y-temp>=0) dir[1]=dp(x, y-temp, city_map);
    return cache[x][y]=(dir[0]+dir[1])%MOD;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    cache.clear();
    cache.assign(m, {});
    for(int i=0;i<m;i++) cache[i].assign(n, -1);
    cache[0][0]=1;
    int answer = dp(m-1,n-1,city_map);
    return answer;
}

int main(){
    int m=3, n=3;
    vector<vector<int>> city_map={{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
   /*
    int m=3, n=6;
    vector<vector<int>> city_map={{0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0}};
    */
    cout<<solution(m, n, city_map);
    return 0;
}