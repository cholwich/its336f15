#include"successor.h"

successor new_successor(void *state, char *action, int cost) {
  successor s;
  s.state = state;
  s.action = action;
  s.cost = cost;
  return s;
}
