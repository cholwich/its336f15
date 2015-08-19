import java.util.ArrayList;
import java.util.List;

public class BFSTree {
  public int nvisited;

  public Node search(State s0) {
    Node n0 = new Node(s0, null, null, 0, 0);
    nvisited = 0;
    ArrayList<Node> frontier = new ArrayList<Node>();
    frontier.add(n0);
    while(true) {
      if (frontier.isEmpty()) {
        return null;
      }
      else {
        Node n = frontier.remove(0);
        nvisited++;
        if (n.state.isGoal()) {
          return n;
        }
        else {
          List<Successor> succs = n.state.successors();
          for(Successor s : succs) {
            Node p = new Node(s.state, n, s.action,
                n.cost+s.cost, n.depth+1);
            frontier.add(p);
          }
        }
      }
    }
  }
}
