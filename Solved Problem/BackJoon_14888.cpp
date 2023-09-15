#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<int> resultVector;
vector<int> operandVector;
int operatorArray[4];

namespace MyOperator
{
    int plus(int a, int b)
    {
        return a + b;
    }

    int minus(int a, int b)
    {
        return a - b;
    }

    int multiple(int a, int b)
    {
        return a * b;
    }

    int divide(int a, int b)
    {
        if (a < 0)
        {
            return -(-a / b);
        }
        else
        {
            return a / b;
        }

    }

}
void Recursive(int plusCount, int minusCount, int multipleCount, int divideCount , int value, int depth)
{
    if (plusCount == 0 && minusCount == 0 && multipleCount == 0 && divideCount == 0)
    {
        resultVector.push_back(value);
        return;
    }

    if (plusCount > 0)
    {
        Recursive(plusCount -1, minusCount, multipleCount, divideCount, MyOperator::plus(value, operandVector[depth]), depth + 1);
    }

    if (minusCount > 0)
    {
        Recursive(plusCount, minusCount -1, multipleCount, divideCount, MyOperator::minus(value, operandVector[depth]), depth + 1);
    }

    if (multipleCount > 0)
    {
        Recursive(plusCount, minusCount, multipleCount-1, divideCount, MyOperator::multiple(value, operandVector[depth]), depth + 1);
    }

    if (divideCount > 0)
    {
        Recursive(plusCount, minusCount, multipleCount, divideCount-1 , MyOperator::divide(value, operandVector[depth]), depth + 1);
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
        operandVector.push_back(input);
    }

    for (int i = 0; i < 4; i++)
    {
        cin >> input;
        operatorArray[i] = input;
    }

    Recursive(operatorArray[0], operatorArray[1], operatorArray[2], operatorArray[3], operandVector[0], 1);

    sort(resultVector.begin(), resultVector.end(), greater<>());

    cout << resultVector[0] << endl << resultVector[resultVector.size() -1];

    return 0;
}
