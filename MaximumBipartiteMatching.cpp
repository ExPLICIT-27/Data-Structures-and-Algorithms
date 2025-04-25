/*
There are M job applicants and N jobs.  Each applicant has a subset of jobs that he/she is interseted in.
Each job opening can only accept one applicant and a job applicant
can be appointed for only one job.
Given a matrix G where G(i,j) denotes
ith applicant is interested in jth job. Find an assignment of jobs
 to applicant in such that as many applicants as possible get jobs.
*/
#include <bits/stdc++.h>

using namespace std;
/*
logic: for every applicant:
-> if he/she is interested in the jth job and it has not been assigned,
-> allocate that job to the applicant
-> else if the job has been assigned,
-> try to allocate the person who has been assigned that job to another job,
-> if possible to allocate the other guy, update current applicants job to the jth job, contnue
-> keep visited arraty to check if the job has already visited
*/
bool AssignJob(int u, vector<vector<int>> &graph, vector<int> &vis, vector<int> &jobs)
{
    for (int i = 0; i < graph[0].size(); i++)
    {
        if (!vis[i] && graph[u][i])
        {
            vis[i] = 1;
            if (jobs[i] == -1 || AssignJob(jobs[i], graph, vis, jobs))
            {
                jobs[i] = u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> graph = {{0, 1, 1, 0, 0, 0},
                                 {1, 0, 0, 1, 0, 0},
                                 {0, 0, 1, 0, 0, 0},
                                 {0, 0, 1, 1, 0, 0},
                                 {0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 1}};

    int applicants = graph.size();
    int jobs = graph[0].size();

    vector<int> assigned(jobs, -1);
    vector<int> visited;
    int res = 0;
    for (int i = 0; i < applicants; i++)
    {
        visited.assign(jobs, 0);
        if (AssignJob(i, graph, visited, assigned))
            res++;
    }
    cout << res;
    return 0;
}