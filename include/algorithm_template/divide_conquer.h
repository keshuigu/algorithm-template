#ifndef ALGORITHM_TEMPLATE_DIVIDE_CONQUER_H
#define ALGORITHM_TEMPLATE_DIVIDE_CONQUER_H

/*
原理：
1）思考一个问题在大范围上的答案，是否等于，左部分的答案 + 右部分的答案 +
跨越左右产生的答案
2）计算“跨越左右产生的答案”时，如果加上左、右各自有序这个设定，会不会获得计算的便利性
3）如果以上两点都成立，那么该问题很可能被归并分治解决（话不说满，因为总有很毒的出题人）
4）求解答案的过程中只需要加入归并排序的过程即可，因为要让左、右各自有序，来获得计算的便利性
*/

#include <vector>

namespace algorithm_template {
// https://www.nowcoder.com/practice/6dca0ebd48f94b4296fc11949e3a91b8
long long SmallSum(std::vector<int>& arr);

// https://leetcode.cn/problems/reverse-pairs/
int ReversePairs(std::vector<int>& arr);
}  // namespace algorithm_template

#endif  // ALGORITHM_TEMPLATE_DIVIDE_CONQUER_H