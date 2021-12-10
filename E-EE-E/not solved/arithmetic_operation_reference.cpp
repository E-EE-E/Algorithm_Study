//https://programmers.co.kr/learn/courses/30/lessons/1843
#include "iostream"
#include <vector>
#include <string>

#define GetMin(X,Y) ((X < Y) ? X : Y)
#define GetMax(X,Y) ((X > Y) ? X : Y)
#define Min 0
#define Max 1

using namespace std;

int TotalSum[2];

int solution(vector<string> arr)
{
    int pivot = arr.size() - 1;
    int sum = 0;

    while (pivot >= 0)
    {
        if (arr[pivot][0] >= '0')
        {
            sum += stoi(arr[pivot]);
        }
        else if (arr[pivot][0] == '-')
        {
            int TempSum[2] = { TotalSum[Min], TotalSum[Max] };

            TotalSum[Min] = GetMin(-(TempSum[Max] + sum), TempSum[Min] - sum);
            TotalSum[Max] = GetMax(-(TempSum[Min] + sum), TempSum[Max] + sum - (2 * stoi(arr[pivot + 1])));
            sum = 0;
        }

        pivot--;
    }

    TotalSum[Max] += sum;
    return TotalSum[Max];
}

int main(){
    vector<string> arr = {"100", "-", "300", "+", "500", "-", "800"};
    cout<<solution(arr);
}