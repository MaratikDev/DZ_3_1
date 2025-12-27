#include <functional>
#include <iostream>
#include <queue>

#include "ArcGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

void PrintAllEdges(const IGraph& graph);
void BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &func);
void mainBFS(const IGraph &graph, const std::function<void(int)> &func);
void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &func);
void mainDFS(const IGraph &graph, const std::function<void(int)> &func);

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
    mainBFS(listGraph,[](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n";

    std::cout << "DFS listGraph: ";
    mainDFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n\n";

    std::cout << "BFS matrixGraph: ";
    mainBFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n";

    std::cout << "DFS matrixGraph: ";
    mainDFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n\n";

    std::cout << "BFS arcGraph: ";
    mainBFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n";

    std::cout << "DFS arcGraph: ";
    mainDFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n\n";

    std::cout << "BFS setGraph: ";
    mainBFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << "\n";

    std::cout << "DFS setGraph: ";
    mainDFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
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

void BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &func)
{
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty())
    {
        int currentVertex = qu.front();
        qu.pop();

        func(currentVertex);

        for (int nextVertex: graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

void mainBFS(const IGraph &graph, const std::function<void(int)> &func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
        {
            BFS(graph, i, visited, func);
        }
    }
}

void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &func)
{
    visited[vertex] = true;
    func(vertex);

    for (int nextVertex: graph.GetNextVertices(vertex))
    {
        if (!visited[nextVertex])
        {
            DFS(graph, nextVertex, visited, func);
        }
    }
}

void mainDFS(const IGraph &graph, const std::function<void(int)> &func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i)
    {
        if (!visited[i])
        {
            DFS(graph, i, visited, func);
        }
    }
}


