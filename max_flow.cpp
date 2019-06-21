#include <bits/stdc++.h>
#include "max_flow.h"
using namespace std;


MaxFlow::MaxFlow(int v, int e){
  this->max_flow = 0;
  this->vertices = v;
  this->edges = e;
  this->set_visited();
  this->init_matrixes();
  this->read_input();
  this->parent = (int*) malloc(sizeof(int) * this->vertices);

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
  free(this->parent);
}

void MaxFlow::init_matrixes(){
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
}

void MaxFlow::reset_visited(){
  for (int i = 0; i < this->vertices; ++i)
  {
    this->visited[i] = 0;
  }
}

void MaxFlow::reset_parent(){
 for (int i = 0; i < this->vertices; ++i)
  {
    this->parent[i] = 0;
  } 
}

void MaxFlow::augment_path(int s,int t){
  int aux_src, aux_trg, min_flow;
  std::vector<pair<int,int>> path;
  aux_trg = t;
  aux_src = this->parent[t];
  min_flow = this->adj_m[aux_src][aux_trg];
  while(aux_trg!=aux_src){
    if (min_flow < this->adj_m[aux_src][aux_trg]){
      min_flow = this->adj_m[aux_src][aux_trg];
    }
    path.push_back(make_pair(aux_src,aux_trg));
    aux_trg = aux_src;
    aux_src = this->parent[aux_trg];
  }
  for (int i = 0; i < path.size(); ++i)
  {
    //atualizando o grafo residual
    aux_src = path[i].first;
    aux_trg = path[i].second;
    this->adj_m[aux_src][aux_trg] -= min_flow;
    this->adj_m[aux_trg][aux_src] += min_flow;  
  }
  this->max_flow += min_flow;
}

void MaxFlow::read_input(){
  int src,trg,w;
  for (int i = 0; i < this->edges; i++) {
    cin >> src >> trg >> w;
    this->adj_m[src][trg] = w;
  }
}
void MaxFlow::set_visited(){
  this->visited = (int*) malloc(sizeof(int) * this->vertices);
  for (int i = 0; i < this->vertices; i++) {//start all vertices as unvisited
    this->visited[i] = 0;
  }
}

bool MaxFlow::BFS(int s, int t){
  queue <int> q;
  int v;
  q.push(s);
  this->reset_visited();
  this->reset_parent();
  this->visited[s] = -1;//-1 means the node was visited
  this->parent[s] = s;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (int i = 0; i < this->vertices; i++) {
      if (this->adj_m[v][i] != 0) {//if there's a edge between v and i
        if (this->visited[i]==0) {//if wasn't visited
          this->visited[i] = -1;
          this->parent[i] = v;
          q.push(i);
        }
      }
    }
  }
  return (this->visited[t] == -1);
}

int MaxFlow::FordFulkerson(int s, int t){
  // copy original graph to residual
  // for (int i = 0; i < this->vertices; i++) {
  //   for (int j = 0; j < this->vertices; j++) {
  //     this->residual_graph[i][j] = this->adj_m[i][j];
  //   }
  // }
  while (this->BFS(s,t)) {
    // s temos caminho de s para t, atualizar os pesos
    augment_path(s, t);
    cout << this->max_flow;
  }

}
