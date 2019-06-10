#include "ff.h"
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
  int v,e;
  cin >> v >> e;
  MaxFlow ff = MaxFlow(v,e);
  cout << ff.BFS(2,3) << endl;

  return 0;
}
