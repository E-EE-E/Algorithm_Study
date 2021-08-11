#include "iostream"
#include "string"
#include "map"
using namespace std;

int main(){
    string temp;
    map<string, int> tree;
    int tot=0;
    while(getline(cin, temp)){
        tree[temp]++;
        tot++;
    }
    for(auto x : tree) printf("%s %.4lf\n", x.first.c_str(), (double)100*x.second/tot);
}