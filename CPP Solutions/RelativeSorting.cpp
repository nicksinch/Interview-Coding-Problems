/*
    Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way
    that the relative order among the elements will be same as those in A2.
    For the elements not present in A2, append them at last in sorted order.
    It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[]
    and A2[] has all distinct elements.

    Note: Expected time complexity is O(N log(N)).
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> RelativeSort(vector<int>& A1, vector<int>& A2)
{
    unordered_map<int, int> Freq; // Stores the frequency of the elements in first array

    int firstArrSize = A1.size();
    int secArrSize = A2.size();

    for (int i = 0; i < firstArrSize; i++)
        Freq[A1[i]]++;

    int index = 0;


    for (int i = 0; i < secArrSize; i++)
    {
        // Equivalent to Freq[A2[i]] > 0, i.e. we want to iterate
        // (key->value) value times over the key of the table
        while (Freq[A2[i]])
        {
            A1[index++] = A2[i];
            Freq[A2[i]]--; // ???
        }
// delete the element from map
        Freq.erase(A2[i]);
    }

// sort the remaining elements present in the map
    int i = index;
    for (auto it = Freq.begin(); it != Freq.end(); ++it)
        while (it->second--)    // ???
            A1[index++] = (it->first);

// sort the remaining elements
    sort(A1.begin() + i, A1.begin() + index);

    return A1;
}
// The above function takes O(nlog(n) + n) time , where n is the length of first element


int main()
{
    vector<int> A1 = {2,1,2,5,7,1,9,3,6,8,8};
    vector<int> A2 = {2,1,8,3};
    A1 = RelativeSort(A1,A2);
    for(int i = 0;i < A1.size(); ++i)
    {
        cout<<A1[i]<<" ";
    }
}

