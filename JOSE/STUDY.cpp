#include "WEEK_1.h"
#include "WEEK_3.h"
#include "WEEK_4.h"
#include "WEEK_5.h"
#include "WEEK_6.h"
#include "WEEK_7.h"
#include "WEEK_8.h"
#include "BasicMath.h"
#include "BruteForce.h"
#include "KakaoPay.h"

#include <fstream>//for debugging


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//ofstream debug;
	//debug.open("debug.txt");
	//cout.rdbuf(debug.rdbuf());

	//vector<long long> ages = { 35, 25, 3, 8, 7 };
	//vector<vector<int>> wires = { {1, 2, 5}, { 2, 1, 5 }, { 1, 3, 2 }, { 3, 4, 2 }, { 3, 5, 20 }, { 4, 5, 1 } };
	//answer :  [3,4,5,2,1]
	
	vector<long long> ages = { 8, 13, 5, 8 };
	vector<vector<int>> wires = { {1, 3, 10}, { 3, 4, 1 }, { 4, 2, 2 }, { 2, 1, 3 } };
	//asnwer : [3,4,1,2]

	kakao::solution(ages, wires);

	return 0;
}

