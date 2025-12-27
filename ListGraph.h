

#ifndef DZ3_LISTGRAPH_H
#define DZ3_LISTGRAPH_H


#include "IGraph.h"


class ListGraph : public IGraph {
public:
    explicit ListGraph(int vertices);
    ListGraph(const IGraph& graph);


    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacency;
};


#endif //DZ3_LISTGRAPH_H