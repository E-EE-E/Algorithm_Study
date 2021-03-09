#include <iostream>
// x를 고정하고 y에 대한 경우의 수만 고려함 -> 복잡도 n
// for(k=x; k<n*m; k+=m)
// m번마다 반복되는 x만 건너뛰며 검사

using namespace std;
int main(int argc, const char * argv[]) {

    int t;
    cin>>t;
    
    while(t--){
        int m, n, x, y;
        cin>>m>>n>>x>>y;
        x -=1;  //mod 이용하기위해
        y -=1;
        
        bool ok = false;
        int k = 0;
        for(k = x; k < (n*m); k += m) {
            if(k%n == y) {
                ok = true;
                break;
            }
        }
        if(ok) {
            cout<<k+1<<'\n';    //mod이용하기 위해 -1했으므로
        } else {
            cout<<"-1"<<'\n';
        }
    }
    
    return 0;
}
