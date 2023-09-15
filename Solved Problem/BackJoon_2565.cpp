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
vector<int> checkVector;
map<int,int> MAP;

vector<int> value;

int num;

void Dynamic(int index)
{
    int NUM = value[index];

    if (index == 1)
    {
        checkVector.push_back(NUM);
    }
    else
    {
        bool flag = true;

        for (int i = 1; i < checkVector.size(); i++)
        {
            if (checkVector[i] < NUM)
            {
                continue;
            }
            else
            {
                checkVector[i] = NUM;
                flag = false;
                break;
            }
        }

        if (flag)
        {
            checkVector.push_back(NUM);
        }

    }

}


// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상

    //while (cin >> num) {}
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int inputStart;
        int inputEnd;
        cin >> inputStart >> inputEnd;
        MAP[inputStart] = inputEnd;
    }

    value.push_back(0);
    checkVector.push_back(0);

    for (auto n : MAP)
    {
        value.push_back(n.second);
    }

    for (int i = 1; i < value.size(); i++)
    {
        Dynamic(i);
    }

    cout << num - checkVector.size() +1 ;


    return 0;
}