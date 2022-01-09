#include <iostream>
#include <queue>
using namespace std;

void bfs(int start, int A[8][8], int n)
{
    queue<int> Q;
    int visited[8] {0};

    cout << "(" << start << "), ";
    visited[start] = 1;
    Q.emplace(start);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v=1; v<=n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                cout << "(" << v << "), ";
                visited[v] = 1;
                Q.emplace(v);
            }
        }
    }
    cout << endl;
}

int main ()
{
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    cout << "Start Node 1:" << endl;
    bfs(1, A, 8);

    return 0;
}
