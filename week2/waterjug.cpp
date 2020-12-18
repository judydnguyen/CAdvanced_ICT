#include <iostream>
#include <queue>
#include <map>
#include <vector>
#define pii pair<int, int>
#define mp make_pair

using namespace std;

map<pii, pii> parent;
int traceback(pii des)
{
    // cout << des.first << ", " << des.second << endl;
    int cost = 0;
    pii cur = des;
    while (1)
    {
        pii parentNode;
        parentNode = parent[cur];
        if (parentNode == pii(0,0))
        {
            break;
        }
        cost += 1;
        // cout << parentNode.first << ", " << parentNode.second << endl;
        cur = parentNode;
        // if (cost > 10)
        //     break;
    }
    // exit(-1);
    return cost+1;
}

int BFS(int a, int b, int target)
{

    // Map is used to store the states, every
    // state is hashed to binary value to
    // indicate either that state is visited
    // before or not
    map<pii, int> m;
    bool isSolvable = false;
    vector<pii> path;

    queue<pii> q;      // queue to maintain states
    q.push(pii(0, 0)); // Initialing with initial state
    parent[pii(0, 0)] = pii(-1, -1);
    pii prev;
    while (!q.empty())
    {

        pii u = q.front(); // current state

        q.pop(); // pop off used state

        // if this state is already visited
        if (m[pii(u.first, u.second)] == 1)
            continue;

        // doesn't met jug constraints
        if ((u.first > a || u.second > b ||
             u.first < 0 || u.second < 0))
            continue;

        // parent[u] = prev;
        // filling the vector for constructing
        // the solution path
        path.push_back(pii(u.first, u.second));

        // marking current state as visited
        m[pii(u.first, u.second)] = 1;

        // if we reach solution state, put ans=1
        if (u.first == target || u.second == target)
        {
            isSolvable = true;
            return traceback(u);
            if (u.first == target)
            {
                if (u.second != 0)

                    // fill final state
                    path.push_back(pii(u.first, 0));
            }
            else
            {
                if (u.first != 0)

                    // fill final state

                    path.push_back(pii(0, u.second));
            }

            // print the solution path
            // int sz = path.size();
            // for (int i = 0; i < sz; i++)
            //     cout << "(" << path[i].first
            //         << ", " << path[i].second << ")\n";
            break;
        }

        // if we have not reached final state
        // then, start developing intermediate
        // states to reach solution state
        if (m[pii(u.first, b)] != 1)
        {
            q.push(pii(u.first, b)); // fill Jug2
            parent[pii(u.first, b)] = pii(u.first, u.second);
        }
        if (m[pii(a, u.second)] != 1)
        {
            q.push(pii(a, u.second)); // fill Jug1
            parent[pii(a, u.second)] = pii(u.first, u.second);
        }
        for (int ap = 0; ap <= max(a, b); ap++)
        {

            // pour amount ap from Jug2 to Jug1
            int c = u.first + ap;
            int d = u.second - ap;

            // check if this state is possible or not
            if (c == a || (d == 0))
            {
                if (m[pii(c, d)] != 1)
                {
                    q.push(pii(c, d));
                    parent[pii(c, d)] = pii(u.first, u.second);
                }
            }

            // Pour amount ap from Jug 1 to Jug2
            c = u.first - ap;
            d = u.second + ap;

            // check if this state is possible or not
            if ((c == 0 ) || d == b)
            {
                if (m[pii(c, d)] != 1)
                {
                    q.push(pii(c, d));
                    parent[pii(c, d)] = pii(u.first, u.second);
                }
            }
        }
        if (m[pii(u.first, 0)] != 1)
        {
            q.push(pii(u.first, 0)); // Empty Jug2
            parent[pii(u.first, 0)] = pii(u.first, u.second);
        }
        if (m[pii(0, u.second)] != 1)
        {
            q.push(pii(0, u.second)); // Empty Jug1
            parent[pii(0, u.second)] = pii(u.first, u.second);
        }
    }

    // No, solution exists if ans=0
    return -1;
}

// Driver code
int main()
{
    int Jug1 = 6, Jug2 = 8, target = 4;
    // cout << "Path from initial state "
    //         "to solution state :\n";
    cin >> Jug1 >> Jug2 >> target;
    cout << BFS(Jug1, Jug2, target);
    return 0;
}
