#include <iostream>
#include <algorithm>
// 난쟁이의 키는 변하지 않기 때문에 9명의 합 먼저 구함
// 난쟁이 중 2명을 골라서 sum - arr[i] - arr[j] == 100 인 난쟁이 오름차순으로 나열

using namespace std;
int main(int argc, const char * argv[]) {

    unsigned int arr[10];
    unsigned int sum = 0;
    size_t temp1 = 101, temp2 = 101;
    
    for(size_t i = 1; i < 10; ++i)
    {
        cin>>arr[i];
    }
    for(size_t i = 1; i < 10; ++i)
    {
        sum += arr[i];
    }
    sort(arr+1, arr+10);

    for(size_t i = 1; i < 10; ++i)
    {
        for(size_t j = i; j <10; ++j)
        {
            if(sum - arr[i] - arr[j] == 100)
            {
                temp1 = i;
                temp2 = j;
                break;
            }
        }
        if (temp1 != 101)
            break;
    }

    for(size_t i = 1; i < 10; ++i)
    {
        if(i != temp1 && i != temp2)
            printf("%d \n", arr[i]);
    }
    
    return 0;
}
