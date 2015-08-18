public class Successor {
  public State state;
  public String action;
  public int cost;

  public Successor(State s, String a, int c) {
    state = s;
    action = a;
    cost = c;
  }

  public String toString() {
    return "(" + state + ", " + action + ", " + cost + ")";
  }
}
