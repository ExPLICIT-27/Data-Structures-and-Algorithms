#include <bits/stdc++.h>
using namespace std;
/*
find the longest palindromic subsequence
*/
string NaiveBrute(int left, int right, string &str)
{
    string res = "";
    if (left == right)
    {
        res += str[left];
        return res;
    }
    if (left > right)
        return res;

    if (str[left] == str[right])
    {
        return str[left] + NaiveBrute(left + 1, right - 1, str) + str[right];
    }
    string incl = NaiveBrute(left + 1, right, str);
    string incr = NaiveBrute(left, right - 1, str);
    return (incl.length() > incr.length()) ? incl : incr;
}
string Memoized(int left, int right, string &str, map<string, string> &memo)
{
    string res = "";
    if (left == right)
    {
        return res + str[left];
    }
    if (left > right)
    {
        return res;
    }
    string key = to_string(left) + "," + to_string(right);
    if (memo.find(key) != memo.end())
    {
        return memo[key];
    }
    if (str[left] == str[right])
    {
        return str[left] + Memoized(left + 1, right - 1, str, memo) + str[right];
    }
    string front = Memoized(left + 1, right, str, memo);
    string back = Memoized(left, right - 1, str, memo);
    memo[key] = (front.length() > back.length()) ? front : back;
    return memo[key];
}

int main()
{
    string str = "abcdfba";
    cout << NaiveBrute(0, str.length() - 1, str) << endl;
    map<string, string> memo;
    cout << Memoized(0, str.length() - 1, str, memo) << endl;
    return 0;
}