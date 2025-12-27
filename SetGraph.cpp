#include "SetGraph.h"

SetGraph::SetGraph(int vertices)
    : adjacency(vertices) {}

SetGraph::SetGraph(const IGraph& graph)
    : adjacency(graph.VerticesCount()) {
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        for (int to : graph.GetNextVertices(v)) {
            AddEdge(v, to);
        }
    }
}

void SetGraph::AddEdge(int from, int to) {
    adjacency[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return adjacency.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    return std::vector<int>(adjacency[vertex].begin(), adjacency[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < adjacency.size(); ++from) {
        if (adjacency[from].count(vertex))
            result.push_back(from);
    }
    return result;
}
