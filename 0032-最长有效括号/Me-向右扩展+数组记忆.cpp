/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
using namespace std;
#include<string>

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxnum=0;
        int nownum=1;//错误点1：初始化值错误，应该为1，之前是0
        int c=1;
        int snum[30000]={-1};
        for(int i=1;i<s.size();i++,nownum=1,c=1){
            snum[i]=-1;
            if(s[i]=='(') continue;
            int j=i-1;
            while(c!=0&&j>=0){
                if(snum[j]!=-1){
                    nownum+=j-snum[j]+1;
                    j=snum[j]-1;
                    continue;//错误点2：更新标号j后没有重新判断是否越界，需要加入continue,每次当下表变化时都一定需要重新检查
                }
                if(s[j]=='('){
                    c--;
                    nownum++;
                }
                else{
                    c++;
                    nownum++;
                }
                j--;
            }
            if(c==0){
                if(j>=1&&snum[j]!=-1){
                    nownum+=j-snum[j]+1;
                    j=snum[j];
                    snum[i]=j;
                }
                else snum[i]=j+1;
                if(nownum>maxnum) maxnum=nownum;
            }
            
        }
        return maxnum;

    }
};
// @lc code=end
//观察点1:有效子串之间只会独立不会重叠，如果重叠了那么一定可以合并成一个更大的有效传，
//如果重叠部分本身就是一个有效串，那么易证可以合并，如果不是一个有效串，其中的左括号/右括号过多过少
//那么其中一个串肯定不能有效
//观察点2:在一个序列的左侧或右侧加入新的括号，如果产生了有效子串，一定是和某个括号匹配了
//如果因新匹配括号新产生了新的有效串，那么新匹配括号之间的部分一定是有效串

