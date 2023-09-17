#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int DPResult[100001]; // 이건 index이하의 무게를 가질 때 최대 가치
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

    for (int j = 1; j <= num; j++)
    {
        for (int i = weightLimit; i >= weightVector[j-1]; i--)
        {
            DPResult[i] = max(DPResult[i], DPResult[i - weightVector[j-1]] + valueVector[j-1]);
        }
    }

    

    cout << DPResult[weightLimit];



    

    return 0;
}