#include "iostream"
#include "vector"
using namespace std;

vector<vector<vector<int>>> way;
vector<bool> visit;

void going(int x, int y, int sum){
    if(x==y) printf("%d\n", sum);
    for(auto x: way[x]){
        if(visit[x[0]]) continue;
        visit[x[0]]=true;
        going(x[0], y, sum+x[1]);
        visit[x[0]]=false;
    }
}

int main(){
    int n, m, temp;
    cin>>n>>m;
    visit.assign(n, false);
    way.assign(n, {});
    int x, y, z;
    for(int i=1;i<n;i++){
        cin>>x>>y>>z;
        way[x-1].push_back({y-1, z});
        way[y-1].push_back({x-1, z});
    }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        visit[x-1]=1;
        going(x-1, y-1, 0);
        visit[x-1]=0;
    }
}