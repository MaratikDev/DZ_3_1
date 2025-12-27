

#ifndef DZ3_MATRIXGRAPH_H
#define DZ3_MATRIXGRAPH_H


#include "IGraph.h"


class MatrixGraph : public IGraph {
public:
    explicit MatrixGraph(int vertices);
    MatrixGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<bool>> matrix;
};


#endif //DZ3_MATRIXGRAPH_H