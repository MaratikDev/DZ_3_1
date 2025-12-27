

#ifndef DZ3_SETGRAPH_H
#define DZ3_SETGRAPH_H


#include "IGraph.h"
#include <set>

class SetGraph : public IGraph {
public:
    explicit SetGraph(int vertices);
    SetGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<int>> adjacency;
};


#endif //DZ3_SETGRAPH_H