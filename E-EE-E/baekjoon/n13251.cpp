#include "iostream"
#include "vector"
using namespace std;

int main(){
    double sum=0;
    int m, k, n=0;
    cin>>m;
    vector<int> arr(m,0);
    for(int i=0;i<m;i++) cin>>arr[i], n+=arr[i];
    cin>>k;
    for(int i=0;i<m;i++){
        double result=1;
        int cnt=0;
        while(cnt<k){
            if(!(arr[i]-cnt)){
                result=0;
                break;
            }
            result*=(double)(arr[i]-cnt)/(n-cnt);
            cnt++;
        }
        sum+=result;
    }
    printf("%.18lf\n", sum);
}