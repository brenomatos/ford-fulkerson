#include <bits/stdc++.h>
#include "ff.h"
using namespace std;


FordFulkerson::FordFulkerson(int v, int e){
  int src,trg,w;

  this->vertices = v;
  this->edges = e;
  this->adj_m = (int**) malloc(sizeof(int*) * this->vertices);
  for (int i = 0; i < this->vertices; i++) {
    this->adj_m[i] = (int*) malloc(sizeof(int) * this->vertices);
  }

  this->visited = (int*) malloc(sizeof(int) * this->vertices);
  for (int i = 0; i < this->vertices; i++) {//start all vertices as unvisited
    this->visited[i] = 0;
  }

  for (int i = 0; i < this->edges; i++) {
    cin >> src >> trg >> w;
    this->adj_m[src][trg] = w;
  }

}

FordFulkerson::~FordFulkerson(){
  for (int i = 0; i < this->vertices; i++) {
    free(this->adj_m[i]);
  }
  free(this->adj_m);

  free(this->visited);
}

void FordFulkerson::BFS(int start_v){
  queue <int> q;
  int v;
  q.push(start_v);
  cout << start_v << endl;
  this->visited[start_v] = -1;//-1 means the node was visited
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (int i = 0; i < this->vertices; i++) {
      if (this->adj_m[v][i] != 0) {//if there's a edge between v and i
        if (this->visited[i]==0) {//if wasn't visited
          cout << i << endl;;
          this->visited[i] = -1;
          q.push(i);
        }
      }
    }
  }
}
// void FordFulkerson::print_matrix(){
//     for (int i = 0; i < this->vertices; i++) {
//       for (int j = 0; j < this->vertices; j++) {
//         cout << this->adj_m[i][j] << " ";
//       }
//       cout << endl;
//     }
// }
