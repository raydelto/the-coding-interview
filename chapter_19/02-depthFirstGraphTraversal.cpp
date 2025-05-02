#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

struct Edge;

struct Vertex {
  string name;
  vector<Edge> edges;

  Vertex(const string& n) : name(n) {}

  void addEdge(Vertex* to, int weight) { edges.emplace_back(this, to, weight); }
};

struct Edge {
  Vertex* from;
  Vertex* to;
  int weight;

  Edge(Vertex* f, Vertex* t, int w) : from(f), to(t), weight(w) {}
};

void DFS(Vertex* start, unordered_set<Vertex*>& visited) {
  if (visited.find(start) != visited.end()) {
    return;
  }

  cout << "Visited: " << start->name << "\n";
  visited.insert(start);

  for (const auto& edge : start->edges) {
    DFS(edge.to, visited);
  }
}

int main() {
  /*
 Example Graph Structure:
     A
    / \
   B   C
    \ /
     D
     |
     E
 */
  Vertex a("A"), b("B"), c("C"), d("D"), e("E");

  a.addEdge(&b, 1);
  a.addEdge(&c, 1);
  b.addEdge(&d, 1);
  c.addEdge(&d, 1);
  d.addEdge(&e, 1);

  unordered_set<Vertex*> visited;
  DFS(&a, visited);

  return 0;
}
