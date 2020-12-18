#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pair_int pair<int, int>

using namespace std;
map<pair_int, pair_int> parent;

int traceback(pair_int des)
{
    int cost = 0;
    pair_int cur = des;
    while (1)
    {
        pair_int parentNode;
        parentNode = parent[cur];
        if (parentNode.first == -1 && parentNode.second == -1)
        {
            break;
        }
        cost += 1;
        // cout << parentNode.first << ", " << parentNode.second << endl;
        cur = parentNode;
    }
    return cost;
}

int BFS(int a, int b, int target)
{
    parent[pair_int(0, 0)] = pair_int(-1, -1);
    map<pair_int, int> visited;
    bool solvable = false;
    vector<pair_int> path;
    queue<pair_int> nextStates;
    nextStates.push(pair_int(0, 0));

    while (!nextStates.empty())
    {
        pair_int cur = nextStates.front();
        nextStates.pop();

        // if cur state is visited
        if (visited[pair_int(cur.first, cur.second)] == 1)
            continue;

        // doesn't met jug constraints
        if ((cur.first > a || cur.second > b ||
             cur.first < 0 || cur.second < 0))
            continue;

        // construct solution path
        path.push_back(pair_int(cur.first, cur.second));
        visited[pair_int(cur.first, cur.second)] = 1;

        // if we reach solution state, put ans=1
        if (cur.first == target || cur.second == target)
        {
            solvable = true;
            return traceback(pair_int(cur.first, cur.second));
            // if (cur.first == target)
            // {
            //     if (cur.second != 0)

            //         // fill final state
            //         {
            //         parent[pair_int(cur.first, 0)] = pair_int(cur.first, cur.second);
            //         path.push_back(pair_int(cur.first, 0));
            //         return traceback(pair_int(cur.first, 0));
            //         }
            // }
            // else
            // {
            //     if (cur.first != 0)

            //         // fill final state
            //         {
            //         parent[pair_int(0, cur.second)] = pair_int(cur.first, cur.second);
            //         path.push_back(pair_int(0, cur.second));
            //         return traceback(pair_int(0, cur.second));
            //         }
            // }
            // break;
        }
        // // add neighbors to queue.
        // if (visited[pair_int(cur.first, b)] != 1)
        // {
        // parent[pair_int(cur.first,b)] = pair_int(cur.first, cur.second);
        // nextStates.push(pair_int(cur.first, b));
        // }
        // if (visited[pair_int(a, cur.second)] != 1)
        // {
        // parent[pair_int(a, cur.second)] = pair_int(cur.first, cur.second);
        // nextStates.push(pair_int(a, cur.second));
        // }

        // // pour from one jug to the other
        // if(cur.first < a) {
        //     int np = a - cur.first;
        //     if(np > cur.second)
        //     {
        //         np = cur.second;
        //     }
        //     if (visited[pair_int(cur.first + np, cur.second - np)] != 1)
        //     {
        //     parent[pair_int(cur.first + np, cur.second - np)] = pair_int(cur.first, cur.second);
        //     nextStates.push(pair_int(cur.first + np, cur.second - np));
        // }
        // }

        // if(cur.second < b) {
        //     int np = b - cur.second;
        //     if(np > cur.first)
        //     {
        //         np = cur.first;
        //     }
        //     if (visited[pair_int(cur.first - np, cur.second + np)] != 1)
        //     {
        //     parent[pair_int(cur.first - np, cur.second + np)] = pair_int(cur.first, cur.second);
        //     nextStates.push(pair_int(cur.first - np, cur.second + np));
        //     }
        // }

        // // empty jug
        // if(visited[pair_int(a, 0)] != 1)
        // {
        // nextStates.push(pair_int(a, 0));
        // }
        //  if(visited[pair_int(0, b)] != 1)
        // {
        // nextStates.push(pair_int(0, b));
        // }

        // for (int i = 0; i < nextStates.size(); i++)
        // {
        //     cout << nextStates.front().first << " " << nextStates.front().second;
        // }

        nextStates.push(pair_int(cur.first, b)); // fill Jug2
        parent[pair_int(cur.first, b)] = cur;
        nextStates.push(pair_int(a, cur.second)); // fill Jug1
        parent[pair_int(a, cur.second)] = cur;
        for (int ap = 0; ap <= max(a, b); ap++)
        {

            // pour amount ap from Jug2 to Jug1
            int c = cur.first + ap;
            int d = cur.second - ap;

            // check if this state is possible or not
            if (c == a || (d == 0 && d >= 0))
            {
                nextStates.push(pair_int(c, d));
                parent[pair_int(c, d)] = cur;
            }

            // Pour amount ap from Jug 1 to Jug2
            c = cur.first - ap;
            d = cur.second + ap;

            // check if this state is possible or not
            if ((c == 0 && c >= 0) || d == b)
            {
                // nextStates.push(pair_int(c, d));
                parent[pair_int(c, d)] = cur;
                cout << c << ":" << d;
                nextStates.push(pair_int(c,d));
            }
        }

        nextStates.push(pair_int(a, 0)); // Empty Jug2
        parent[pair_int(a, 0)] = cur;
        nextStates.push(pair_int(0, b)); // Empty Jug1
        parent[pair_int(0, b)] = cur;

        for (int i = 0; i < nextStates.size(); i++)
        {
            cout << nextStates.front().first << " " << nextStates.front().second;
        }
    }
    return -1;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << BFS(a, b, c);
    return 0;
}