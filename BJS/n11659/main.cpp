#include <iostream>
#include <vector>
using namespace std;

int n, m;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    vector<int> a(n, 0);
    for(int i = 1; i <= n; ++i) {
        cin>>a[i];
        a[i] += a[i-1]; //a[0] = 0이기때문에
    }
    
    int i, j;
    for(int k = 0; k < m; ++k) {
        cin>>i>>j;
        cout<<a[j] - a[i-1]<<'\n';//a[0] = 0이기때문에 i = 1인 상황 고려x
    }
    return 0;
}
