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
vector<int> argVector;

int num;

void Dynamic(int index)
{
    int num = argVector[index - 1];

    if (index == 1)
    {
        dynamicResult[index] = num;
    }
    else if(index == 2)
    {
        dynamicResult[index] = num + dynamicResult[1];
    }
    else
    {
        int case1 = dynamicResult[index - 2] + num; // 이전에 안먹고 이번에 먹은 경우
        int case2 = dynamicResult[index - 1]; // 안먹는 경우
        int case3 = dynamicResult[index - 3] + num + argVector[index - 2];  // 이전에도 먹고 이번에도 먹는 경우

        dynamicResult[index] = max(max(case1, case2), case3) ;
    }

}

// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
   
    
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


    cout << dynamicResult[num];


    return 0;
}
