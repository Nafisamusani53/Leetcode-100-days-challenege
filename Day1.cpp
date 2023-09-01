#include<iostream>
#include<vector>
using namespace std;
/*--Counting Bits--

    Given an integer n, return an array ans of length n + 1 such that for each 
    i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
    
    Input: n = 5
    Output: [0,1,1,2,1,2]
    Explanation:
    0 --> 0
    1 --> 1
    2 --> 10
    3 --> 11
    4 --> 100
    5 --> 101
    
    T.C = O(nlogn)*/

vector<int> countBits(int n) {
    vector<int> ans;
    for(int i = 10; i<=n;i++){
        int count = 0;
        int num = i;
        while(num!=0){
            int x = num;
            if(x&1 == 1){
                count++;
            }
            num = num >> 1;
        }
        ans.push_back(count);
    }
    return ans;
}

// T.C = O(n)

vector<int> countBits(int n) {
        vector<int> ans(n+1);
        // for zero, set bit will be zero

        // now if x is odd so LSB will be set Eg = 7 --> 111
        // then right shift by 1 (7 >> 1 = 011 = y) will its LSB will get lost,
        // so y will have one set bit less than x
        // so { set bit of y + 1 }

        // now if x is even so LSB will be 0 eg == 4 --> 100
        // if we right shift by 1 then 0 will be lost, number of set bit remains same
        // (4 >> 2 = 10 = y) , so number of set bit in x = number of set bit in y
        // {set bit of y + 0 }
        ans[0] = 0;
        for(int i = 0; i<=n;i++){
            ans[i] = ans[i>>1] + bool(i&1);
        }
        return ans;
}