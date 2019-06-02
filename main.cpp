#include "ff.h"
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
  int v,e;
  cin >> v >> e;
  FordFulkerson ff = FordFulkerson(v,e);
  // ff.BFS(2);
  // ff.print_matrix();
  return 0;
}
