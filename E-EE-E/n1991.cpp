#include "iostream"
#include "vector"
using namespace std;

vector<vector<int>> tree;

void search(int po, int way){
    for(int i=0;i<3;i++){
        if(way==i) printf("%c", po+(int)'A');
        if(i==2) continue;
        if(tree[po][i]!=-1) search(tree[po][i], way);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    tree.assign(n, {-1, -1});
    vector<char> temp(3);
    for(int i=0;i<n;i++){
        scanf("\n%c %c %c", &temp[0], &temp[1], &temp[2]);
        for(int j=0;j<2;j++) if(temp[j+1]!='.') tree[temp[0]-'A'][j]=temp[j+1]-'A';
    }
    for(int i=0;i<3;i++){
        search(0, i);
        printf("\n");
    }
}