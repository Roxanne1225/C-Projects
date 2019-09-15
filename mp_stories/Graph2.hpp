#include <queue>
#include <algorithm>
#include <string>
#include <list>

/**
 * Returns an std::list of vertex keys that creates any shortest path between `start` and `end`.
 *
 * This list MUST include the key of the `start` vertex as the first vertex in the list, the key of
 * the `end` vertex as the last element in the list, and an ordered list of all vertices that must
 * be traveled along the shortest path.
 *
 * For example, the path a -> c -> e returns a list with three elements: "a", "c", "e".
 *
 * You should use undirected edges. Hint: There are no edge weights in the Graph.
 *
 * @param start The key for the starting vertex.
 * @param end   The key for the ending vertex.
 */
template <class V, class E>
std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
  // TODO: Part 3
  std::list<std::string> path;
  	unordered_map<string, string> paths;
  	unordered_map<string, int> distance;

  queue<string> q;
  q.push(start);
  distance[start] = 0;
  for (auto ver : vertexMap){
    paths.insert(pair<string, string>(ver.first, ""));
    distance.insert(pair<string, int>(ver.first, -1));
  }
  while(!q.empty()) {
    string current = q.front();
    q.pop();
    for (auto adjacent : incidentEdges(current)) {
      if (distance[adjacent.get().source().key()] == -1) {
        distance[adjacent.get().source().key()] = distance[current] + 1;
        paths[adjacent.get().source().key()] = current;
        q.push(adjacent.get().source().key());
      }
      if (distance[adjacent.get().dest().key()] == -1) {
        distance[adjacent.get().dest().key()] = distance[current] + 1;
        paths[adjacent.get().dest().key()] = current;
        q.push(adjacent.get().dest().key());
      }
    }

  }

  	string cur = end;
  	while (cur != "") {
  		path.push_front(cur);
  		cur = paths[cur];
  	}
  	return path;

  return path;
}
