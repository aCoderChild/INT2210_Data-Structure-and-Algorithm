/*
Euclidean graph: vertices are points in the euclidean plane

1. use a more efficient priority queue: k - d tree or ball tree to store the vertices
2. Exploit the triangle inequality: 
*/

/*
#include <bits/stdc++.h>
// Define a struct to represent a vertex in the graph
struct Vertex {
    int x, y; // coordinates
    int id; // unique identifier
    double distance; // distance from the source vertex
    Vertex* previous; // previous vertex in the shortest path
};

// Define a struct to represent an edge in the graph
struct Edge {
    Vertex* source;
    Vertex* target;
    double weight; // Euclidean distance between source and target
};

// Define a class to represent the graph
class Graph {
public:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;

    // Add a vertex to the graph
    void addVertex(int x, int y) {
        Vertex v;
        v.x = x;
        v.y = y;
        v.id = vertices.size();
        vertices.push_back(v);
    }

    // Add an edge to the graph
    void addEdge(int sourceId, int targetId) {
        Edge e;
        e.source = &vertices[sourceId];
        e.target = &vertices[targetId];
        e.weight = std::hypot(e.target->x - e.source->x, e.target->y - e.source->y);
        edges.push_back(e);
    }

    // Run Dijkstra's algorithm to find the shortest path from source to target
    std::vector<Vertex*> dijkstra(int sourceId, int targetId) {
        // Create a priority queue to store vertices to be processed
        std::priority_queue<std::pair<double, Vertex*> > queue;

        // Initialize the distance and previous vertex for each vertex
        for (Vertex& v : vertices) {
            v.distance = std::numeric_limits<double>::max();
            v.previous = nullptr;
        }

        // Set the distance of the source vertex to 0 and add it to the queue
        vertices[sourceId].distance = 0;
        queue.push(std::make_pair(0, &vertices[sourceId]));

        while (!queue.empty()) {
            // Extract the vertex with the minimum distance from the queue
            double distance = queue.top().first;
            Vertex* vertex = queue.top().second;
            queue.pop();

            // If we've reached the target vertex, construct the shortest path
            if (vertex->id == targetId) {
                std::vector<Vertex*> path;
                while (vertex != nullptr) {
                    path.push_back(vertex);
                    vertex = vertex->previous;
                }
                std::reverse(path.begin(), path.end());
                return path;
            }

            // Iterate over the neighbors of the current vertex
            for (Edge& e : edges) {
                if (e.source == vertex) {
                    // Compute the tentative distance
                    double tentativeDistance = distance + e.weight;

                    // If the neighbor is not in the queue or the tentative distance is shorter
                    if (e.target->distance > tentativeDistance) {
                        // Update the distance and previous vertex
                        e.target->distance = tentativeDistance;
                        e.target->previous = vertex;

                        // Add the neighbor to the queue
                        queue.push(std::make_pair(tentativeDistance, e.target));
                    }
                }
            }
        }

        // If the target vertex is not reachable, return an empty path
        return {};
    }
};

//for testing
int main() {
    Graph graph;

    // Add vertices to the graph
    graph.addVertex(0, 0);
    graph.addVertex(3, 4);
    graph.addVertex(6, 8);
    graph.addVertex(9, 12);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(0, 3);

    // Run Dijkstra's algorithm to find the shortest path from vertex 0 to vertex 3
    std::vector<Vertex*> path = graph.dijkstra(0, 3);

    // Print the shortest path
    for (Vertex* v : path) {
        std::cout << "(" << v->x << ", " << v->y << ")" << std::endl;
    }

    return 0;
}
*/