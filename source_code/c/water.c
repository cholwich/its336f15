#include<stdio.h>
#include<stdlib.h>
#include"successor.h"
#include"water.h"

water *new_water(int x, int y) {
  water *w = (water *)malloc(sizeof(water));
  w->x = x;
  w->y = y;
  return w;
}

void print_water(water *w) {
  printf("[%d,%d]", w->x, w->y);
}

int is_goal(water *w) {
  if (w->y == 4) 
    return 1;
  return 0;
}

void successors(water *w, successor **list) {
  int idx = 0;
  int a = 3 - w->x;
  int b = 5 - w->y;

  *list = (successor *)calloc(8, sizeof(successor));
  
  if (w->x > 0)
    (*list)[idx++] = new_successor(new_water(0, w->y), "Empty {3}", w->x);
  if (w->y > 0)
    (*list)[idx++] = new_successor(new_water(w->x, 0), "Empty {5}", w->y);
  if (w->x < 3)
    (*list)[idx++] = new_successor(new_water(3, w->y), "Fill up {3}", 3 - w->x);
  if (w->y < 5)
    (*list)[idx++] = new_successor(new_water(w->x, 5), "Fill up {5}", 5 - w->y);
  if (w->x < 3) {
    if (w->y >= a)
      (*list)[idx++] = new_successor(new_water(3, w->y - a), "Pour {5} -> {3}", a);
    else if (w->y > 0)
      (*list)[idx++] = new_successor(new_water(w->x + w->y, 0), "Pour {5} -> {3}", w->y);
  }
  if (w->y < 5) {
    if (w->x >= b)
      (*list)[idx++] = new_successor(new_water(w->x - b, 5), "Pour {3} -> {5}", b);
    else if (w->x > 0) 
      (*list)[idx++] = new_successor(new_water(0, w->x + w->y), "Pour {3} -> {5}", w->x);
  }
}
