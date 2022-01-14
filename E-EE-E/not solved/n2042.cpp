//https://www.acmicpc.net/problem/2042
#include "iostream"
#include "vector"
using namespace std;

class BT{
private:
    int cnt, size;
    vector<long long> arr;
public:
    BT(){
        cnt=0, size=1;
        arr.assign(1, 0);
    }
    void push(long long x){
        cnt++;
        if(size<cnt){
            size*=2;
            arr.resize(size);
            arr[size-1]=arr[(size>>1)-1];
        }
        int ind=cnt;
        while(ind<=size){
            arr[ind-1]+=x;
            ind+=(ind&(-ind));
        }
    }
    
    void update(int index, long long x){
        long long gap=x-arr[index-1];
        int ind=index;
        while(ind<=size){
            arr[ind-1]+=gap;
            ind+=(ind&(-ind));
        }
    }
    
    long long sum(int lIndex, int rIndex){
        long long sum=0;
        int ind=rIndex;
        while(ind>0){
            sum+=arr[ind-1];
            ind-=(ind&(-ind));
        }
        ind=lIndex-1;
        while(ind>0){
            sum-=arr[ind-1];
            ind-=(ind&(-ind));
        }
        return sum;
    }
};


int main(){
    int N, K;
    int temp1, temp2;
    scanf("%d %d %d", &N, &temp1, &temp2);
    K = temp1 + temp2;
    BT arr;
    for(int i=0;i<N;i++){
        long long temp;
        scanf("%lld", &temp);
        arr.push(temp);
    }
    long long temp3;
    while(K--){
        scanf("%d %d %lld", &temp1, &temp2, &temp3);
        if(temp1==1) arr.update(temp2, temp3);
        else if(temp1==2) printf("%lld\n", arr.sum(temp2, (int)temp3));
    }
}