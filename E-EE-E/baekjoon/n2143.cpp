#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

void scan(int n, vector<int> &arr){
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d", &temp);
        arr.push_back(arr[i]+temp);
    }
}

void make_comb(int n, vector<int> arr, vector<int> &comb){
    for(int i=0;i<arr.size();i++) for(int j=i+1;j<arr.size();j++) comb.push_back(arr[j]-arr[i]);
}

void print(char *str, vector<int> arr){
    printf("%s -> len = %d\n", str, arr.size());
    for(auto temp : arr) printf("%d ", temp);
    printf("\n");
}

int main(){
    int T, n, m;
    vector<int> a_arr={0}, b_arr={0}, a_comb, b_comb;
    scanf("%d", &T);
    scanf("%d", &n);
    scan(n, a_arr);
    scanf("%d", &m);
    scan(m, b_arr);
    make_comb(n, a_arr, a_comb);
    make_comb(m, b_arr, b_comb);
    sort(a_comb.begin(), a_comb.end());
    sort(b_comb.rbegin(), b_comb.rend());
    long long cnt=0, a_point=0, b_point=0, a_same=1, b_same=1;
    while(b_point<b_comb.size()-1 && b_comb[b_point]==b_comb[b_point+1]){
        b_point++;
        b_same++;
    }
    while(a_point<a_comb.size()){
        a_same=1;
        while(a_point<a_comb.size()-1 && a_comb[a_point]==a_comb[a_point+1]){
            a_point++;
            a_same++;
        }
        while(b_point<b_comb.size()-1 && a_comb[a_point]+b_comb[b_point]>T){
            b_point++;
            b_same=1;
            while(b_point<b_comb.size()-1 && b_comb[b_point]==b_comb[b_point+1]){
                b_point++;
                b_same++;
            }
        }
        cnt+=a_same*b_same*(a_comb[a_point]+b_comb[b_point]==T);
        a_point++;
    }
    printf("%lld\n", cnt);
}