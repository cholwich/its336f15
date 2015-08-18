#include<stdio.h>
#include<stdlib.h>
#include"successor.h"
#include"water.h"

int main() {
  water *w = new_water(0, 0);
  successor *l;

  printf("isgoal? ");
  if (is_goal(w))
    printf("true\n");
  else
    printf("false\n");

  successors(w, &l);
  for(int i=0; l[i].state != NULL; i++) {
    print_water(l[i].state);
    printf(", %s, %d\n", l[i].action, l[i].cost);
    free(l[i].state);
  }
  free(l);
  free(w);
  printf("-----\n");

  w = new_water(3, 0);
  successors(w, &l);
  for(int i=0; l[i].state != NULL; i++) {
    print_water(l[i].state);
    printf(", %s, %d\n", l[i].action, l[i].cost);
    free(l[i].state);
  }
  free(l);
  free(w);

  return 0;
}
