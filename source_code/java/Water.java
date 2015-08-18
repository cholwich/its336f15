import java.util.List;
import java.util.ArrayList;

public class Water implements State {
  public int x, y;

  public Water(int x, int y) {
    this.x = x;
    this.y = y;
  }

  public String toString() {
    return "[" + x + "," + y + "]";
  }

  public Boolean isGoal() {
    if (y == 4)
      return true;
    return false;
  }

  public List<Successor> successors() {
    List<Successor> l = new ArrayList<Successor>();
    if (x > 0)
      l.add(new Successor(new Water(0, y), "Empty {3}", x));
    if (y > 0)
      l.add(new Successor(new Water(x, 0), "Empty {5}", y));
    if (x < 3)
      l.add(new Successor(new Water(3, y), "Fill up {3}", 3-x));
    if (y < 5)
      l.add(new Successor(new Water(x, 5), "Fill up {5}", 5-y));

    int a = 3-x;
    int b = 5-y;

    if (x < 3) {
      if (y >= a)
        l.add(new Successor(new Water(3, y-a), "Pour {5} -> {3}", a));
      else if (y > 0)
        l.add(new Successor(new Water(x+y, 0), "Pour {5} -> {3}", y));
    }
    if (y < 5) {
      if (x >= b)
        l.add(new Successor(new Water(x-b, 5), "Pour {3} -> {5}", b));
      else if (x > 0)
        l.add(new Successor(new Water(0, x+y), "Pour {3} -> {5}", x));
    }
    return l;
  }
}
