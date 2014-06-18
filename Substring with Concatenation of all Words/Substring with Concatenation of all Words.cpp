/*******************************************

Substring with Concatenation of All Words

You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cstring>
#include <stack>
#include <map>


using namespace std;


vector<int> findSubstring(string S, vector<string> &L) {
    map<string, int> table;
    map<string, int> count;
    map<string, int>::iterator iterT, iterC;
    vector<int> result;
    int i, j, k, l;
    if(!S.length() || !L.size()) return result;
    l = L[0].length();
    if(S.length() < L.size() * l) return result;
    for(i = 0; i < L.size(); ++i) {
        iterT = table.find(L[i]);
        if(iterT == table.end()) table.insert(pair<string, int> (L[i], 1));
        else iterT->second++;
    }
    for(i = 0; i < l; ++i) {
        for(j = i; j <= S.length() - L.size() * l; j += l) {
            count.clear();
            for(k = j; k < j + L.size() * l; k += l) {
                string sub = S.substr(k, l);
                iterT = table.find(sub);
                iterC = count.find(sub);
                if(iterT == table.end()) break;
                if(iterC == count.end()) count.insert(pair<string, int> (sub, 1));
                else if(iterC->second < iterT->second) iterC->second++;
                else break;
            }
            if(k - j == L.size() * l) result.push_back(j);
        }
    }

    return result;
}



int main()
{
    string s1 = "barfoothefoobarman";
    vector<string> v1 = {"foo", "bar"};

    vector<int> result = findSubstring(s1, v1);
    for(int i = 0; i < result.size(); ++i)    cout << result[i] << endl;

    return 0;
}

