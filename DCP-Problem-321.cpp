/*
    This problem was asked by PagerDuty.

    Given a positive integer N, find the smallest number of steps it will take to reach 1.

    There are two kinds of permitted steps:

    You may decrement N to N - 1.
    If a * b = N, you may decrement N to the larger of a and b.
    For example, given 100, you can reach 1 in five steps with the following route: 100 -> 10 -> 9 -> 3 -> 2 -> 1

    Solution provided for both iterative and recursive implementations.
    In fact, iterative way uses queue which simulates recursion.

 */

#include <iostream>
#include <vector>
#include "math.h"
#include <queue>
#include <set>
using namespace std;

pair<int,int> getClosestFactors(int N)
{
    pair<int,int> factors;
    factors.second = (int)sqrt(N);

    while(N % factors.second != 0)
    {
        (factors.second)--;
    }
    factors.first = factors.second;
    factors.second = N / factors.second;
    return factors;
}

int SmallestNumberOfSteps(int N)
{
    queue<pair<int,int>> Queue;
    set<int> Visited; // Used to track visited values

    Queue.push(make_pair(N,0)); // With 0 steps, we are at N

    while(!Queue.empty())
    {
        pair<int,int> frontValue = Queue.front();
        Queue.pop();

        int Value = frontValue.first; // more readable
        int Steps = frontValue.second; // more readable

        if(Value == 1)
            return Steps;

        if(Visited.find(Value - 1) == Visited.end()) // If value is not visited yet
        {
            Queue.push(make_pair(Value - 1,Steps + 1));
            Visited.insert(Value-1);
        }

        pair<int,int> factors = getClosestFactors(Value);
        int LargerFactor = factors.first > factors.second ? factors.first : factors.second;
        Queue.push(make_pair(LargerFactor, Steps + 1));
    }
}

int SmallestNumOfStepsRecursively(int N,int steps = 0)
{
    if(N == 1)
        return steps;

    pair<int,int> factors = getClosestFactors(N);

    int largestF = factors.first > factors.second ? factors.first : factors.second;

    if(largestF < N - 1)
        SmallestNumOfStepsRecursively(largestF, steps+1);
    else
        SmallestNumOfStepsRecursively(N - 1, steps+1);
}


int main()
{
    int N = 100050;
    cout<<"Iterative implementation: "<<endl;
    cout<<SmallestNumberOfSteps(N)<<endl;

    cout<<"Recursive implementation: "<<endl;
    cout<<SmallestNumOfStepsRecursively(N)<<endl;

}
