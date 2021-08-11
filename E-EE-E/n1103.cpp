#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> map, map_cnt, way{{1,0}, {-1,0}, {0,1}, {0,-1}};
int N, M;

int play(int x, int y, int count){
    if(x<0 || x>N-1 || y<0 || y>M-1 || map[x][y]==-1) return 0;
    if(map_cnt[x][y]!=-2) return map_cnt[x][y];
    if(count>N*M){
        map_cnt[x][y]=-1;
        return -1;
    }
    int max_play=0, cnt_play;
    for(auto temp : way){
        cnt_play=play(x+map[x][y]*temp[0], y+map[x][y]*temp[1], count+1);
        if(cnt_play==-1){
            map_cnt[x][y]=-1;
            return -1;
        }
        if(max_play<cnt_play+1) max_play=cnt_play+1;
    }
    map_cnt[x][y]=max_play;
    return max_play;
}

int main(){
    cin>>N>>M;
    char temp;
    for(int i=0;i<N;i++){
        map.push_back({});
        map_cnt.push_back({});
        map_cnt[i].assign(M, -2);
        for(int j=0;j<M;j++){
            cin>>temp;
            if(temp=='H') map[i].push_back(-1);
            else map[i].push_back(temp-'0');
        }
    }
    cout<<play(0, 0, 0);

    return 0;
}