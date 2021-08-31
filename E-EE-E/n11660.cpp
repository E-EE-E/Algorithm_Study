#include "stdio.h"
#include "vector"
using namespace std;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int>> arr(N);
    int temp;
    for(int i=0;i<N;i++){
        arr[i].assign(N, 0);
        for(int j=0;j<N;j++){
            scanf("%d", &arr[i][j]);
            arr[i][j]+=(j>0)?arr[i][j-1]:0;
        }
    }
    for(int i=1;i<N;i++) for(int j=0;j<N;j++) arr[i][j]+=arr[i-1][j];
    int x1, x2, y1, y2, result;
    while(M--){
        result=0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        result+=arr[x2-1][y2-1];
        if(x1-1) result-=arr[x1-2][y2-1];
        if(y1-1) result-=arr[x2-1][y1-2];
        if(x1-1 && y1-1) result+=arr[x1-2][y1-2];
        printf("%d\n", result);
    }
}