/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include<cmath>
class Solution {
public:
    int reverse(int x) {
        if(x == -2147483648) return 0;
        bool flag;
        if(x>0) flag = true;
        else flag = false;
        int r=0;
        int length = 0;
        int test = x;
        do{
            test = test/10;
            length++;
        }while(test!=0);
        x = abs(x);// 细节一：当X为最小值是不能使用abs,因为变为正数会越界
        for(int i=0;i<length;i++){
            if(length == 10&&i == 9){
                if(flag){
                    if((r>214748364)||(2147483647-10*r<x%10)) return 0;//细节二，判断表达式中不能出现大于int范围的数字
                }
                else{
                    if((r>214748364)||(2147483647-10*r<x%10-1)) return 0;//稍微变换表达式，防止了环境出现大于int的值
                }
            }
            int mod = x%10;
            r = r*10 + mod;
            x = x/10;
        }
        if(flag) return r;
        else return r*-1;
    }
};
//-2147483648~2147483647
//阿斯克码 48 - ‘0’
// @lc code=end

