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
         if(l<frN){ // ������ ����ŭ�� �׳� ������� ����ֱ� 
             fr[m]=st[l];
             order[m]=l; 
            }
         else{
            int in=0;
            int num;
            
            for(int n; n<frN; n++){
               if(fr[n]==st[m]) in =1;
               num = n; //�Ȱ��� �� �ִ��� ������ Ȯ��
            }
            
            if(in==1/*�Ȱ����� ���� ��*/){
               count[num]+=1;//��õ���� �ø���
               order[m]=l;
			   }
               
             else{//�Ȱ����� ���� ��
                int countN=0;
                int min;
                for(int x=0; x<frN; x++){
                   for(int y=0; y<frN; y++){
                      if(count[x]==count[y]) countN=1;
                      if(count[x]<count[y]) min=x;
                      else min=y;
                   }
                }
                //��õ�� ������ 2�� �̻�����Ȯ��
                
                if(countN==0/*��õ�� ������ 2�� �̻��� �ƴ�*/){
                   fr[min]=st[m];//��õ�� ���� ������ ���� �ٲٱ�
                	order[m]=l;
				}
                
                else{// ��õ�� ������ 2���̻�
                   for(int o=0; o<frN; o++){
				   	for(int r=o+1; r<frN; r++){
				   		int old=order[o];
						if(order[o]>order[r]) old=order[r];
					   }
				   }
					fr[]=st[m];
				   order[m]=l; //�迭 ���� �������� ������ ���� �ٲٱ�
                } 
             }
         }
      }
   }
   
}
```
```
