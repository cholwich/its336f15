#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"successor.h"
#include"eightqueen.h"

eightqueen *new_empty_board() {
  eightqueen *e = (eightqueen *)malloc(sizeof(eightqueen));
  memset(e->board, 0, sizeof(int)*8);
  e->lastqueen = 0;
  return e;
}

eightqueen *new_board(int *b, int l) {
  eightqueen *e = (eightqueen *)malloc(sizeof(eightqueen));
  memcpy(e->board, b, sizeof(int)*8);
  e->lastqueen = l;
  return e;
}

int is_goal(eightqueen *e) {
  if (e->lastqueen == 8)
    return 1;
  return 0;
}

void successors(eightqueen *e, successor **list) {
  int idx = 0;
  
  *list = (successor *)calloc(8, sizeof(successor));
}

void print_board(eightqueen *e) {
  int i;
  printf("[");
  for(i=0; i<7; i++)
    printf("%d, ", e->board[i]);
  printf("%d]\n", e->board[7]);
}
