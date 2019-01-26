#ifndef SOLVE
#define SOLVE
#include <stdio.h>
#include <string>
#include <cstring>
#include <map>
#include <iostream>
#include "mapcore.h"
using namespace std;
const double C1 = 1.0; //ROOM: C1 = area / Length
const double C2 = 1.0; // PATH: C2 = Cap / length
const double C3 = 1.0; // PATH: C3 = Length / length
const double C4 = 100; // STAIRS: Cap
const double C5 = 10;  // STAIRS: Length
const string floor_name[] = {"", "-0", "-1"};

class Solve
{
private:
  map<string, int> id;
  Mapcore mapcore;
  int floor_check(string name, int floor_id);
  int id_find(string name, int floor_id);

public:
  void init();
  void input();
  void solve();
};
#endif