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
vector<int> CheckArrayASC;
vector<int> CheckArrayDSC;

vector<int> ascendingVector;
vector<int> descendingVector;

int num;

void Dynamic(int index)
{
    int num = argVector[index - 1];
    if (index == 1)
    {
         CheckArrayASC.push_back(num);
         ascendingVector.push_back(1);
    }
    else
    {
        bool flag = true;
        for (int h = 1; h < CheckArrayASC.size(); h++)
        {
            if (num > CheckArrayASC[h])
            {
                continue;
            }
            else
            {
                CheckArrayASC[h] = num;
                ascendingVector.push_back(h);
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ascendingVector.push_back(CheckArrayASC.size());
            CheckArrayASC.push_back(num);
            
        }

    }

}

void Dynamic2(int index)
{
    int num = argVector[index - 1];
    if (index == 1)
    {
        CheckArrayDSC.push_back(num);
        descendingVector.push_back(1);
    }
    else
    {
        bool flag = true;
        for (int h = 1; h < CheckArrayDSC.size(); h++)
        {
            if (num > CheckArrayDSC[h])
            {
                continue;
            }
            else
            {
                CheckArrayDSC[h] = num;
                descendingVector.push_back(h);
                flag = false;
                break;
            }
        }

        if (flag)
        {
            descendingVector.push_back(CheckArrayDSC.size());
            CheckArrayDSC.push_back(num);

        }

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

    CheckArrayASC.push_back(0);
    CheckArrayDSC.push_back(0);

    ascendingVector.push_back(0);
    descendingVector.push_back(0);

    for (int i = 1; i <= num; i++)
    {
        Dynamic(i);
    }

    reverse(argVector.begin(), argVector.end());

    for (int i = 1; i <= num; i++)
    {
        Dynamic2(i);
    }

    int maxValue = 0;

    for (int i = 1; i <= num; i++)
    {
        int temp = ascendingVector[i] + descendingVector[num - i + 1];
        
        maxValue = max(maxValue, temp);
    }

    cout << maxValue - 1;



    return 0;
}