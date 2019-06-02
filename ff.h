#include <bits/stdc++.h>

using namespace std;


class FordFulkerson {
private:
  int vertices, edges;
  int** adj_m;//adjecency matrix
  int* visited;//keeps track of visited vertices
public:
  FordFulkerson(int v, int e);
  ~FordFulkerson();
  void BFS(int start_v);//receives the vertice from which the BFS will start
  void print_matrix();
};
