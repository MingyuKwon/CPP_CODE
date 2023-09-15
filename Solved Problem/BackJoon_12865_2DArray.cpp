#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int DPResult[100001][101]; // 이건 index이하의 무게를 가질 때 최대 가치
vector<int> argVector;

vector<int> weightVector;
vector<int> valueVector;

int num;
int weightLimit;

// 백준 제출용 폼
int main(int argc, char const* argv[]) {
    ios::sync_with_stdio(false); // c와 c++ 입력 동기화 끊어서 속도 향상
    cin.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상
    cout.tie(NULL); // cin과 cout의 동기화를 끊어서 속도 향상

    //while (cin >> num) {}
    cin >> num >> weightLimit;

    int input1;
    int input2;

    for (int i = 0; i < num ; i++)
    {
        cin >> input1 >> input2;
        weightVector.push_back(input1);
        valueVector.push_back(input2);
    }

    for (int i = 1; i <= weightLimit; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (weightVector[j - 1] > weightLimit)
            {
                DPResult[i][j] = DPResult[i][j - 1];
            }
            else
            {
                if (i >= weightVector[j - 1])
                {
                    DPResult[i][j] = max(DPResult[i - weightVector[j - 1]][j - 1] + valueVector[j - 1], DPResult[i][j - 1]);
                }
                else
                {
                    DPResult[i][j] = DPResult[i][j - 1];
                }
                
            }
        }
    }

    cout << DPResult[weightLimit][num];



    

    return 0;
}