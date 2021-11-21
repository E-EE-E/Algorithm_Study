#include "iostream"
#include "vector"
using namespace std;

bool comp_min(int x, int y){return x<y?true:false;}
bool comp_max(int x, int y){return x>y?true:false;}

class heap{
protected:
    vector<int> arr;
    bool (*comp)(int, int);
public:
    heap(bool (*func)(int, int)){comp=func;}
    int size(){return arr.size();}
    int pop(){
        int result=arr[0], ind=1, temp=2;
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        while(temp-1<arr.size()){
            if(temp<arr.size() && comp(arr[temp], arr[temp-1])) temp++;
            if(comp(arr[ind-1], arr[temp-1])) break;
            swap(arr[ind-1], arr[temp-1]);
            ind=temp;
            temp=ind<<1;
        }
        return result;
    }
    int top(){
        return arr[0];
    } 
    void push(int x){
        arr.push_back(x);
        int ind=arr.size();
        while(ind>1 && comp(arr[ind-1], arr[(ind>>1)-1])){
            swap(arr[ind-1], arr[(ind>>1)-1]);
            ind>>=1;
        }
    }
};

int main(){
    int n, temp;
    heap left_heap(comp_max), right_heap(comp_min);
    vector<int> ans;
    scanf("%d %d", &n, &temp);
    ans.push_back(temp);
    left_heap.push(temp);
    for(int i=1;i<n;i++){
        scanf("%d", &temp);
        if(left_heap.top()<temp) right_heap.push(temp);
        else left_heap.push(temp);
        if(right_heap.size()>left_heap.size()) left_heap.push(right_heap.pop());
        else if(left_heap.size()>right_heap.size()+1) right_heap.push(left_heap.pop());
        ans.push_back(left_heap.top());
    }
    for(auto x : ans) printf("%d\n", x);
}