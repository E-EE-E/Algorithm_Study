#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for(int test = 1; test <= t; ++test) {
        int n, m;
        cin>>n >> m;
        vector<vector<int>> a(n, vector<int>(n, 0));
        vector<pair<int, int>> home;
        vector<pair<int, int>> store;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cin>> a[i][j];
                if(a[i][j] == 1) {
                    home.push_back(make_pair(i, j));
                } else if(a[i][j] == 2) {
                    store.push_back(make_pair(i, j));
                }
            }
        }
        vector<int> select(store.size(), 0);
        for(int i = 0; i < m; ++i) {
            select[i] = 1;
        }
        sort(select.begin(), select.end());
        int ans = -1;
        do{
            int sum = 0;
            for(int i = 0; i < home.size(); ++i) {
                int min = -1;
                for(int j = 0; j < store.size(); ++j) {
                    if(select[j] == 0) continue;
                    int x, y, r, c;
                    tie(x, y) = home[i];
                    tie(r, c) = store[j];
                    int dist = abs(x-r) + abs(y-c);
                    if(min == -1 || min > dist)
                        min = dist;
                }
                sum += min;
            }
            if(ans == -1 || ans > sum)
                ans = sum;
        }while(next_permutation(select.begin(), select.end()));
        cout<<'#'<<test <<' ';
        cout<< ans<<'\n';
    }
    return 0;
}
