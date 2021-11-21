#include "stdio.h"
#include "unordered_map"
#include "vector"
using namespace std;

int main(){
    unordered_map<int, int> map;
    map[0]=1;
    int N, temp;
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d", &temp);
        vector<int> que;
        for(auto x : map){
            que.push_back(x.first+temp);
            que.push_back(x.first-temp);
        }
        for(auto x : que) map[x]=1;
    }
    int M;
    scanf("%d", &M);
    while(M--){
        scanf("%d", &temp);
        printf("%c ", map.find(temp)==map.end()?'N':'Y');
    }
}