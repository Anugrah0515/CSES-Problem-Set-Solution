#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &it: a)
        cin>>it;
    vector<int> nums;
    for(auto it: a) {
        if (nums.empty() || nums.back() <= it) 
            nums.push_back(it);
        else {
            int idx = upper_bound(nums.begin(), nums.end(), it) - nums.begin();
            nums[idx] = it;
        }
    }
    cout<<nums.size()<<endl;
    return 0;
}