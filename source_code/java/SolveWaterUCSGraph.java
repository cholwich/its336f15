public class SolveWaterUCSGraph {
  public static void main(String[] args) {
    State s0 = new Water(0, 0);
    UCSGraph s = new UCSGraph();
    Node n = s.search(s0);
    if (n != null) {
      System.out.println("Solution");
      System.out.println("========");
      n.printSolution();
      System.out.println("========");
      System.out.println("Depth = " + n.depth + ", Cost = " + n.cost);
      System.out.println("No. of Visited Nodes = " + s.nvisited);
    }
  }
}
