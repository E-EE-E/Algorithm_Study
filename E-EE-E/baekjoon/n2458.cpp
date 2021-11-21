#include "stdio.h"
#include "queue"
using namespace std;

vector<vector<vector<int>>> comp(2); //smaller, larger

int main(){
    int N, M, result=0, a, b;
    scanf("%d %d", &N, &M);
    comp[0].assign(N,{});
    comp[1].assign(N,{});
    while(M--){
        scanf("%d %d", &a, &b);
        comp[0][a-1].push_back(b-1);
        comp[1][b-1].push_back(a-1);
    }
    for(int i=0;i<N;i++){
        vector<int> visit(N,0);
        queue<int> que;
        int cnt=0;
        for(int j=0;j<2;j++){
            que.emplace(i);
            while(!que.empty()){
                for(auto x : comp[j][que.front()]){
                    if(!visit[x]){
                        visit[x]=1;
                        que.emplace(x);
                        cnt++;
                    }
                }
                que.pop();
            }
        }
        result+=(cnt==N-1);
    }
    printf("%d\n", result);
}