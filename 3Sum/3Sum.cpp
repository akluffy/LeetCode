/*******************************************

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a �� b �� c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

// ���������˺ܾã����Ҳο��˲��ٱ��˵Ľⷨ������ԭ����д�ܶ�ϻ�ע��//

********************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {

    int n = (int)num.size();
    vector<vector<int> > result;
    sort(begin(num), end(num));

    for(int i = 0; i < n-2; i++) {
        // �������if continue���������ڷ�ֹ�����ظ�����ϡ��������ظ�������־�������
        // Ϊʲô������ num[i] == num[i+1]? �𰸸� ΪʲôҪ��do while ��������while���ơ�
        //  i��ʾ����ѭ����Ҫʹ�õ��i-1��ʾ�ϴ�ѭ�����Ѿ����������������д�ܱ�֤
        // ���Ԫ��(����-2,0,0,0,0,4����һ��0����Ϊnum[i]����whileѭ��)
        // ���پ���һ�������whileѭ���������д��num[i] == num[i+1], ���п���
        // ֱ��������ͬ���е����һ�����������0,0,0,0,��ôд��ֱ���������һ��0���Ӷ�
        // ���0,0,0����ϡ�ȷʵ������Ȳ�������ظ����ֲ�����������ͬ�����ϡ�
        if(i > 0 && num[i-1] == num[i]) continue;
        int x = i + 1, y = n - 1;
        while(x < y) {
            int sum = num[i] + num[x] + num[y];
            if(sum < 0) x++;
            else if(sum > 0) y--;
            else {
                result.push_back(vector<int>({num[i], num[x], num[y]}));
                do {x++;} while(x < y && num[x-1] == num[x]);
                do {y--;} while(x < y && num[y+1] == num[y]);
            }
        }
    }

    return result;
}



int main() {

    std::vector<int> v1 = {-5, -3, -1, -1, 0, 0, 0, 0, 1, 2, 3, 5, -2, -3, 6, -15, 10};

    vector<vector<int> > result1 = threeSum(v1);
    for(auto iter1 : result1) {
        for(auto iter2 : iter1) {
            cout << iter2 << " ";
        }
        cout << endl;
    }
    return 0;
}
