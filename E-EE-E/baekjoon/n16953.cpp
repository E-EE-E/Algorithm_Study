#include "iostream"
#include "set"
using namespace std;

int main(){
    int A, B;
    scanf("%d %d", &A, &B);
    set<pair<int, int>> que;
    que.emplace(make_pair(B, 1));
    pair<int, int> temp;
    int min=(1<<31)-1;
    while(!que.empty()){
        temp=*(que.begin());
        que.erase(que.begin());
        if(temp.first<1) continue;
        if(temp.first==A) min=min<temp.second?min:temp.second;
        if(temp.first%2==0) que.emplace(temp.first/2, temp.second+1);
        if(temp.first%10==1) que.emplace(temp.first/10, temp.second+1);
    }
    printf("%d\n", min==(1<<31)-1?-1:min);
}