/*******************************************

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".

**********************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <map>


using namespace std;

string simplifyPath(string const& path) {
    vector<string> stack;
    assert(path[0] == '/');
    int i = 0;
    while(i < path.size()) {
        while(path[i] == '/' && i < path.size()) i++; // ������/����
        if(i == path.size()) break;
        int start = i; // start ��¼ÿ��element����ʼλ��
        while(path[i] != '/' && i < path.size()) i++; // ����/ element / ֮���string
        int end = i - 1; // end ��¼ÿ��element��ĩβλ��
        string element = path.substr(start, end + 1 - start);
        if(element == "..") { // �����..�͵���һ��element
            if(stack.size() > 0)
                stack.pop_back();
        } else if(element != ".") { // �������.��.. ��ѹ��element��Ŀ¼������stack
            stack.push_back(element);
        }
    }

    if(stack.size() == 0) return "/";
    string simpPath;
    for(int i = 0; i < stack.size(); i++) {
        simpPath += "/" + stack[i];
    }

    return simpPath;
}

int main()
{

    string path1 = "/a/./b/../../c/";
    string result = simplifyPath(path1);
    cout << result << endl;

    return 0;
}

