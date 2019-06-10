#include <bits/stdc++.h>

using namespace std;


class MaxFlow {
private:
  int vertices, edges, max_flow;
  int** adj_m;//adjecency matrix
  int** residual_graph;
  int* visited;//keeps track of visited vertices
public:
  MaxFlow(int v, int e);
  ~MaxFlow();
  bool BFS(int s, int t);//s for source and t for sink
  int FordFulkerson(int s, int t);//returns max flow for the graph
  void print_matrix();
};