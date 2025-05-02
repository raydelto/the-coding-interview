#include <algorithm>  // for reverse
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
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

unordered_set<Vertex*> visited;

vector<Vertex*> getShortestPath(Vertex* source, Vertex* destination) {
  if (source == nullptr || destination == nullptr)
    return {};
  unordered_map<Vertex*, Vertex*> parent;
  unordered_set<Vertex*> visited;
  queue<Vertex*> q;

  q.push(source);
  visited.insert(source);
  parent[source] = nullptr;

  while (!q.empty()) {
    Vertex* current = q.front();
    q.pop();

    if (current == destination) {
      break;
    }

    for (const Edge& edge : current->edges) {
      if (visited.find(edge.to) == visited.end()) {
        visited.insert(edge.to);
        parent[edge.to] = current;
        q.push(edge.to);
      }
    }
  }

  if (visited.find(destination) == visited.end()) {
    return {};
  }

  vector<Vertex*> path;
  for (Vertex* at = destination; at != nullptr; at = parent[at]) {
    path.push_back(at);
  }

  reverse(path.begin(), path.end());
  return path;
}

int main() {
  /* Example Graph Structure:
     A
   / \
  B   C
   \ / \
    D   \
     \   \
      \   \
         E
*/
  Vertex a("A"), b("B"), c("C"), d("D"), e("E");

  a.addEdge(&b, 1);
  a.addEdge(&c, 1);
  b.addEdge(&d, 1);
  c.addEdge(&d, 1);
  c.addEdge(&e, 1);
  d.addEdge(&e, 1);

  Vertex* start = &a;
  Vertex* destination = &e;

  vector<Vertex*> path = getShortestPath(start, destination);

  if (path.empty()) {
    cout << "No path found.\n";
  } else {
    cout << "Shortest path from " << start->name << " to " << destination->name
         << " is: ";
    for (const auto& vertex : path) {
      cout << vertex->name << " ";
    }
    cout << "\n";
  }

  return 0;
}
