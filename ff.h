#include <bits/stdc++.h>

using namespace std;


class FordFulkerson {
private:
  int vertices, edges;
  int** adj_m;
public:
  FordFulkerson(int v, int e);
  ~FordFulkerson();
  void BFS();
  void print_matrix();
};
