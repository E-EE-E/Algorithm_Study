#include <iostream>
using namespace std;
int main(){
   int frN;
   int stN;
   cin >> frN;
   cin >> stN;
   int fr[frN];
   int count[frN]={0};
   int st[stN];
	int order[frN]={0}; 
   for(int i=0; i<stN; i++){
      cin >> st[i];
   }
   
   for(int l=0; l<stN; l++){
      for(int m=0; m<frN; m++){
         if(l<frN){ // 프레임 수만큼은 그냥 순서대로 집어넣기 
             fr[m]=st[l];
             order[m]=l; 
            }
         else{
            int in=0;
            int num;
            
            for(int n; n<frN; n++){
               if(fr[n]==st[m]) in =1;
               num = n; //똑같은 게 있는지 없는지 확인
            }
            
            if(in==1/*똑같은거 있을 때*/){
               count[num]+=1;//추천수만 늘리기
               order[m]=l;
			   }
               
             else{//똑같은거 없을 때
                int countN=0;
                int min;
                for(int x=0; x<frN; x++){
                   for(int y=0; y<frN; y++){
                      if(count[x]==count[y]) countN=1;
                      if(count[x]<count[y]) min=x;
                      else min=y;
                   }
                }
                //추천수 같은거 2개 이상인지확인
                
                if(countN==0/*추천수 같은거 2개 이상이 아님*/){
                   fr[min]=st[m];//추천수 제일 적은거 새로 바꾸기
                	order[m]=l;
				}
                
                else{// 추천수 같은거 2개이상
                   for(int o=0; o<frN; o++){
				   	for(int r=o+1; r<frN; r++){
				   		int old=order[o];
						if(order[o]>order[r]) old=order[r];
					   }
				   }
					fr[]=st[m];
				   order[m]=l; //배열 가장 먼저들어온 것으로 새로 바꾸기
                } 
             }
         }
      }
   }
   
}
```
```
