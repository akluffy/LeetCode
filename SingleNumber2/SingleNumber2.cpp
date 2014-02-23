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
            three = ~(one & two);   //ȡ����ʾ,û�г������ε�
            one &= three;
            two &= three;
        }
        return one;
    }


// ����һ������Ϊ32������a��a[i]��ʾ����������iλ���ֵĴ�����
// ����a[i]��3��������������ԣ�����ͰѸ�λȡ������ɴ𰸡�
int singleNumber2(int A[], int n) {

    int bitArray[32];
    int result = 0;

    for(int i = 0; i < 32; i++) {
        bitArray[i] = 0;    //��һλ���ж��ٸ�1
        for(int j = 0; j < n; j++) {
            if((A[j] >> i) & 1) bitArray[i] = (bitArray[i] + 1) % 3;    //A[j] >> i) & 1) ��ʾȡ��A[J]�������Ʊ�ʾ���ĵ�iλ
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

��лRockyLearningCS�Ľ�𣡷��������Ա㲻ʱ֮�裡

����һ������Ȥ��λ�����⡣��˼������⣬�����[1]���ܵ�˼·��

����ö����������������ÿһ�����ֵĻ���������Ǳ���һ�������е����е����������������������Ķ����Ʊ���ÿλ�ϵġ�1������һ�飬��ô������Ҫ�ҵ��Ǹ�ֻ����һ�ε������⣬�������е����ֶ����Ʊ�ʾ��ÿһλ��1����������3k�Σ�kΪ�Ǹ���������
������а취�����еĶ����Ʊ������Щ3k����1�����㣬��ôʣ�µĶ����Ʊ��ͱ�ʾ����Ҫ�ҵ�������

��0����ʼ�趨ones=0; twos=0;

��1����twos��¼����ǰΪֹ�������ơ�1������3k+2�ε�λ����
twos = twos | (ones & A[i]);

��2����ones��¼����ǰΪֹ�������ơ�1������3k+1�ε�λ����
ones = ones ^ A[i];

��3����ones��twos��ĳһλͬʱΪ��1��ʱ������λ���ֶ����ơ�1�� 3k+3�Σ�Ҳ����3k�Σ��������λ��
xthrees = ~(ones & twos); // xthrees �Ƕ����ơ�1��û�г���3k�ε�λ��
ones = ones & xthrees;
twos = twos & xthrees;

��4�����������������е���֮��ones��¼�ľ������ս����

��չ��

ͬ���ĵ������Խ��{����һ������n�����������飬����һ�����������������е��������������Σ��ҳ����ֻ�������ε�������}��return twos�����ˡ�
************************************************************************/
