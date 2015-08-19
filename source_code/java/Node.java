import java.util.ArrayDeque;

public class Node implements Comparable<Node> {
  State state;
  Node parent;
  String action;
  int cost;
  int depth;

  public Node(State state, Node parent, String action, 
      int cost, int depth) {
    this.state = state;
    this.parent = parent;
    this.action = action;
    this.cost = cost;
    this.depth = depth;
  }
  
  public void printSolution() {
    Node n = this;
    ArrayDeque<String> l = new ArrayDeque<String>();
    while (n.parent != null) {
      l.push(n.action);
      n = n.parent;
    }
    for(String a : l) {
      System.out.println(a);
    }
  }

  public int compareTo(Node n) {
    return this.cost - n.cost;
  }
}
