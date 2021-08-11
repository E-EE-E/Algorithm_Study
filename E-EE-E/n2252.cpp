#include "stdio.h"
#include "queue"
using namespace std;

int main(){
    int N, M, x, y;
    scanf("%d %d", &N, &M);
    vector<vector<int>> back;
    vector<int> visit;
    back.assign(N,{}), visit.assign(N,0);
    for(int i=0;i<M;i++){
        scanf("%d %d", &x, &y);
        visit[y-1]++;
        back[x-1].push_back(y-1);
    }
    queue<int> que;
    for(int i=0;i<N;i++) if(!visit[i]) que.emplace(i);
    while(!que.empty()){
        printf("%d ", que.front()+1);
        for(auto temp : back[que.front()]) if(!--visit[temp]) que.emplace(temp);
        que.pop();
    }
}