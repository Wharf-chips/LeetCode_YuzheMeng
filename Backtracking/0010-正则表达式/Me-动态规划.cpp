/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start

using namespace std;
#include<string>
class Solution {
public:
    bool isMatch(string s, string p) {
        bool **arr = new bool*[s.size()+1];
        for(int i=0;i<s.size()+1;i++){
            arr[i]=new bool[p.size()+1];
        }
        arr[0][0] = true;
        for(int i=1;i<s.size()+1;i++){
            arr[i][0]=false;
        }
        for(int i=1;i<p.size()+1;i++){
            if(i==2&&p[i-1]=='*') arr[0][i] = true;
            if(p[i-1]!='*') arr[0][i] = false;
            else arr[0][i] = arr[0][i-2];
        }

        return f(s.size(),p.size(),arr,s,p);
    }

    bool f(int i, int j, bool **arr, string &s, string &p){
        if(i==0||j==0) return arr[i][j];
        if(p[j-1]!='*'){
            if(s[i-1]!=p[j-1]&&p[j-1]!='.') return false;
            else return f(i-1, j-1, arr, s, p);
        }
        else{
            if(p[j-2]!='.'&&p[j-2]!=s[i-1]){
                if(f(i,j-2,arr,s,p)) return true;
                else return false;
            }
            if(p[j-2]=='.'){
                for(int k=0;k<i+1;k++){
                    if(f(k,j-2,arr,s,p)) return true;
                }
                return false;
            }
            else return f(i-1,j,arr,s,p)||f(i,j-2,arr,s,p);
        }
    }

    

};
// @lc code=end

//DPS法：https://blog.csdn.net/HizT_1999/article/details/113260843
//建立一个S+1*P+1的二维数组(考虑为空情况），f(i, j)表示字符串前i个能否和匹配串前j个匹配成功，矩阵右下角位置就为
//寻找的答案

