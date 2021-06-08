#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int n, m;
	cin >> n;	
	int a[n+1];
	
	for(int i=0; i<n; i++){
		cin >> a[i];
	
	sort(a, a+n);
	
	cin >> m;	
	int b[m+1];
		
	for(int i=0; i<m; i++){
		cin >> b[i];
		int x = 0, y = n, mid;
		bool in = false;
		
		while(x<=y){
			mid = (x+y)/2;
			if(b[i] < a[mid]){
				y = mid-1;
			} else if(b[i] > a[mid]) {
				x = mid+1;
			} else {
				in = true;
				break;
			}	 
		}
		
		if(in) cout << "1\n";
		else cout << "0\n";
	}
	
	return 0;
}
