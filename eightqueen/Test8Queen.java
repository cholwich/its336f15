public class Test8Queen {
  public static void main(String[] args) {
    EightQueen s = new EightQueen();
    System.out.println("State = " + s);
    System.out.println("isgoal? " + s.isGoal());
    for(Successor t : s.successors()) {
      System.out.println(t.state);
    }
    System.out.println("=====");
    int[] b = {2,4,6,8,1,3,5,0};
    s = new EightQueen(b, 7);
    System.out.println("State = " + s);
    System.out.println("isgoal? " + s.isGoal());
    for(Successor t : s.successors()) {
      System.out.println(t.state);
    }
  }
}
