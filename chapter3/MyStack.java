import java.util.EmptyStackException;

public class MyStack<T> {
    private static class StackNode<T> {
        private T data;
        private StackNode<T> next;

        public StackNode(T data) {
            this.data = data;
        }
    }

    private StackNode<T> top;

    public T pop() {
        if (this.top == null) {
            throw new EmptyStackException();
        }
        T item = this.top.data;
        this.top = this.top.next;
        return item;
    }

    public void push(T item) {
        StackNode<T> newNode = new StackNode<T>(item);
        this.top.next = newNode;
        this.top = newNode;
    }

    public T peek() {
        return this.top.data;
    }

    public boolean isEmpty() {
        return this.top == null;
    }
};
