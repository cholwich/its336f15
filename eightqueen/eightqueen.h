typedef struct {
  int board[8];
  int lastqueen;
} eightqueen;

eightqueen *new_empty_board();
eightqueen *new_board(int *b, int l);
int is_goal(eightqueen *e);
void successors(eightqueen *e, successor **list);
void print_board(eightqueen *e);
