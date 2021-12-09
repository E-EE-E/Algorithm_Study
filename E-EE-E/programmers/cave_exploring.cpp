//https://programmers.co.kr/learn/courses/30/lessons/67260
#include "iostream"
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> way;
vector<vector<int>> before;
vector<bool> visit, check;

void makeTree(int here, int from, vector<vector<int>> &order){
    for(auto x : way[here]){
        if(x==from) continue;
        order.push_back({here, x});
        makeTree(x, here, order);
    }
}

void searchTree(int here){
    visit[here]=true;
    for(auto x : before[here]){
        if(!visit[x]) searchTree(x);
        else if(!check[x]) throw false;
    }
    check[here]=true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    way.assign(n, {});
    before.assign(n,{});
    visit.assign(n,false);
    check.assign(n,false);
    for(auto x : path){
        way[x[0]].push_back(x[1]);
        way[x[1]].push_back(x[0]);
    }
    makeTree(0,-1, order);
    for(auto x : order) before[x[1]].push_back(x[0]);
    for(auto x : order) printf("%d %d\n", x[0], x[1]);
    bool answer = true;
    try{
        while(n-->0){
            searchTree(n);
            printf("%d ", n);
        }printf("\n");
    }catch(bool result){
        answer=result;
    }
    return answer;
}

int main(){
    //expected result == true
    int n=9;
    vector<vector<int>> path={{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}}, order={{8,5},{6,7},{4,1}};
    cout<<solution(n, path, order);
    return 0;
}