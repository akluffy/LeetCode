/*******************************************

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <map>


using namespace std;

    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, int> count;
        map<string, int>::iterator iter;
        map<string, string> fstr;
        string str;
        for(size_t i = 0; i < strs.size(); i++) {
            str = strs[i];
            std::sort(str.begin(), str.end());
            iter = count.find(str);
            if(iter == count.end()) {
                count.insert(pair<string, int>(str, 1));
                fstr.insert(pair<string, string>(str, strs[i]));
            } else {
                if(iter->second == 1)
                    result.push_back(fstr.find(str)->second);
                result.push_back(strs[i]);
                iter->second++;
            }
        }

        return result;
    }

int main()
{

    vector<string> a = {"abcd", "abced", "abdc", "dcba", "cadb", "decba", "cebda"};
    vector<string> outcome = anagrams(a);
    for(vector<string>::iterator iter = outcome.begin(); iter != outcome.end(); iter++) {
        cout << *iter << endl;
    }

    return 0;
}

