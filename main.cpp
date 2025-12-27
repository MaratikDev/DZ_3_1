#include <functional>
#include <iostream>
#include <queue>

#include "ArcGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

void PrintAllEdges(const IGraph& graph);
void BFS(const IGraph& graph, int start);
void DFS(const IGraph& graph, int start);

int main() {

    ListGraph listGraph(5);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(3, 4);


    MatrixGraph matrixGraph(listGraph);
    ArcGraph arcGraph(matrixGraph);
    SetGraph setGraph(arcGraph);
    ListGraph listGraph1(setGraph);

    std::cout << "Vertices count:\n";
    std::cout << listGraph.VerticesCount() << "\n";
    std::cout << matrixGraph.VerticesCount() << "\n";
    std::cout << arcGraph.VerticesCount() << "\n";
    std::cout << listGraph1.VerticesCount() << "\n";
    std::cout << setGraph.VerticesCount() << "\n\n";

    std::cout << "listGraph: " << "\n";
    PrintAllEdges(listGraph);

    std::cout << "matrixGraph: " << "\n";
    PrintAllEdges(matrixGraph);

    std::cout << "arcGraph: " << "\n";
    PrintAllEdges(arcGraph);

    std::cout << "setGraph: " << "\n";
    PrintAllEdges(setGraph);

    std::cout << "listGraph1: " << "\n";
    PrintAllEdges(listGraph1);


    std::cout << "BFS listGraph: ";
    BFS(listGraph, 0);
    std::cout << "\n";

    std::cout << "DFS listGraph: ";
    DFS(listGraph, 0);
    std::cout << "\n\n";

    std::cout << "BFS matrixGraph: ";
    BFS(matrixGraph, 0);
    std::cout << "\n";

    std::cout << "DFS matrixGraph: ";
    DFS(matrixGraph, 0);
    std::cout << "\n\n";

    std::cout << "BFS arcGraph: ";
    BFS(arcGraph, 0);
    std::cout << "\n";

    std::cout << "DFS arcGraph: ";
    DFS(arcGraph, 0);
    std::cout << "\n\n";

    std::cout << "BFS setGraph: ";
    BFS(setGraph, 0);
    std::cout << "\n";

    std::cout << "DFS setGraph: ";
    DFS(setGraph, 0);
    std::cout << "\n\n";

    return 0;
}

void PrintAllEdges(const IGraph& graph)
{
    int n = graph.VerticesCount();

    for (int from = 0; from < n; ++from)
    {
        std::vector<int> next = graph.GetNextVertices(from);
        for (int to : next)
        {
            std::cout << from << " -> " << to << "\n";
        }
    }
    std::cout << std::endl;
}

void BFS(const IGraph& graph, int start)
{
    int n = graph.VerticesCount();
    std::vector visited(n, 0);
    std::queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
       std::cout << v << " ";

        for (int to : graph.GetNextVertices(v)) {
            if (!visited[to]) {
                visited[to] = 1;
                q.push(to);
            }
        }
    }
}

void DFS(const IGraph& graph, int start)
{
    int n = graph.VerticesCount();
    std::vector<bool> visited(n, 0);

    std::function<void(int)> dfs = [&](int v) {
        visited[v] = 1;
        std::cout << v << " ";

        for (int to : graph.GetNextVertices(v)) {
            if (!visited[to]) {
                dfs(to);
            }
        }
    };

    dfs(start);
}


