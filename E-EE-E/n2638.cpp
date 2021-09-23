#include "iostream"
#include "vector"
#include "set"
using namespace std;

vector<vector<int>> map, way={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N,M;

void airCheck(){
    set<pair<int, int>> point;
    point.insert(make_pair(0,0));
    int cnt=0;
    while(!point.empty()){
        pair<int, int> temp=*(point.begin());
        point.erase(point.begin());
        if(map[temp.first][temp.second]==2) continue;
        map[temp.first][temp.second]=2;
        for(int i=0;i<4;i++){
            if(temp.first+way[i][0]>=0 && temp.first+way[i][0]<N && temp.second+way[i][1]>=0 && temp.second+way[i][1]<M){
                if(map[temp.first+way[i][0]][temp.second+way[i][1]]==0)
                point.insert(make_pair(temp.first+way[i][0], temp.second+way[i][1]));
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    map.assign(N,{});
    int temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &temp);
            map[i].push_back(temp);
    }}
    bool flag=true;
    int cnt=0, air;
    vector<vector<int>> tempMap=map;
    while(flag){
        flag=false;
        airCheck();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(map[i][j]==1){
                    flag=true;
                    air=0;
                    for(int k=0;k<4;k++) air+=(map[i+way[k][0]][j+way[k][1]]==2);
                    if(air>1) tempMap[i][j]=0;
                    else tempMap[i][j]=1;
                }
                else{
                    tempMap[i][j]=0;
                }
            }
        }
        map=tempMap;
        cnt+=flag;
    }
    printf("%d\n", cnt);
}