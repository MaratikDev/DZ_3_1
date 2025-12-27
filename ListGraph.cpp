#include "ListGraph.h"

ListGraph::ListGraph(int vertices)
    : adjacency(vertices) {}

ListGraph::ListGraph(const IGraph& graph)
    : adjacency(graph.VerticesCount()) {
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        for (int to : graph.GetNextVertices(v)) {
            AddEdge(v, to);
        }
    }
}


void ListGraph::AddEdge(int from, int to) {
    adjacency[from].push_back(to);
}

int ListGraph::VerticesCount() const {
    return adjacency.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    return adjacency[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < adjacency.size(); ++from) {
        for (int to : adjacency[from]) {
            if (to == vertex)
                result.push_back(from);
        }
    }
    return result;
}
