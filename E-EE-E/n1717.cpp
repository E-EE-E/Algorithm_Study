#include "stdio.h"
#include "vector"
using namespace std;

int boss[1000001];

int find(int x){
    if(x==boss[x]) return x;
    return boss[x]=find(boss[x]);
}

void together(int x, int y){
    int arr[]={x, y}, ind=find(x)<find(y)?0:1;
    boss[find(arr[(ind+1)%2])]=boss[arr[ind]];
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    N++;
    for(int i=0;i<N;i++) boss[i]=i;
    int a, b, c;
    while(M--){
        scanf("%d %d %d", &a, &b, &c);
        if(!a) together(b, c);
        else if(a) printf("%s\n", find(b)==find(c)?"YES":"NO");
    }
}