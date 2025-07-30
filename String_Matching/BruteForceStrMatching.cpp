/*
 Problem Description : Given a text and a pattern, find all occurences of the pattern in the text
*/

#include <bits/stdc++.h>

using namespace std;

void stringMatching(string text, string pattern, vector<int> &positions)
{
    for (int i = 0; i < text.length() - pattern.length() + 1; i++)
    {
        bool found = true;
        for (int j = 0; j < pattern.length(); j++)
        {
            if (text[i + j] != pattern[j])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            positions.push_back(i);
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
    vector<int> positions;
    stringMatching(text, pattern, positions);
    if (!positions.size())
    {
        cout << "\nPattern does not exist inside the text";
    }
    else
    {
        cout << "\nPattern occurs at the following indices : ";
        for (int pos : positions)
            cout << pos << " ";
    }
    return 0;
}