#include "max_flow.h"
#include <bits/stdc++.h>

using namespace std;
int main(int argc, char const *argv[]) {
  int v,e;
  cin >> v >> e;
  MaxFlow ff = MaxFlow(v,e);
  int flux = MAX;
  for (int i = v; i > 0; --i)
  {
  	ff.FordFulkerson(0,i);
  	if (ff.get_flow() < flux && ff.get_flow()!=0)
  	{
  		flux = ff.get_flow();
  		ff.get_cut();
  	}
  }
  // after we find the correct s,t and flow, print output
  ff.set_flow(flux);
  ff.print_output();


  return 0;
}
