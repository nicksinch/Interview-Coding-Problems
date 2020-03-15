/*
    This problem was recently asked by Google.

    Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

    For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

    Bonus: Can you do this in one pass?

    O(n) solution, since we use unordered_map.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool AddUp(vector<int> Numbers, int K)
{
    unordered_map<int,int> HashTable;

    int NumLen = Numbers.size();
    for(int i = 0;i < NumLen;++i)
    {
        if(HashTable.find(K-Numbers[i]) != HashTable.end())
            return true;
        HashTable.insert(make_pair(Numbers[i],i));
    }
    return false;

}

int main()
{
    vector<int> Numbers = {10,15,3,7};
    int K = 17;
    cout<<AddUp(Numbers,K);
}

