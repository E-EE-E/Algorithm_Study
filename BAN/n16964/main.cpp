/*
 dfs순서를 결정하는 것은
 x정점에 연결된 방문하지 않은 y를 어떤 순서로 순회하는가

 입력으로 주어진 bfs 순서대로 x정점에 연결된 y를 정렬한 뒤 dfs를 돌아
 같은 결과가 나오는 지를 확인
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a[100000];
vector<bool> check;
vector<int> order;
vector<int> num;
vector<int> dfs_order;
bool comp(const int &u, const int &v) {
    return order[u] < order[v];
}
void dfs(int x) {
    if(check[x]== true) {
        return;
    }
    dfs_order.push_back(x);
    check[x] = true;
    for(int i = 0; i < a[x].size(); ++i) {
        dfs(a[x][i]);
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t<= tc; ++t) {
        int n;
        cin >> n;
        check.clear();
        order.clear();
        num.clear();
        dfs_order.clear();
        for(int i = 0; i < n; ++i) {
            a[i].clear();
            check.push_back(false);
            order.push_back(-1); //초기화 주의
        }
        for(int i = 0; i < n-1; ++i) {
            int x, y;
            cin>>x>>y;
            x -=1; y -=1;
            a[x].push_back(y);  //양방향 그래프
            a[y].push_back(x);
        }
        for(int i = 0; i < n; ++i){
            int x;
            cin>>x;
            x-=1;
            num.push_back(x); //입력 dfs 순서
            order[num[i]] = i;//들어온 순서를 저장
        }
        for(int i = 0; i < n; ++i) {
            sort(a[i].begin(), a[i].end(), comp); //한 정점에 연결된 정점들의 인접리스트를 입력 dfs순으로 재정렬
        }
        dfs(0); //dfs
        int ans = 0;
        if(dfs_order == num) //만든 dfs와 입력 dfs순서가 같으면
            ans = 1;
        else
            ans = 0;
        cout<<'#'<<t<<' '<<ans<<'\n';
    }
    return 0;
}
