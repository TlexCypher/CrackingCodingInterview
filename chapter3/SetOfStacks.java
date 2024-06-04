import java.util.ArrayList;
import java.util.Stack;

public class SetOfStacks {
    private ArrayList<Stack<Integer>> stacks = new ArrayList<>();

    public void push(int data) {
        Stack<Integer> last = getLastStack();
        if (last == null) {
            stacks.add(new Stack<>());
            stacks.get(0).push(data);
        } else {
            last.push(data);
        }
    }

    public int pop() {
        Stack<Integer> last = getLastStack();
        if (last == null) {
            throw new NullPointerException();
        }
        int val = last.pop();
        if (last.empty()) {
            stacks.remove(stacks.size() - 1);
        }
        return val;
    }

    public Stack<Integer> getLastStack() {
        if (stacks.size() == 0) {
            return null;
        } else {
            return this.stacks.get(this.stacks.size() - 1);
        }
    }
}
