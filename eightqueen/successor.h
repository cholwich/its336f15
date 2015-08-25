typedef struct {
  void *state;
  char *action;
  int  cost;
} successor;

successor new_successor(void *state, char *action, int cost);
