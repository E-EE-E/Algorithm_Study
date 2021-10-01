#include"iostream"
#include"vector"
using namespace std;
vector<vector<int>> cache, cost;

int min_func(int x, int y){ return x<y?x:y; }

int dp(int x, int color){
    if(cache[x][color]!=-1) return cache[x][color];
    return cache[x][color]=min_func(dp(x-1, (color+1)%3)+cost[x][color], dp(x-1, (color+2)%3)+cost[x][color]);
}

int main(){
    int N;
    scanf("%d", &N);
    cost.assign(N+1, {});
    cache.assign(N+1,{});
    for(int i=1;i<=N;i++){
        cost[i].assign(3,0);
        cache[i].assign(3,-1);
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    cost[0].assign(3,0);
    cache[0].assign(3,0);
    int min=1000000;
    min=min_func(dp(N, 0), dp(N,1));
    min=min_func(min, dp(N,2));
    printf("%d", min);
}