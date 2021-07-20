#include "iostream"
#include "vector"
using namespace std;

vector<vector<char>> map;
vector<vector<int>> way={{0,1}, {0,-1}, {1,0}, {-1,0}};

int rolling(vector<int> red, vector<int> blue, int cnt){
    if(cnt>9) return -1;
    int result=-1, temp;
    vector<int> to_red, to_blue;
    for(int i=0;i<way.size();i++){
        temp=-2;
        to_red=red, to_blue=blue;
        while(map[to_red[0]][to_red[1]]=='.'){
            to_red[0]+=way[i][0];
            to_red[1]+=way[i][1];
            if(map[to_red[0]][to_red[1]]=='O'){
                temp=0;
                break;
            }
            if(to_red==blue) temp=1;
        }
        while(map[to_blue[0]][to_blue[1]]=='.'){
            to_blue[0]+=way[i][0];
            to_blue[1]+=way[i][1];
            if(map[to_blue[0]][to_blue[1]]=='O'){
                temp=-1;
                break;
            }
            if(to_blue==red) temp=2;
        }
        if(temp==0){
            result=cnt+1;
            continue;
        }
        if(temp==-1){
            continue;
        }
        if(temp==1){
            to_red[0]-=way[i][0];
            to_red[1]-=way[i][1];
        }
        else if(temp==2){
            to_blue[0]-=way[i][0];
            to_blue[1]-=way[i][1];
        }
        to_red[0]-=way[i][0];
        to_red[1]-=way[i][1];
        to_blue[0]-=way[i][0];
        to_blue[1]-=way[i][1];
        if(to_red==red && to_blue==blue) continue;
        temp=rolling(to_red, to_blue, cnt+1);
        if(result==-1 || (temp!=-1 && result>temp)) result=temp;
    }
    return result;
}

int main(){
    int N, M;
    cin>>N>>M;
    vector<int> r_point, b_point;
    map.assign(N, {});
    char temp;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>temp;
            if(temp=='R'){
                r_point={i, j};
                temp='.';
            }
            else if(temp=='B'){
                b_point={i, j};
                temp='.';
            }
            map[i].push_back(temp);
        }
    }
    cout<<rolling(r_point, b_point, 0);
}