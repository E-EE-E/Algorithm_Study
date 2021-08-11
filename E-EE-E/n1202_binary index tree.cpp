#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

bool comp(vector<int> x, vector<int> y){
    if(x[1]==y[1]) return x[0]<y[0];
    return x[1]>y[1];
}

class bit{
    protected:
    vector<int> arr;
    public:
    bit(int c){arr.assign(c+1,0);}
    void push(int x){
        while(x&-x){
            arr[x]++;
            x-=x&-x;
        }
        arr[x]++;
    }
    void remove(int x){
        while(x&-x){
            arr[x]--;
            x-=x&-x;
        }
        arr[x]--;
    }
    int count(int x){
        int sum=0;
        do{
            sum+=arr[x];
            x+=x&-x;
        }while(x&-x && x<arr.size());
        return sum;
    }
    int find(int x){
        if(count(x)==0) return -1;
        int left=x, right=arr.size(), mid=(left+right)/2;
        while(left<right){
            if(count(mid)<count(x)) right=mid;
            else left=mid+1;
            mid=(left+right)/2;
        }
        return left-1;
    }
};

int main(){
    int n, k, temp, sum=0;
    bit bag(100000000);
    vector<vector<int>> jewel;
    scanf("%d %d", &n, &k);
    jewel.assign(n, {0,0});
    for(int i=0;i<n;i++) scanf("%d %d", &jewel[i][0], &jewel[i][1]);
    sort(jewel.begin(),jewel.end(), comp);
    for(int i=0;i<k;i++){
        scanf("%d", &temp);
        bag.push(temp);
    }
    for(int i=0;i<n;i++){
        temp=bag.find(jewel[i][0]);
        if(temp>-1){
            sum+=jewel[i][1];
            bag.remove(temp);
        }
    }
    printf("%d\n", sum);
}