#include <bits/stdc++.h>
#include "ff.h"
using namespace std;


MaxFlow::MaxFlow(int v, int e){
  int src,trg,w;
  this->max_flow = 0;
  this->vertices = v;
  this->edges = e;
  //original graph
  this->adj_m = (int**) malloc(sizeof(int*) * this->vertices);
  for (int i = 0; i < this->vertices; i++) {
    this->adj_m[i] = (int*) malloc(sizeof(int) * this->vertices);
  }
  //residual graph
  this->residual_graph = (int**) malloc(sizeof(int*) * this->vertices);
  for (int i = 0; i < this->vertices; i++) {
    this->residual_graph[i] = (int*) malloc(sizeof(int) * this->vertices);
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

MaxFlow::~MaxFlow(){
  for (int i = 0; i < this->vertices; i++) {
    free(this->adj_m[i]);
  }
  free(this->adj_m);

  for (int i = 0; i < this->vertices; i++) {
    free(this->residual_graph[i]);
  }
  free(this->residual_graph);


  free(this->visited);
}

bool MaxFlow::BFS(int s, int t){
  queue <int> q;
  int v;
  q.push(s);
  // cout << s << endl;
  this->visited[s] = -1;//-1 means the node was visited
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (int i = 0; i < this->vertices; i++) {
      if (this->adj_m[v][i] != 0) {//if there's a edge between v and i
        if (this->visited[i]==0) {//if wasn't visited
          // cout << i << endl;
          this->visited[i] = -1;
          q.push(i);
        }
      }
    }
  }
  return (this->visited[t] == -1);
}

int MaxFlow::FordFulkerson(int s, int t){
  while (this->BFS(s,t)) {
    cout << "verdade" << endl;
  }
}