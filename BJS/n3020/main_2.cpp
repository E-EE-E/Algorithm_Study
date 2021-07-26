#include <iostream>
#include <vector>
using namespace std;

int n, h;
int ans, cnt;
int main() {
    cin >> n >> h;
    vector<int> hsum(h+1, 0);
    for(int i = 0; i < n; ++i) {
        int bar;
        cin>>bar;
        if(i%2 != 0) { //석순
            hsum[1]++;
            hsum[bar+1]--;
        } else { //종유석
            hsum[h-bar+1]++;
        }
    }
    ans = -1;
    for(int i = 1; i <= h; ++i) {
        hsum[i] += hsum[i-1];
        if(ans == -1 || hsum[i] < ans) {
            ans = hsum[i];
            cnt = 1;
        } else if(hsum[i] == ans) {
            cnt++;
        }
    }
    cout<<ans<<' '<<cnt<<'\n';
    return 0;
}
