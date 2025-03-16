/*

    Hash Function = charvalue*pos^m % q

*/

#include <bits/stdc++.h>

using namespace std;

int modval = 101;
void matchStr(string text, string pattern)
{
    int i, j;
    int h = 1;
    int d = 256;
    int n = text.length(), m = pattern.length();
    int p = 0, t = 0;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % modval; // finding d^m-1, we would need it during the rolling hash

    for (i = 0; i < m; i++)
    {
        p = (p * d + pattern[i]) % modval; // 0*d + p, then d*p + p, d^p + d*p + p, and so on
        t = (t * d + text[i]) % modval;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (pattern[j] != text[i + j])
                    break;
            }
            if (j == m)
                cout << "\nPattern found at index : " << i << endl;
        }
        else
        {
            if (i < n - m)
            {
                t = ((t - text[i] * h) * d + text[i + m]) % modval;
            }
            if (t < 0)
            {
                t += modval;
            }
        }
    }
}

int main()
{
    string text = "ABCCDDAEFG";
    string pattern = "CDD";

    matchStr(text, pattern);

    return 0;
}