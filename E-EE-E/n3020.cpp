#include "iostream"
#include "vector"
#include "algorithm"
#include "map"
using namespace std;

int main(){
    int N, H;
    cin>>N>>H;
    int n=N/2;
    vector<int> stalagmite(n, 0), pillar(n, 0);
    for(int i=0;i<n;i++) cin>>stalagmite[i]>>pillar[i];
    sort(stalagmite.rbegin(), stalagmite.rend());
    sort(pillar.rbegin(), pillar.rend());
    int hight=1, ind_stal=n-1, ind_pill=0;
    map<int, int> cnt;
    while(hight<=H){
        while(hight>stalagmite[ind_stal] && ind_stal>=0) ind_stal--;
        while(hight>(H-pillar[ind_pill]) && ind_pill<n) ind_pill++;
        cnt[ind_stal+1+ind_pill]++;
        hight++;
    }
    cout<<cnt.begin()->first<<" "<<cnt.begin()->second;
}