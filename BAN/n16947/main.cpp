#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
vector<vector<int>> a(3000, vector<int>(3000));
//순환선 찾기 (DFS)
bool dfs(int x, int px, deque<int> &circle, vector<bool> &check, int start) {
    if(check[x]) {
        if(x == start) return true;
        else return false;
    }
    circle.push_back(x);
    check[x] = true;
    for(int i = 0; i < a[x].size(); ++i) {
        int y = a[x][i];
        if(y != px) {
            if(dfs(y, x, circle, check, start))
                return true;
            else {
                if(!circle.empty())
                    circle.pop_back();
            }
        }
    }
    return false;
}
//순환선과의 최단거리 찾기 (DFS)
void go(int x, int ans, int &min, vector<int> &check, deque<int> &circle) {
    if(check[x] != -1) return;
    check[x] = ans;
    for(int k = 0; k < circle.size(); ++k) {
        if(circle[k] == x) {
            min = ans < min? ans:min;
            return;
        }
    }
    for(int i = 0; i < a[x].size(); ++i) {
        go(a[x][i], ans+1, min, check, circle);
    }
    
}
void solution(int n) {
    deque<int> circle;
    for(int i = 0; i < n; ++i) {
         vector<bool> check(n, false);
        if(dfs(i, -1, circle, check, i) == false)
            circle.clear();
        else
            break;
    }
//    for(int i = 0; i < circle.size(); ++i)
//        cout<<circle[i]<<' ';
    for(int i = 0; i < n; ++i) {
        vector<int> check(n, -1);
        int min = 4000;
        go(i, 0, min, check, circle);
        cout<<min<<' ';
    }
}

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>> tc;
    for(int t = 1; t <= tc; ++t) {
        int n;
        cin>> n;
        for(int i = 0; i < n; ++i) {
            a[i].clear();
        }
        for(int i = 0; i < n; ++i) {
            int x, y;
            cin>>x>>y;
            x-=1; y-=1;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cout<<'#'<<t<<' ';
        solution(n);
        cout<<'\n';
    }
    return 0;
}
