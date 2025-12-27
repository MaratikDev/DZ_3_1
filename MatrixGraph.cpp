#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int vertices)
    : matrix(vertices, std::vector<bool>(vertices, false)) {}

MatrixGraph::MatrixGraph(const IGraph& graph)
    : matrix(graph.VerticesCount(), std::vector<bool>(graph.VerticesCount(), false)) {
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        for (int to : graph.GetNextVertices(v)) {
            AddEdge(v, to);
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (int to = 0; to < matrix.size(); ++to) {
        if (matrix[vertex][to])
            result.push_back(to);
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (int from = 0; from < matrix.size(); ++from) {
        if (matrix[from][vertex])
            result.push_back(from);
    }
    return result;
}
