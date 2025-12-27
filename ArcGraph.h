

#ifndef DZ3_ARCGRAPH_H
#define DZ3_ARCGRAPH_H


#include "IGraph.h"



class ArcGraph : public IGraph {
public:
    explicit ArcGraph(int vertices);
    ArcGraph(const IGraph& graph);

    void AddEdge(int from, int to) override;
    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

private:
    int vertexCount;
    std::vector<std::pair<int,int>> edges;
};


#endif //DZ3_ARCGRAPH_H