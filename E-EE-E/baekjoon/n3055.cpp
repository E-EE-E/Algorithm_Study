#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> way = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int result=-1;

int main(){
    int x_len, y_len;
    vector<vector<char>> map;
    vector<vector<int>> water_bfs, water_map, run_bfs, run_map;
    char temp;
    cin>>x_len>>y_len;

    for(int i=0;i<x_len;i++){
        map.push_back({});
        water_map.push_back({});
        run_map.push_back({});
        water_map[i].assign(y_len, 2500);
        run_map[i].assign(y_len, 2500);
        for(int j=0;j<y_len;j++){
            cin>>temp;
            map[i].push_back(temp);
            if(temp=='*'){
                water_bfs.push_back({i, j});
                water_map[i][j]=0;
            }
            else if(temp=='S') {
                run_bfs.push_back({i,j});                
                run_map[i][j]=0;
                map[i][j]='.';
            }
        }
    }
    
    int s=0;
    while(s<water_bfs.size()){
        for(auto w : way){
            int xGo=water_bfs[s][0]+w[0];
            int yGo=water_bfs[s][1]+w[1];
            if(xGo>-1 && xGo<x_len && yGo > -1 && yGo<y_len && water_map[xGo][yGo]>water_map[water_bfs[s][0]][water_bfs[s][1]]+1 && map[xGo][yGo]=='.'){
                water_map[xGo][yGo]=water_map[water_bfs[s][0]][water_bfs[s][1]]+1;
                water_bfs.push_back({xGo, yGo});
            }
        }
        s++;
    }
    s=0;
    while(s<run_bfs.size()){
        for(auto w : way){
            int xGo=run_bfs[s][0]+w[0];
            int yGo=run_bfs[s][1]+w[1];
            if(xGo>-1 && xGo<x_len && yGo > -1 && yGo<y_len && run_map[xGo][yGo]>run_map[run_bfs[s][0]][run_bfs[s][1]]+1 && run_map[run_bfs[s][0]][run_bfs[s][1]]+1<water_map[xGo][yGo]){
                if(map[xGo][yGo]=='.'){
                    run_map[xGo][yGo]=run_map[run_bfs[s][0]][run_bfs[s][1]]+1;
                    run_bfs.push_back({xGo, yGo});
                }
                else if(map[xGo][yGo]=='D' && (result==-1 || result>run_map[run_bfs[s][0]][run_bfs[s][1]]+1)) result=run_map[run_bfs[s][0]][run_bfs[s][1]]+1;
            }
        }
        s++;
    }
    if(result==-1) cout<<"KAKTUS";
    else cout<<result;
}