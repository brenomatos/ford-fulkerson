#include "max_flow.h"
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
  int v,e;
  cin >> v >> e;
  MaxFlow ff = MaxFlow(v,e);
  for (int i = v; i > 0; --i)
  {
  	ff.FordFulkerson(0,i);
  }

  return 0;
}
