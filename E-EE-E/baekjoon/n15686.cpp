#include "iostream"
#include "vector"
using namespace std;

int n, m;
vector<vector<int>> map, house_position, chicken_position;
vector<int> check_chicken;
int minDistance=(1<<31)-1;

void DoC_Calculator(){
    int result=0, minDis;
    for(auto x : house_position){
        minDis=100;
        for(int i=0;i<chicken_position.size();i++){
            if(check_chicken[i]==1 && minDis>abs(x[0]-chicken_position[i][0])+abs(x[1]-chicken_position[i][1])) minDis=abs(x[0]-chicken_position[i][0])+abs(x[1]-chicken_position[i][1]);
        }
        result+=minDis;
    }
    if(result<minDistance) minDistance = result;
    return;
}

void recursive(int num, int pos){
    if(num==m) { DoC_Calculator(); return;}
    for(int i=pos+1;i<chicken_position.size();i++){
        check_chicken[i]=1;
        recursive(num+1, i);
        check_chicken[i]=0;
    }
    return;
}

int main(){
    cin>>n>>m;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            if(temp==1) house_position.push_back({i,j});
            else if(temp==2) chicken_position.push_back({i,j});
        }
    }

    check_chicken.assign(chicken_position.size(), 0);
    recursive(0, -1);
    cout<<minDistance;
}