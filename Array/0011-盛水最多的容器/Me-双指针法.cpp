/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
//自己的思路：动态规划，但是每次在右边新加一个柱子就肯定需要和前面的
//的所有柱子比较一次，复杂度o(n^2)

//正解：双指针法，每次移动较小边那一侧的指针，从空间搜索的角度去理解，
//证明每次移动放弃的那一部分空间，是绝对不可能的结果。

#include<vector>
#include<algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxnum = (right-left)*(height[left]>height[right]?height[right]:height[left]);

        while(right-left!=1){ //错误1：特殊情况不需要进入循环判断，边界处理错误
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
            maxnum = fmax(maxnum, (right-left)*(height[left]>height[right]?height[right]:height[left]));
            if(right-left==1) break;
        }
        return maxnum;
    }
};
// @lc code=end

