#include "iostream"
#include "vector"
#include "set"
using namespace std;

vector<set<int>> heavier, lighter;

void set_heavier(set<int>& heavy_list, int ind){
    for(auto x: heavy_list) heavier[ind].emplace(x);
    heavy_list.emplace(ind);
    for(auto x : lighter[ind]){
        set_heavier(heavy_list, x);
    }
    heavy_list.erase(ind);
}

void set_lighter(set<int>& light_list, int ind){
    for(auto x: light_list) lighter[ind].emplace(x);
    light_list.emplace(ind);
    for(auto x : heavier[ind]){
        set_heavier(light_list, x);
    }
    light_list.erase(ind);
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    heavier.assign(N, {});
    lighter.assign(N, {});

    int a, b;
    while(M--){
        scanf("%d %d", &a, &b);
        heavier[b-1].emplace(a-1);
        lighter[a-1].emplace(b-1);
    }
    set<int> set_list;
    for(int i=0;i<N;i++){
        set_list.clear();
        set_list.emplace(i);
        for(auto x : lighter[i]){
            set_heavier(set_list, x);
        }
        for(auto x : heavier[i]){
            set_lighter(set_list, x);
        }
    }

    for(int i=0;i<N;i++){
        printf("i=%d\nheavier : ", i);
        for(auto x : heavier[i]) printf("%d ", x);
        printf("\nlighter : ");
        for(auto x: lighter[i]) printf("%d ", x);
        printf("\n");
    }
    for(int i=0;i<N;i++)
        printf("%d  %d\n", heavier[i].size(), lighter[i].size());
        //printf("%d\n", N-heavier[i].size()-lighter[i].size()-1);
    return 0;
}