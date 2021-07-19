#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
vector<char> arr, vowel={'a', 'e', 'i', 'o', 'u'};
vector<int> check, vowel_ind;
int L, C;

void gogo(int x, int cnt){
    if(cnt==L){
        int vowel_cnt=0;
        for(auto temp : vowel_ind) if(check[temp]==1) vowel_cnt++;
        if(vowel_cnt>0 && vowel_cnt<L-1){
            for(int i=0;i<C;i++) if(check[i]==1) cout<<arr[i];
            cout<<'\n';
        }
        return;
    }
    for(int i=x+1; i<C;i++){
        check[i]=1;
        gogo(i, cnt+1);
        check[i]=0;
    }
    return;
}

int main(){
    cin >> L >> C;
    check.assign(C, 0);
    char temp;
    for(int i=0;i<C;i++){
        cin>>temp;
        if(temp!=' ') arr.push_back(temp);
    }
    sort(arr.begin(), arr.begin()+arr.size());
    for(int i=0;i<C;i++) for(auto temp : vowel) if(arr[i]==temp) vowel_ind.push_back(i);
    gogo(-1, 0);
}