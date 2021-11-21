#include "iostream"
#include "vector"
using namespace std;

int H, W, N;
vector<vector<int>> visit;
vector<vector<vector<int>>> map;

int count(int x, int y){
    if(visit[x][y]) return map[x][y][1];
    if(x-1>-1) map[x][y][1]+=count(x-1, y)/2+(map[x-1][y][0]==0)*(count(x-1, y)%2);
    if(y-1>-1) map[x][y][1]+=count(x, y-1)/2+(map[x][y-1][0]==1)*(count(x, y-1)%2);
    visit[x][y]=1;
    return map[x][y][1];
}

int main(){
    cin>>H>>W>>N;
    map.assign(H,{});
    visit.assign(H,{});
    for(int i=0;i<H;i++){
        map[i].assign(W,{0, 0});
        visit[i].assign(W, 0);
        for(int j=0;j<W;j++) cin>>map[i][j][0];
    }
    visit[0][0]=1;
    map[0][0][1]=N-1;
    count(H-1,W-1);
    int x=0, y=0, temp;
    while(x<H && y<W){
        temp=(map[x][y][0]+map[x][y][1])%2;
        x+=temp==0;
        y+=temp==1;
    }
    printf("%d %d\n", x+1, y+1);
}