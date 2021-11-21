#include "iostream"
#include "vector"
#include "set"
using namespace std;
#define MAXN 801
int way[MAXN][MAXN];
int N, E;
int v1, v2;

pair<int, int> minWay(int x, int y){
    int min;
    int map[MAXN], flag[MAXN], check[MAXN];
    for(int i=1;i<=MAXN;i++){
        flag[i]=0;
        map[i]=0;
        check[i]=0;
    }
    flag[v1]=1, flag[v2]=2;
    set<pair<int,pair<int,int>>> que;   //(wayLength, (position, flag))
    que.emplace(make_pair(0, make_pair(x, flag[x])));
    while(!que.empty()){
        pair<int, pair<int,int>> temp = (*que.begin());
        que.erase(que.begin());
        if(check[temp.second.first]) continue;
        check[temp.second.first]=1;
        flag[temp.second.first]=flag[temp.second.first]|temp.second.second;
        map[temp.second.first]=temp.first;
        for(int i=1;i<=N;i++){
            if(way[temp.second.first][i] && !check[i]){
                que.insert(make_pair(temp.first+way[temp.second.first][i], make_pair(i, flag[temp.second.first])));
            }
        }
    }
    printf("%d -> %d = %d, flag=%d\n", x, y, map[y], flag[y]);
    return make_pair(map[y], flag[y]);
}

int min(int x, int y){return x<y?x:y;}

int main(){
    
    scanf("%d %d", &N, &E);
    int a, b, c;
    for(int i=0;i<E;i++){
        scanf("%d %d %d", &a, &b, &c);
        way[a][b]=c;
        way[b][a]=c;
    }
    scanf("%d %d", &v1, &v2);
    pair<int, int> temp=minWay(1, N), part1=minWay(1, v1), part2=minWay(1, v2), part3=minWay(v1, v2), part4=minWay(v1,N), part5=minWay(v2,N);
    int result;
    if(!part1.first && !part2.first && !part3.first && !part4.first && !part5.first){
        printf("-1\n");
        return 0;
    }
    if(temp.second==3 && !temp.first) result=temp.first;
    else{
        result=min(part1.first+part3.first+part5.first, part2.first+part3.first+part4.first);
        temp=part1;
        if(temp.second==3) result=min(result, temp.first+part4.first);
        temp=part2;
        if(temp.second==3) result=min(result, temp.first+part5.first);
    }
    printf("%d\n", result);
}