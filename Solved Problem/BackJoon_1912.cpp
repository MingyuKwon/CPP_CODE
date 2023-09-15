#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int dynamicResult1[1000000]; // 이건 index로 끝나는 최대 값
vector<int> argVector;

void Dynamic(int index)
{
    if (index == 1)
    {
        dynamicResult1[index] = argVector[index-1];
    }
    else
    {
        if (dynamicResult1[index - 1] < 0)
        {
            dynamicResult1[index] = argVector[index - 1];
        }
        else
        {
            dynamicResult1[index] = dynamicResult1[index-1] +  argVector[index - 1];
        }

    }
}

// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
   
    int num;
    int input;
    //while (cin >> num) {}
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> input;
        argVector.push_back(input);
    }

    for (int i = 1; i <= num; i++)
    {
        Dynamic(i);
    }

    int max = -1001;
    for (int i = 1; i <= num; i++)
    {
        if (max < dynamicResult1[i])
        {
            max = dynamicResult1[i];
        }
    }

    cout << max;

    return 0;
}
