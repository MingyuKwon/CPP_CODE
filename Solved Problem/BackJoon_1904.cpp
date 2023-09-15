#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int dynamicResult[1000000];

void Dynamic(int index)
{
    if (index == 1)
    {
        dynamicResult[index] = 1;
    }
    else if (index == 2)
    {
        dynamicResult[index] = 2;
    }
    else
    {
        dynamicResult[index] = (dynamicResult[index - 1] + dynamicResult[index - 2]) % 15746;
    }
}

// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
   
    int num;
    //while (cin >> num) {}
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        Dynamic(i);
    }

    cout << dynamicResult[num];
;

    return 0;
}
