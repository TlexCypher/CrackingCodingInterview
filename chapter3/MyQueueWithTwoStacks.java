import java.util.EmptyStackException;
import java.util.Stack;

public class MyQueueWithTwoStacks<T> {
    private Stack<T> frontStack;
    private Stack<T> lastStack;

    public MyQueueWithTwoStacks() {
        this.frontStack = new Stack<T>();
        this.lastStack = new Stack<T>();
    }

    public void push(T data) {
        this.frontStack.push(data);
    }

    public T pop() {
        if (!this.lastStack.empty()) {
            return this.lastStack.pop();
        } else {
            this.shiftFrontToLast();
            if (this.lastStack.empty()) {
                throw new EmptyStackException();
            }
            return this.lastStack.pop();
        }
    }

    public T peek() {
        if (!this.lastStack.empty()) {
            return this.lastStack.peek();
        } else {
            this.shiftFrontToLast();
            if (this.lastStack.empty()) {
                throw new EmptyStackException();
            }
            return this.lastStack.peek();
        }
    }

    private void shiftFrontToLast() {
        while (!this.frontStack.empty()) {
            this.lastStack.push(this.frontStack.pop());
        }
    }
}
