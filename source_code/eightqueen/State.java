import java.util.List;

public interface State {
  Boolean isGoal();
  List<Successor> successors();
}
