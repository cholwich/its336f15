import java.util.ArrayList;
import java.util.List;
import java.util.HashSet;

public class BFSGraph {
  public int nvisited;

  public Node search(State s0) {
    Node n0 = new Node(s0, null, null, 0, 0);
    nvisited = 0;
    ArrayList<Node> frontier = new ArrayList<Node>();
    HashSet<String> explored = new HashSet<String>();
    frontier.add(n0);
    while(true) {
      if (frontier.isEmpty()) {
        return null;
      }
      else {
        Node n = frontier.remove(0);
        explored.add(n.state.toString());
        nvisited++;
        if (n.state.isGoal()) {
          return n;
        }
        else {
          List<Successor> succs = n.state.successors();
          for(Successor s : succs) {
            if (!explored.contains(s.state.toString()) &&
                !containsState(s.state, frontier)) { 
              Node p = new Node(s.state, n, s.action, n.cost+s.cost, n.depth+1);
              frontier.add(p);
            }
          }
        }
      }
    }
  }

  public boolean containsState(State s, List<Node> l) {
    for(Node n : l) {
      if (n.state.toString().equals(s.toString())) {
        return true;
      }
    }
    return false;
  }
}
