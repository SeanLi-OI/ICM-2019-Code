#ifndef MAPCORE
#define MAPCORE
#include <cstring>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
const int MAXM = 5000;
const int MAXN = 1000;
const int C0 = 500000; // max CAP
class Mapcore
{
private:
  struct Edge
  {
    int to, next, cap, flow;
    double length;
  } edge[MAXM];
  int head[MAXN];
  int gap[MAXN], dep[MAXN], pre[MAXN], cur[MAXN];
  int input[MAXN], output[MAXN];
  int ef[MAXN], P;
  int sap(int start, int end, int N);
  string name[MAXN];
  void clean();

public:
  int start_node, end_node, node_num;
  int tol;
  void init();
  int add_node(string _name);
  void add_edge(int u, int v, int w, double length);
  void maxflow();
};
#endif