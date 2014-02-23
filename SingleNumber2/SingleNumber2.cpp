/*******************************************

Single Number Total Accepted: 12254 Total Submissions: 27142 My Submissions
Given an array of integers, every element appears twice except for one.
Find that single one.

Note:
Your algorithm should have a linear runtime complexity.
Could you implement it without using extra memory?

solution from : http://rockylearningcs.blogspot.com/2014/02/single-number-ii-in-leetcode-in-java.html
********************************************/

#include <iostream>
#include <vector>

using namespace std;

    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < n; ++i) {
            two |= one & A[i];
            one ^= A[i];
            three = ~(one & two);   //取反表示,没有出现三次的
            one &= three;
            two &= three;
        }
        return one;
    }


// 创建一个长度为32的数组a，a[i]表示所有数字在i位出现的次数。
// 假如a[i]是3的整数倍，则忽略；否则就把该位取出来组成答案。
int singleNumber2(int A[], int n) {

    int bitArray[32];
    int result = 0;

    for(int i = 0; i < 32; i++) {
        bitArray[i] = 0;    //这一位上有多少个1
        for(int j = 0; j < n; j++) {
            if((A[j] >> i) & 1) bitArray[i] = (bitArray[i] + 1) % 3;    //A[j] >> i) & 1) 表示取出A[J]（二进制表示）的第i位
        }
        result |= (bitArray[i] << i);
    }

    return result;
}



int main() {

    int a[13] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 1, 2, 3, 4};

    cout << singleNumber(a, 13);

    return 0;
}


/*********************************************************************

感谢RockyLearningCS的解答！放在下面以便不时之需！

这是一道很有趣的位运算题。百思不得其解，最后看了[1]介绍的思路。

如果用二进制来表达数组中每一个数字的话，如果我们遍历一遍数组中的所有的数，即将数组中所有数的二进制表达的每位上的“1”都数一遍，那么除了需要找的那个只出现一次的整数外，其他所有的数字二进制表示中每一位“1”都出现了3k次（k为非负整数）。
如果能有办法将所有的二进制表达中这些3k个“1”清零，那么剩下的二进制表达就表示了需要找到的数。

（0）初始设定ones=0; twos=0;

（1）用twos记录到当前为止，二进制”1“出现3k+2次的位数；
twos = twos | (ones & A[i]);

（2）用ones记录到当前为止，二进制“1”出现3k+1次的位数；
ones = ones ^ A[i];

（3）当ones和twos的某一位同时为”1“时，即该位出现二进制”1“ 3k+3次（也就是3k次），清零该位。
xthrees = ~(ones & twos); // xthrees 是二进制“1”没有出现3k次的位数
ones = ones & xthrees;
twos = twos & xthrees;

（4）遍历完数组中所有的数之后，ones记录的就是最终结果。

扩展：

同样的道理，可以解决{给定一个包含n个整数的数组，除了一个数出现两次外所有的整数均出现三次，找出这个只出现两次的整数。}，return twos就行了。
************************************************************************/
