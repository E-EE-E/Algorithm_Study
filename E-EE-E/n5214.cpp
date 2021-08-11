#include "iostream"
#include "queue"
#include "vector"
using namespace std;
 
int main(){
    int n, k, m, temp;
    scanf("%d %d %d", &n, &k, &m);
    vector<bool> check(m, 1);
    vector<vector<int>> station_tube(n), tube_station(m);
    queue<vector<int>> qu; //(tube number, cnt)
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            scanf("%d", &temp);
            station_tube[temp-1].push_back(i);
            tube_station[i].push_back(temp-1);
        }
    }
    if(n==1){
        printf("1\n");
        return 0;
    }
    for(int i=0;i<station_tube[0].size();i++){
        qu.push({station_tube[0][i], 1});
        check[station_tube[0][i]]=0;
    }
    while(!qu.empty()){
        for(int i=0;i<tube_station[qu.front()[0]].size();i++){
            if(tube_station[qu.front()[0]][i]==n-1){
                printf("%d\n", qu.front()[1]+1);
                return 0;
            }
            for(int j=0;j<station_tube[tube_station[qu.front()[0]][i]].size();j++){
                if(!check[station_tube[tube_station[qu.front()[0]][i]][j]]) continue;
                qu.push({station_tube[tube_station[qu.front()[0]][i]][j], qu.front()[1]+1});
                check[station_tube[tube_station[qu.front()[0]][i]][j]]=0;
            }
        }
        qu.pop();
    }
    printf("-1\n");
    return 0;
}