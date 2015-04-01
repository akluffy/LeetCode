/*******************************************


All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].


**********************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <unordered_set>
#include <map>
#include <climits>
#include <assert.h>
#include <iterator>
#include <bitset>

using namespace std;

int decode(char c){
    switch (c){
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
}

/*

    ˼·���ǰ��Ӵ�ת����һ�����֣�Ȼ��浽һ��bitset����

*/

vector<string> findRepeatedDnaSequences(string s) {
    if(s.length() <= 10) return vector<string>();
    bitset<1048576> table;
    unordered_set<string> result;
    int stringValue = 0;
    for(size_t i = 0; i < 10; ++i) {
        stringValue = (stringValue << 2) + decode(s[i]); // ��ǰ10��char���ַ���ת�������֣�ÿ��char2bit������10����20bit�����ֵҲ����2^20
    }
    table.set(stringValue);

    for(size_t i = 10; i < s.length(); ++i) {
        stringValue %= 262144;
        stringValue = (stringValue << 2) + decode(s[i]);
        if(table.test(stringValue) == 1) {          // ���ֹ����ַ�����ֱ�ӱ������
            result.insert(s.substr(i-9, 10));
        } else {                                    // û�г��ֹ��ģ���bitset����һλ��ֵ���1
            table.set(stringValue);
        }
    }

    return vector<string>(result.begin(), result.end());
}

// ��set����Ч�ʺܵ��£��ĺܶ��ڴ�
    vector<string> findRepeatedDnaSequences_set(string s) {
        if(s.size() <= 10) return vector<string>();
        unordered_set<string> result;
        unordered_set<string> hashSet;
        for(size_t i = 0; i < s.size() - 10; ++i) {
            string temp = s.substr(i, 10);
            if(hashSet.find(temp) != hashSet.end()) {
                result.insert(temp);
            } else {
                hashSet.insert(temp);
            }
        }

        return vector<string>(result.begin(), result.end());
    }



int main()
{

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> vStr = findRepeatedDnaSequences(s);
    for(const string &s : vStr) cout << s << endl;

    return 0;
}
