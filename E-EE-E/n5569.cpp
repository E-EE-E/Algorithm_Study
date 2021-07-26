#include "iostream"
using namespace std;
#define MOD 100000

int cache[100][100][2];

int search(int x, int y, int dir){
    if(cache[x][y][dir]) return cache[x][y][dir];
    if(x==0 || y==0) return cache[x][y][dir]=1;
    int nextX=x-2+(dir==0), nextY=y-2+(dir==1);
    if(nextX>=0) cache[x][y][dir]+=search(nextX, y, 0);
    if(nextY>=0) cache[x][y][dir]+=search(x, nextY, 1);
    cache[x][y][dir]%=MOD;
    return cache[x][y][dir];

}

int main(){
    int w, h;
    cin>>w>>h;
    cout<<(search(w-2,h-1, 0)+search(w-1,h-2,1))%MOD;
}