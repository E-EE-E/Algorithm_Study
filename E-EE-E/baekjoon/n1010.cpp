#include "iostream"
#include "vector"
using namespace std;

int cache[61][61];

int comb(int x, int y){
    y=(y<x-y)?y:(x-y);
    if(cache[x][y]) return cache[x][y];
    if(y==0) return cache[x][y]=1;
    cache[x][y]=comb(x-1, y-1)+comb(x-1, y);
    return cache[x][y];
}

int main(){
    int T, n, m;
    cin>>T;
    while(T-->0){
        cin>>n>>m;
        cout<<comb(m, n)<<"\n";
    }
}
