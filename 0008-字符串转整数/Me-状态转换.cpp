/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
using namespace std;
#include <string>
class Solution {
public:
    int myAtoi(string s) {
        bool flag = true;
        long r = 0;
        int mode = 0;
        for(int i=0;i<s.size();i++){
            switch (mode){
                case 0:
                    if((s[i]=='+'||s[i]=='-')&&i!=s.size()-1&&s[i+1]>=48&&s[i+1]<=57){
                        mode = 1;
                        flag = (s[i]=='+')?true:false;
                    }
                    else if(s[i]>=48&&s[i]<=57){
                        r = r*10 + (s[i]-48);
                        if(r*((flag)?(1):(-1))>2147483647) return 2147483647;//错误点 1：在便利的过程中就要不断计算是否越界
                        if(r*((flag)?(1):(-1))<-2147483648) return -2147483648;
                        mode = 1;
                    }
                    else if(s[i]!=' '){
                        i = s.size();
                        break;
                    }
                break;

                case 1:
                    if(s[i]<48||s[i]>57){
                        i = s.size();
                        break;
                    }
                    r = r*10 + (s[i]-48);
                    if(r*((flag)?(1):(-1))>2147483647) return 2147483647;
                    if(r*((flag)?(1):(-1))<-2147483648) return -2147483648;
                break;
            }
        }
        if(!flag) r = r*-1;
        if(r>2147483647) return 2147483647;
        if(r<-2147483648) return -2147483648;

        return int(r);
    }
};

//[-2147483648,2147483647]
//'0' 48
// @lc code=end

