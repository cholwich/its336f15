import java.util.List;
import java.util.ArrayList;

public class EightQueen implements State {
  int[] board;
  int lastQueen;

  public EightQueen() {
    board = new int[8];
    for(int i=0; i<8; i++)
      board[i] = 0;
    lastQueen = 0;
  }

  public EightQueen(int[] b, int l) {
    board = new int[8];
    for(int i=0; i<8; i++)
      board[i] = b[i];
    lastQueen = l;
  }

  public String toString() {
    String s = "[";
    for(int i=0; i<7; i++) {
      s += board[i] + ", ";
    }
    s += board[7] + "]";
    return s;
  }

  public Boolean isGoal() {
    return false;
  }

  public List<Successor> successors() {
    return new ArrayList<Successor>();
  }
}
