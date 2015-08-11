public class TestWater {
  public static void main(String args[]) {
    Water w = new Water(0, 0);
    System.out.println("isgoal? " + w.isGoal());
    for(Successor s : w.successors()) {
      System.out.println(s);
    }
    System.out.println("-----");
    w = new Water(3, 0);
    for(Successor s : w.successors()) {
      System.out.println(s);
    }

  }
}
