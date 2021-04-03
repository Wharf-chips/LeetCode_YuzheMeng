/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
using namespace std;
#include<string>
#include<cmath>
class Solution {
public:
    bool isPalindrome(int x) {
        string s;
        int length = 0;
        int test = x;
        if(x<0)s+='-';
        test = abs(x);
        do{
            s += char(test%10+48);
            test = test/10;
        }while(test!=0);
        int left=0,right=s.size()-1;
        while(left!=right&&right>left){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end

