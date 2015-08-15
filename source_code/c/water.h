typedef struct {
  int x;
  int y;
} water;

typedef struct {
  void *state;
  char *action;
  int  cost;
} successor;

water *new_water(int x, int y);
int is_goal(water *w);
void successors(water *w, successor **list);
void print_water(water *w);
