#include <iostream>
#include <vector>
using namespace std;

int n, m;
int p[55];
int Find(int a) {
    if(p[a] == a) return a;
    else return p[a] = Find(p[a]);
}
bool UnionFind(int a, int b, int op) {
    a = Find(a);
    b = Find(b);
    if(a == b) return 1;
    if(op == 1) {
        if(a != b)
            p[a] = b;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    cin>> n>>m;
    int t;
    cin>>t;
    vector<int> known;//진실아는사람
    for(int i=0; i<t; ++i) {
        int temp;
        cin>>temp;
        known.push_back(temp);
    }
    vector<vector<int>> party(m);//파티원
    for(int i=0; i < m; ++i) {
        int p;
        cin>>p;
        for(int j = 0; j < p; ++j) {
            int temp;
            cin>>temp;
            party[i].push_back(temp);
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    for(int i = 0; i < m; ++i) {
        int n1 = party[i][0];
        for(int j= 1; j < party[i].size(); ++j) {
            int n2 = party[i][j];
            UnionFind(n2, n1, 1);
        }
    }
    int ans = m;
    for(int i = 0; i < m; ++i) {
        bool ok = true;
        for(int j = 0; j < party[i].size(); ++j) {
            int n1 = party[i][j];
            for(int k = 0; k < known.size(); ++k) {
                int n2 = known[k];
                if(UnionFind(n1, n2, 0) == true) {
                    ok = false;
                    break;
                }
            }
            if(ok == false) break;
        }
        if(ok == false) ans--;
    }
    cout<< ans<<'\n';
    return 0;
}
