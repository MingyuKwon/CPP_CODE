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
vector<int> CheckArray;

int num;

void Dynamic(int index)
{
    int num = argVector[index - 1];
    if (index == 1)
    {
        CheckArray.push_back(num);
    }
    else
    {
        bool flag = true;
        for (int h = 1; h < CheckArray.size(); h++)
        {
            if (num > CheckArray[h])
            {
                continue;
            }
            else
            {
                CheckArray[h] = num;
                flag = false;
                break;
            }
        }

        if (flag)
        {
            CheckArray.push_back(num);
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

    CheckArray.push_back(0);

    for (int i = 1; i <= num; i++)
    {
        Dynamic(i);
    }


    cout << CheckArray.size() - 1;


    return 0;
}
