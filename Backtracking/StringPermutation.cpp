/*
Given a string, print all possible permutations of the string in lexicographical order
*/
#include <bits/stdc++.h>

using namespace std;

void GenPerms(int index, string &s, vector<string> &perms)
{
    if (index == s.size())
    {
        perms.push_back(s);
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        GenPerms(index + 1, s, perms);
        swap(s[index], s[i]); // backtracking step
    }
    return;
}
int main()
{
    string s = "abc";
    vector<string> result;
    GenPerms(0, s, result);
    sort(result.begin(), result.end());
    for (string perm : result)
        cout << perm << endl;
    return 0;
}