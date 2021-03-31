/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maps[300]; //映射表
        memset(maps, -1, 300 * sizeof(int));
        int maxnum=0;
        int left=0,right=0,count=0;

        for(int i=0;i<s.size();i++,right++){
            if(maps[s[right]]!=-1){
                //判断是否为最大子串
                if(count>maxnum){
                    maxnum = count;
                }
                while(left!=maps[s[right]]+1){
                    if(left==maps[s[right]]){//错误一 遗漏的细节
                        maps[s[left]] = right; //错误二 无意间修改了循环的判断条件
                        left++;
                        break;
                    }
                    maps[s[left]] = -1;
                    count--;
                    left++;
                }

            }
            else{
                maps[s[right]] = right;
                count++;
                if(i==s.size()-1&&count>maxnum){
                    maxnum = count;
                }
            }
        }

        return maxnum;
    }
};
// @lc code=end

