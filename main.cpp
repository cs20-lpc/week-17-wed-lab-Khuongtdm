// Implement main program.
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
struct Edge
{
	int target;
	int weight;
};

typedef pair<int, int> iPair;

void dijkstra(const vector<vector<Edge>>& graph, int source) {
	int numVertices = graph.size();
	vector<int> distance(numVertices, INT_MAX);
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

	distance[source] = 0;
	pq.push({ 0,source});

	while (!pq.empty())
	{
		int u = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if (d > distance[u]) continue;
		for (const auto& edge : graph[u])
		{
			int v = edge.target;
			int w = edge.weight;

			if (distance[u] + w < distance[v])
			{
				distance[v] = distance[u] + w;
				pq.push({ distance[v], v });
			}
		}
		// Print the calculated shortest distances
		cout << "Shortest distances from source node " << source << ":\n";
		for (int i = 0; i < numVertices; ++i) {
			cout << "  To node " << i << " -> ";
			if (distance[i] == INT_MAX) {
				cout << "Unreachable\n";
			}
			else {
				cout << distance[i] << "\n";
			}
		}
	}
}
int main()
{
	int numVertices = 6;
	vector<vector<Edge>> graph(numVertices);

	
	graph[0].push_back({ 1, 4 });
	graph[0].push_back({ 2, 9 });
	graph[0].push_back({ 4, 2 });

	graph[1].push_back({ 3, 1 });
	graph[1].push_back({ 2, 2 });

	graph[2].push_back({ 3, 7 });
	graph[2].push_back({ 5, 4 });

	graph[3].push_back({ 5, 1 });

	graph[4].push_back({ 2, 3 });
	graph[4].push_back({ 5, 8 });

	cout << "From 0 to other nodes \n";
	dijkstra(graph, 0);

	cout << "From 1 to other nodes \n";
	dijkstra(graph, 1);

	return 0;
}

