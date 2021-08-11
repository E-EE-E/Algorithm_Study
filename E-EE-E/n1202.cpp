#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class heap{
    protected:
    vector<int> arr;
    public:
    int pop(){
        int result=0, ind=1, temp=2;
        if(arr.size()==0) return result;
        result=arr[0];
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        while(temp-1<arr.size()){
            if(temp<arr.size() && arr[temp-1]<arr[temp]) temp++;
            if(arr[ind-1]>arr[temp-1]) break;
            swap(arr[ind-1], arr[temp-1]);
            ind=temp;
            temp=ind<<1;
        }
        return result;
    }
    void push(int x){
        arr.push_back(x);
        int ind=arr.size();
        while(ind>1 && arr[ind-1]>arr[(ind>>1)-1]){
            swap(arr[ind-1], arr[(ind>>1)-1]);
            ind>>=1;
        }
    }
};

int main(){
    int n, k, temp;
    long long sum=0;
    scanf("%d %d", &n, &k);
    vector<vector<int>> jewel(n, {0, 0});
    vector<int> bag(k, 0), ans;
    for(int i=0;i<n;i++) scanf("%d %d", &jewel[i][0], &jewel[i][1]);
    for(int i=0;i<k;i++) scanf("%d", &bag[i]);
    sort(bag.begin(), bag.end());
    sort(jewel.begin(), jewel.end());
    for(auto x: bag) printf("%d ", x);
    printf("\n");
    for(auto x: jewel) printf("%d %d / ", x[0], x[1]);
    printf("\n");
    temp=0;
    heap steel;
    for(int i=0;i<k;i++){
        while(temp<jewel.size() && jewel[temp][0]<=bag[i]) steel.push(jewel[temp++][1]);
        ans.push_back(steel.pop());
        sum+=ans[ans.size()-1];
    }
    for(auto x: ans) printf("%d ", x);
    printf("\n");
    printf("%lld", sum);
}