#include<stdio.h>
#include<stdlib.h>
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
  else
    return 0;
}

void successors(water *w, successor **list) {
  int idx = 0;
  int a = 3 - w->x;
  int b = 5 - w->y;

  *list = (successor *)calloc(8, sizeof(successor));
  for(int i=0; i<8; i++) {
    (*list)[i].state = NULL;
  }
  
  if (w->x > 0) {
    (*list)[idx].state = new_water(0, w->y);
    (*list)[idx].action = "Empty {3}";
    (*list)[idx].cost = w->x;
    idx++;
  }
  if (w->y > 0) {
    (*list)[idx].state = new_water(w->x, 0);
    (*list)[idx].action = "Empty {5}";
    (*list)[idx].cost = w->y;
    idx++;
  }
  if (w->x < 3) {
    (*list)[idx].state = new_water(3, w->y);
    (*list)[idx].action = "Fill up {3}";
    (*list)[idx].cost = 3 - w->x;
    idx++;
  }
  if (w->y < 5) {
    (*list)[idx].state = new_water(w->x, 5);
    (*list)[idx].action = "Fill up {5}";
    (*list)[idx].cost = 5 - w->y;
    idx++;
  }
  if (w->x > 0 && w->x < 3) {
    if (w->y >= a) {
      (*list)[idx].state = new_water(3, w->y - a);
      (*list)[idx].action = "Pour {5} -> {3}";
      (*list)[idx].cost = a;
      idx++;
    }
    else {
      (*list)[idx].state = new_water(w->x + w->y, 0);
      (*list)[idx].action = "Pour {5} -> {3}";
      (*list)[idx].cost = w->y;
      idx++;
    }
  }
  if (w->y > 0 && w->y < 5) {
    if (w->x >= b) {
      (*list)[idx].state = new_water(w->x - b, 5);
      (*list)[idx].action = "Pour {3} -> {5}";
      (*list)[idx].cost = b;
      idx++;
    }
    else {
      (*list)[idx].state = new_water(0, w->x + w->y);
      (*list)[idx].action = "Pour {3} -> {5}";
      (*list)[idx].cost = w->x;
      idx++;
    }
  }
}
