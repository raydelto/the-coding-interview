#include <queue>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

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

void BFS(Vertex* start) {
  queue<Vertex*> q;
  unordered_set<Vertex*> visited;
  q.push(start);
  visited.insert(start);

  while (!q.empty()) {
    Vertex* current = q.front();
    q.pop();
    cout << "Visited: " << current->name << "\n";

    for (const auto& edge : current->edges) {
      if (visited.find(edge.to) == visited.end()) {
        visited.insert(edge.to);
        q.push(edge.to);
      }
    }
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

  cout << "Breadth-First Graph Traversal starting from vertex A:\n";
  BFS(&a);

  return 0;
}
