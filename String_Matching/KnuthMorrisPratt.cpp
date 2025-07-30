/*
    Making use of an LPS - Longest common prefix suffix array which is precomputed from the
*/
#include <bits/stdc++.h>

using namespace std;

void BuildLPS(vector<int> &lps, string pattern)
{
    int i = 1, len = 0;

    while (i < pattern.length())
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                i++;
            }
        }
    }
}
void FindMatches(vector<int> &lps, string text, string pattern)
{
    int i = 0, j = 0;

    while (i < text.length())
    {
        if (text[i] == pattern[j])
        {
            i++, j++;
        }

        if (j == pattern.length())
        {
            cout << "\nPattern found at index : " << i - j;
            j = lps[j - 1];
        }
        else if (i < text.length() && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}
int main()
{
    string text, pattern;
    cout << "\nEnter the text : ";
    cin >> text;
    cout << "\nEnter the pattern : ";
    cin >> pattern;

    vector<int> lps(pattern.length(), 0);
    BuildLPS(lps, pattern);
    FindMatches(lps, text, pattern);
    return 0;
}