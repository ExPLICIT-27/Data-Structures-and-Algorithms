/*
A positive integer n can be partitioned into a sequence of distinct positive integers
a1, a2, ..., an such that n = a1+a2+...+ak. We call a1+a2+...+ak as k−size distinct
partition of n. Here, none of the positive integers ai ,i = 1, 2..., n are same.
Distinct partitions of 3 are 2+1 and 3. We consider the partition 2 + 1 and the
partition 1 + 2, as the same partition. Maximumsize distinct parttion of 3 is 2 + 1.
Similarly, distinct partitions of 6 are 1 + 5, 2 + 4, 3 + 2 + 1, 6.
Maximum-size distinct partition of 6 is 3 + 2 + 1.
Given a positive integer n, design a back-tracking algorithm to compute a maximum-size
distinct partition of n. Analyse the algorithm with the running-time and the time-complexity.
*/
#include <bits/stdc++.h>

using namespace std;
void backtrack(int start, int remaining, vector<int> &partition, vector<int> &maxPartition)
{
    if (remaining == 0)
    {
        if (partition.size() > maxPartition.size())
        {
            maxPartition = partition;
        }
        return;
    }
    for (int i = start; i <= remaining; i++)
    {
        if (!partition.empty() && i <= partition.back())
        {
            continue;
        }
        partition.push_back(i);
        backtrack(i + 1, remaining - i, partition, maxPartition);
        partition.pop_back();
    }
}
vector<int> Numberpartition(int n)
{
    vector<int> partition, maxPartition;
    backtrack(1, n, partition, maxPartition);
    return maxPartition;
}
int main()
{
    int n = 6;
    vector<int> result = Numberpartition(8);
    for (int num : result)
        cout << num << " ";
    return 0;
}