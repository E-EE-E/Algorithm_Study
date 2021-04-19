//
//  main.cpp
//  n16940
//
//  Created by Ban on 2021/04/19.
//
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool solution(vector<vector<int>> tree, vector<int> order) {
    int n = (int)order.size();
    vector<bool>check(n, false);
    vector<int> parent(n);

    queue<int> q;
    check[0] = true;
    q.push(0);  //시작정점 넣기
    int m = 1;
    for(int i = 0; i < n; ++i) {
        if(q.empty()) return false; //bfs가 돌고 있는데 q가 비었다
        int x = q.front(); q.pop();
        if(order[i] != x) return false; //order와 bfs순서가 맞지 않다
        int cnt = 0;
        for(int j = 0; j < tree[x].size(); ++j) {
            int y = tree[x][j];
            if(check[y] == false) {
                parent[y] = x;
                ++cnt;
            }
        }
        for(int j = 0; j < cnt; ++j) {
            if(m+j >= n || parent[order[m+j]] != x) return false;
            
            q.push(order[m+j]);
            check[order[m+j]] = true;
        }
        m += cnt;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        int n;
        cin>>n;
        vector<vector<int>> tree(n);
        vector<int> order;
        for(int i = 0; i < n-1; ++i) {
            int x, y;
            cin>>x>>y;
            x -= 1; y -=1;
            tree[x].push_back(y);
            tree[y].push_back(x); //양방향 그래프이므로
        }
        for(int i = 0; i < n; ++i) {
            int x;
            cin>>x;
            x -= 1; //인덱스로 사용될것이기 때문에
            order.push_back(x);
        }
        cout<<'#'<<t<<' '<<solution(tree, order)<<'\n';
    }
    return 0;
}
