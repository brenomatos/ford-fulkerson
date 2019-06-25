#include <bits/stdc++.h>
#define MAX INT_MAX
using namespace std;


class MaxFlow {
private:
  int vertices, edges, max_flow;
  int** adj_m;//adjecency matrix
  int** adj_m2;
  int** aux_graph;
  int* visited;//keeps track of visited vertices
  int* parent;
  int* cut; 
  int vertex_cut;
public:
  MaxFlow(int v, int e);
  ~MaxFlow();
  bool BFS(int s, int t);//s for source and t for sink
  int FordFulkerson(int s, int t);//returns max flow for the graph
  void init_matrixes();
  void read_input();
  void reset_matrix();
  int get_flow();
  void get_cut();
  void set_visited();
  void reset_visited();
  void reset_parent();
  void set_flow(int f);
  void augment_path(int s, int t);
  void print_output();
};
