#include<stdio.h>
#include<stdlib.h>
#include"successor.h"
#include"eightqueen.h"

int main() {
  eightqueen *e = new_empty_board();
  successor *l;
  int b[] = {2,4,6,8,1,3,5,0};

  printf("State = ");
  print_board(e);

  printf("isgoal? ");
  if (is_goal(e))
    printf("true\n");
  else
    printf("false\n");

  successors(e, &l);
  for(int i=0; l[i].state != NULL; i++) {
    print_board(l[i].state);
    free(l[i].state);
  }
  free(l);
  free(e);
  printf("-----\n");

  e = new_board(b, 7);
  printf("State = ");
  print_board(e);

  printf("isgoal? ");
  if (is_goal(e))
    printf("true\n");
  else
    printf("false\n");

  successors(e, &l);
  for(int i=0; l[i].state != NULL; i++) {
  print_board(l[i].state);
    free(l[i].state);
  }
  free(l);
  free(e);

  return 0;
}
