#include <iostream>
#include <vector>
#include <unordered_set>
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

unordered_set<Vertex*> visited;

bool pathExists(Vertex* current, Vertex* destination) {
  if (current == destination) {
    return true;
  }

  visited.insert(current);

  for (const Edge& edge : current->edges) {
    if (visited.find(edge.to) == visited.end()) {
      if (pathExists(edge.to, destination)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  /* Example Graph Structure:
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

  Vertex* start = &a;
  Vertex* destination = &e;

  if (pathExists(start, destination)) {
    cout << "Path exists from " << start->name << " to " << destination->name
         << "\n";
  } else {
    cout << "No path exists from " << start->name << " to " << destination->name
         << "\n";
  }

  return 0;
}
