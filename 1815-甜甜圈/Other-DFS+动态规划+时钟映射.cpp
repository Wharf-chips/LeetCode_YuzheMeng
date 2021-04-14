/*
 * @lc app=leetcode.cn id=1815 lang=cpp
 *
 * [1815] 得到新鲜甜甜圈的最多组数
 */

// @lc code=start
using namespace std;
#include<vector>
#include<cmath>
class Solution {
public:
    int fre[9],fre0[9],f[600000]={0},w[9];
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        for(int i=0;i<9;i++) fre0[i]=0,fre[i]=0;
        for(int i=0;i<groups.size();i++) fre0[groups[i]%batchSize]++;
        w[1]=1;//没有注意到要从w[1]开始初始化权值，因为不考虑fre0[0]的情况
        for(int i =2;i<batchSize;i++) w[i]=w[i-1]*(fre0[i-1]+1);//n进制数q位有n^q种可能，同理权重也是
        int all=1;
        for(int i=0;i<batchSize;i++) all*=fre0[i]+1;

        for(int i=1;i<all;i++){
            for(int j=1;j<batchSize;j++){
                fre[j]=(i/w[j])%(fre0[j]+1);
            }
            int temp=0;
            for(int j=1;j<batchSize;j++){
                temp+=(fre0[j]-fre[j])*j;
                temp = temp%batchSize;
            }
            for(int j=1;j<batchSize;j++){
                if(fre[j]!=0) f[i]=max(f[i],f[i-w[j]]+(temp==0));// 动归方程表达式写错
            }
        }
        return f[all-1]+fre0[0];
    }
};
// @lc code=end
//先将问题转化成求在何种情况下，令groups按照某种情况划分，可以使得满足sum(该组group)% == 0 的组数最多
//观察点1：对于group[i]%batchsize==0的情况，将其放在队头显然最优，并且每出现一个这样的group，开心数+1
//观察点2：若group[i]%batchsize==group[j]%batchsize，那么他们在排队时其实是等效的
//基本思路：DFS+记忆+优化+动态规划
//首先先去除所有的group[i]%batchsize==0的顾客，然后开始考虑如何表示当前DFS状态
//决定一个当前搜索状态的有三点，一是之前已经满意顾客次数，二是sum（已加入队列group)%batchsize的值和三剩余了哪些顾客
//一与二很好记录，而对于三，由于n<=30，那么如果直接用0和1表示某个批次顾客是否入队有2^30中状态需要搜索，显然超时
//由观察点2的特性得到可以优化状态表达方式，对于三来说只要group[i]%batchsize==group[j]%batchsize，那么i和j就可以看做为一类顾客
//这样子三就可以用一个fre[9]表示了（batch_size<=9),来存储group[i]%batch_size的所有情况，即每个group对应到mod后的结果
//这样我们只用对fre[]数组表示的状态进行搜索了，由于group小于30，因此搜索空间fre[1]*fre[2]....fre[9]<=10^5
//并且若我们知道了某个特定状态下的fre，那么sum(之前已经加入队列的组)%batch_size也就可以计算出来了
//综上所述这个问题就变成了对于fre的搜索，核心问题就在于如何对于这个fre进行搜索，思考可以知道我们应该从后向前搜索，因为我们记录的是剩余的顾客数，其实从前从后搜索是一样等价的
//然后就需要用到动态规划，动态规划就引出了记忆化数组的选取，如果直接选取，那么就是定义一个九维数组，每个维度的长度和fre[i]最大值相关，这个数组记录了某个状态下最大的高兴数
//有动态方程 某个状态 = max(枚举该状态减掉一个fre[i]的状态)
//对这个数组直接进行搜索时会遇到一个问题，那就是如何搜索保证之前的动态规划方程的右侧的状态总是已经搜搜过的呢
//根据LeetCode某大佬的思路，利用了时钟映射法
