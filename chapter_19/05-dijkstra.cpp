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

vector<Vertex*> dijkstra(Vertex* start, Vertex* end) {
  unordered_map<Vertex*, int> distances;
  unordered_map<Vertex*, Vertex*> previous;

  priority_queue<pair<int, Vertex*>, vector<pair<int, Vertex*>>, greater<>> pq;

  vector<Vertex*> path;

  distances[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int currentDist = pq.top().first;
    Vertex* currentVertex = pq.top().second;
    pq.pop();

    if (currentVertex == end)
      break;

    if (distances.find(currentVertex) != distances.end() &&
        currentDist > distances[currentVertex])
      continue;

    for (const Edge& edge : currentVertex->edges) {
      int newDist = distances[currentVertex] + edge.weight;
      if (distances.find(edge.to) == distances.end() ||
          newDist < distances[edge.to]) {
        distances[edge.to] = newDist;
        previous[edge.to] = currentVertex;
        pq.push({newDist, edge.to});
      }
    }
  }

  if (distances.find(end) == distances.end()) {
    return path;  // No path exists
  }

  // Reconstruct the shortest path
  for (Vertex* at = end; at != nullptr; at = previous[at]) {
    path.push_back(at);
  }
  reverse(path.begin(), path.end());
  return path;
}

int main() {
  /* Example Graph Structure:
            
    A -(1)-->B-(2)-> D
     \            /    \
     (2)        (4)      (1)
       \       /          \
        --> C -----(5)-----> E
             
*/
  Vertex a("A"), b("B"), c("C"), d("D"), e("E");

  a.addEdge(&b, 1);
  a.addEdge(&c, 2);
  b.addEdge(&d, 2);
  c.addEdge(&d, 4);
  c.addEdge(&e, 5);
  d.addEdge(&e, 1);

  Vertex* start = &a;
  Vertex* destination = &e;

  vector<Vertex*> path = dijkstra(start, destination);

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
