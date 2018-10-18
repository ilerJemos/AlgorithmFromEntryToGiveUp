#include <iostream>
#include "Solution.cpp"

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(23);
    v.push_back(2);
    v.push_back(6);
    v.push_back(4);
    v.push_back(7);

    Solution s;
    cout << (s.checkSubarraySum(v,6));
  
}
