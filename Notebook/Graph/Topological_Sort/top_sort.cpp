/* Toplogical sort algorithm (Kahn's). Takes a graph of in edges and a graph of out_edges
 * Running time: O(E + V)
 */

#include <vector>
#include <limits>
#include <map>
#include <queue>

using namespace std;

typedef vector<map<int, int>> graph;

bool cycle = false;

vector<int> top_sort(vector<int> &in, graph &out) {
    vector<int> order;
    queue<int> next;

    for (int i = 0; i < in.size(); ++i) {
        if (in[i] == 0) next.push(i);
    }

    while (!next.empty()) {
        int cur = next.front(); next.pop();
        order.push_back(cur);
        for (auto e : out[cur]) {
            int v = e.first;
            --in[v];
            if (in[v] == 0) {
                next.push(v);
            }
        }
    }

    for (int i = 0; i < in.size(); ++i) {
        if (in[i] > 0) {
            cycle = true;
            break;
        }
    }

    return order;
}
