#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> a;
int solution() {
    int len = 2*n;
    vector<pair<int, int> > d(len, make_pair(0, 0));
    int ans = 0;
    for(int i = 0; i < len; ++i) {
        d[i].first = a[i];
    }
    int index = 0;
    while(true) {
        ans += 1;
        
        pair<int, int> temp = d[len-1];
        for(int i = len-2; i >= 0; --i) {
            if ((i == n-1) || (i == n-2)){
                d[i+1].first = d[i].first;
                if(d[i].second > 0)
                    d[i].second = 0;
            } else {
                d[i+1] = d[i];
            }
        }
        d[0] = temp;
        for(int i = len-1; i >= 0; --i) {
            if(d[i].second > 0) { //current robot
                if(d[(i+1)%len].second == 0) { //next part- no robot
                    if(d[(i+1)%len].first > 0) {
                        d[(i+1)%len].second = d[i].second;
                        d[i].second = 0;
                        d[(i+1)%len].first -= 1;
                    }
                }
            }
        }
        
        if(d[0].first > 0 && d[0].second == 0) {
            d[0].first -= 1;
            index += 1;
            d[0].second = index;
        }
        int cnt = 0;
        for(int i = 0; i < len; ++i) {
            if(d[i].first == 0) cnt += 1;
        }
        if(cnt >= k) break;
    }
    
    return ans;
}
int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    int tc;
    cin>>tc;
    for(int t = 1; t <= tc; ++t) {
        a.clear();
        cin>>n>>k;
        for(int i = 0; i < 2*n; ++i) {
            int x;
            cin>>x;
            a.push_back(x);
        }
        cout<<'#'<<t<<' ';
        cout<<solution();
        cout<<'\n';
    }
    return 0;
}
