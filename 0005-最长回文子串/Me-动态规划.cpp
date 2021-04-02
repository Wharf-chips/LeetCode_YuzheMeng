/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
using namespace std;
#include<string>
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        bool **p = new bool*[s.size()];
        string maxs;
        for(int i=0;i<s.size();i++){
            p[i] = new bool[s.size()];
        }
        for(int len=0;len<s.size();len++){//由于动归方程是从短到长的，故以串长度作为最外层循环
            for(int i=0;i+len<s.size();i++){
                int j = i + len;
                if(len == 0){
                    p[i][j] = true;
                }
                else if(len == 1){
                    if(s[i]==s[j]) p[i][j] = true;
                    else p[i][j] = false;
                }
                else{
                    p[i][j] = p[i+1][j-1]&&(s[i]==s[j]);
                }
                if(p[i][j]&&len+1>maxs.size()){//错误1，实际长度是len+1，不是len
                    maxs = s.substr(i, j-i+1);
                }
                
            }
        }

        return maxs;

    }
};
//动态规划方法
//p(i,j) = (s[i]==s[j])&&p(i+1,j-1)
// @lc code=end

// 从字符串中间为起点，每次左右各增加一个字符，并将其放入回文备选集中
//（空为中和新字符为中）对于左右侧增加的字符更新回文数量，如果不再符合回文规则，踢出回文备选集中。

