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
}


void FordFulkerson::print_matrix(){
    for (int i = 0; i < this->vertices; i++) {
      for (int j = 0; j < this->vertices; j++) {
        cout << this->adj_m[i][j] << " ";
      }
      cout << endl;
    }
}
