/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
using namespace std;
#include<string>
class Solution {
public:
    string convert(string s, int numRows) {
        string r;
        for(int i=0;i<numRows;i++){
            int start = i;
            if(start>=s.size()) break;

            if(start == 0||start == numRows-1){
                do{
                    r += s[start];
                    start += 2*numRows - 2;
                    if(numRows == 1) start++;
                }while(start<s.size());
            }
            else{
                int flag = 0;
                do{
                    r += s[start];
                    if(flag%2==0){
                        start += 2*numRows - 2*(i+1);
                    }
                    else{
                        start += 2*i;
                    }
                    flag++;
                }while(start<s.size());
            }
        }

        return r;
    }
};
// 找到数学规律输出即可
// @lc code=end

