/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        stack<char> ss,pp;
        for(int i=s.size()-1;i>=0;i--){ //第一个错误，入栈顺序错误
            ss.push(s[i]);
        }
        for(int i=p.size()-1;i>=0;i--){
            pp.push(p[i]);
        }
        char prec = ' ';
        while(ss.size()!=0&&pp.size()!=0){
            char nows = ss.top();
            char nowp = pp.top();

            if(nows==nowp){
                ss.pop();
                pp.pop();
                prec = nowp;
                continue;
            }
            else if(nowp=='.'){
                prec = '.';
                ss.pop();
                pp.pop();
                continue;
            }
            else if(nowp=='*'){
                if(nows==prec||prec=='.'){
                    ss.pop();
                    continue;
                }
                else{
                    pp.pop();
                    prec=' ';
                    continue;
                }
            }
            else{ // 第二个错误，忘了考虑不相等的情况，可以在草稿纸上列出分叉图
                prec = nowp;
                pp.pop();
                continue;
            }
        }

        if(ss.size()!=0) return false;
        if(pp.size()>1||(pp.size()==1&&pp.top()!='*')){
            return false;
        }

        return true;
    }
};
// @lc code=end

