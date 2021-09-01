#include "stdio.h"
#include "vector"
using namespace std;

vector<vector<int>> arr, map;
int max(int x, int y){ return x>y?x:y; }
int cnt(int x, int y){
    if(map[x][y]!=-1) return map[x][y];
    if(x==0) return map[x][y]=arr[x][y];
    else if(y==0) return map[x][y]=cnt(x-1, y)+arr[x][y];
    else if(y==x) return map[x][y]=cnt(x-1, y-1)+arr[x][y];
    return map[x][y]=max(cnt(x-1,y-1), cnt(x-1,y))+arr[x][y];
}

int main(){
    int n;
    scanf("%d", &n);
    arr.assign(n,{});
    map.assign(n,{});
    int temp;
    for(int i=0;i<n;i++){
        arr[i].assign(i+1,-1);
        map[i].assign(i+1,-1);
        for(int j=0;j<=i;j++){
            scanf("%d", &temp);
            arr[i][j]=temp;
        }
    }
    int result=0;
    for(int i=0;i<n;i++) result=max(result, cnt(n-1, i));
    printf("%d", result);
}