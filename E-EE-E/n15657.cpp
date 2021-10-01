#include"iostream"
#include"set"
#include"vector"
using namespace std;

set<int> arr;
set<vector<int>> result;
vector<int> asdf;
int N, M;

void dfs(set<int>::iterator it){
    if(asdf.size()==M){
        result.emplace(asdf);
        return;
    }
    for(auto temp = it; temp!=arr.end(); temp++){
        asdf.push_back((*temp));
        dfs(temp);
        asdf.pop_back();
    }
}

int main(){
    scanf("%d %d", &N, &M);
    int temp;
    for(int i=0;i<N;i++){
        scanf("%d", &temp);
        arr.emplace(temp);
    }
    dfs(arr.begin());
    for(auto temp : result){
        for(auto x : temp) printf("%d ", x);
        printf("\n");
    }
}