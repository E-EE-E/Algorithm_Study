#include "iostream"
#include "vector"
using namespace std;



int main(){
    int temp;
    int n, m;
    vector<vector<int>> map, way={{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    cin>>n>>m;
    vector<int> loc(3,0);
    cin>>loc[0]>>loc[1]>>loc[2];
    for(int i=0;i<n;i++){
        map.push_back({});
        for(int j=0;j<m;j++){
            cin>>temp;
            map[i].push_back(temp);
        }
    }
    int sum=0, dir, nextX, nextY;
    while(1){
        if(map[loc[0]][loc[1]]==0){
            map[loc[0]][loc[1]]=2;
            sum++;
        }
        int flag=0;
        for(int i=1;i<6;i++){
            dir=(loc[2]+8-i)%4;
            if(i==5) i++, dir=(dir+1)%4;
            nextX=loc[0]+way[(loc[2]+8-i)%4][0];
            nextY=loc[1]+way[(loc[2]+8-i)%4][1];
            if(map[nextX][nextY]==0 || (i==6 && map[nextX][nextY]==2)){
                        cout<<loc[0]<<" "<<loc[1]<<" "<<loc[2]<<"\n";
                loc[0]=nextX;
                loc[1]=nextY;
                loc[2]=dir;
                flag=1;
                break;
            }
        }
        if(flag==0) break;
    }
    cout<<sum;
}