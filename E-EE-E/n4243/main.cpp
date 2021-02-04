#include<stdio.h>
//시행 회차 수와 현재 위치를 차원으로 갖는 map으로 memorizing 하자
//좌로간 수, 우로간 수를 차원으로 갖는 cache map으로 재귀 하는게 좋을듯

int n, s;
int loc[100];

class vector{
    public:
    long long weight;
    int dir;
};
vector cache[100][100];

int getMin(int left, int right, int posi){
    if(left+right==n-1) return 0;
    if(cache[left][right].weight!=-1) return cache[left][right].weight;

    long long lway, rway;
    if(s-left==1)
        lway = -1;
    else
        lway = getMin(left+1, right, s-left-1)+loc[posi]-loc[s-left-1];
    if(s+right==n)
        rway=-1;
    else
        rway = getMin(left, right+1, s+right+1)+loc[s+right+1]-loc[posi];
    
    if((lway!=-1 && lway<rway) || rway==-1){
        cache[left][right].dir=0;
        cache[left][right].weight=lway;
    }
    else{
        cache[left][right].dir=1;
        cache[left][right].weight=rway;
    }
    
    return cache[left][right].weight;
}

int main (){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        scanf("%d %d", &n, &s);
        int temp;
        loc[0]=0;
        for(int j=1;j<n;j++){
            scanf("%d", &temp);
            loc[j]=loc[j-1]+temp;
        }
        
        for(int j=0;j<100;j++)
            for(int k=0;k<100;j++)
                cache[j][k].weight=-1;

        printf("%d %d\n", n, s);
        for(int j=0;j<n;j++){
            printf("%d\n", loc[j]);
        }

        printf("%d\n", getMin(0,0, s));
    }
}