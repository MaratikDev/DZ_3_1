#include "ArcGraph.h"

ArcGraph::ArcGraph(int vertices)
    : vertexCount(vertices) {}

ArcGraph::ArcGraph(const IGraph& graph)
    : vertexCount(graph.VerticesCount()) {
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        for (int to : graph.GetNextVertices(v)) {
            ArcGraph::AddEdge(v, to);
        }
    }
}

void ArcGraph::AddEdge(int from, int to) {
    edges.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return vertexCount;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto& e : edges) {
        if (e.first == vertex)
            result.push_back(e.second);
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (auto& e : edges) {
        if (e.second == vertex)
            result.push_back(e.first);
    }
    return result;
}
