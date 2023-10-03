#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Subset {
    int parent;
    int rank;
};

struct Edge {
    int src;
    int dest;
    int weight;
};

class Graph {
    private:
        vector<Subset> subsets;
        vector<Edge> edges;
    
    public:
        Graph(int v) {
            for (int i = 0; i <= v; i++) {
                Subset subset = {i, 0};
                subsets.push_back(subset);
            }
        }

        void reset() {
            for (int i = 0; i <= subsets.size(); i++) {
                subsets[i].parent = i;
                subsets[i].rank = 0;
            }
        }

        void addEdge(int src, int dest, int weight) {
            Edge edge = {src, dest, weight};
            edges.push_back(edge);
        }

    public:
        static bool compareEdges(Edge& a, Edge& b) {
            return a.weight < b.weight;
        }
        static bool reverseCompareEdges(Edge& a, Edge& b) {
            return a.weight > b.weight;
        }
    
    public:
        int findRoot(int i) {
            if (subsets[i].parent != i) {
                subsets[i].parent = findRoot(subsets[i].parent);
            }
            return subsets[i].parent;
        }

    private:
    void unionSets(int xRoot, int yRoot) {
        if (subsets[xRoot].rank > subsets[yRoot].rank) {
            subsets[yRoot].parent = xRoot;
        } else if (subsets[xRoot].rank < subsets[yRoot].rank) {
            subsets[xRoot].parent = yRoot;
        } else {
            subsets[yRoot].parent = xRoot;
            subsets[xRoot].rank++;
        }
    }

    public:
    long long kruskal(bool reverse) {
        int cost = subsets.size() - 2;
        
        sort(edges.begin(), edges.end(), reverse ? reverseCompareEdges : compareEdges);
        
        for (auto edge : edges) {
            int xRoot = findRoot(edge.src);
            int yRoot = findRoot(edge.dest);

            if (xRoot != yRoot) {
                unionSets(xRoot, yRoot);
                cost -= edge.weight;
            }
        }

        return cost;
    }

};
int main() {
    int N, M;
    // cin >> N >> M;
    scanf("%d %d", &N, &M);
    Graph graph(N+1);

    for (int i = 0; i <= M; i++) {
        int A, B, C;
        // cin >> A >> B >> C;
        scanf("%d %d %d", &A, &B, &C);

        graph.addEdge(A, B, C);
    }

    auto a = graph.kruskal(false);
    graph.reset();
    auto b = graph.kruskal(true);

    printf("%lld", a*a - b*b);
}