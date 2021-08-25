#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<vector<int>> orders(n);
    vector<int> time(n);
    vector<int> indegree(n, 0);
    vector<int> ans(n, 0);
    for(int i = 0; i < n; ++i) {
        int temp;
        cin>>temp; // 건물 짓는데 걸리는 시간
        ans[i] = time[i] = temp;
        while(1) {
            cin>>temp;
            if(temp == -1) break;;
            temp -= 1;
            indegree[i]++;
            orders[temp].push_back(i);
        }
    }
    queue<int> q;
    for(int i = 0; i < n; ++i) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < orders[cur].size(); ++i) {
            int nx = orders[cur][i];
            ans[nx] = max(ans[nx], ans[cur] + time[nx]); //왜지? 중복이 있나??

            indegree[nx]--;
            if(indegree[nx] == 0) {
                q.push(nx);
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        cout<<ans[i]<<'\n';
    }
    return 0;
}
