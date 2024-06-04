import java.util.NoSuchElementException;

public class MyQueue<T> {
    private static class QueueNode<T> {
        private T data;
        private QueueNode<T> next;

        public QueueNode(T data) {
            this.data = data;
        }
    };

    private QueueNode<T> first;
    private QueueNode<T> last;

    public void push(T item) {
        QueueNode<T> newNode = new QueueNode<T>(item);
        if (this.first == null) {
            this.first = newNode;
        } else if (this.last == null) {
            this.last = newNode;
            this.first.next = this.last;
        } else {
            QueueNode<T> lastNode = this.last;
            lastNode.next = newNode;
            this.last = newNode;
        }
    }

    public T pop() {
        if (this.first == null) {
            throw new NoSuchElementException();
        }
        T data = this.first.data;
        this.first = this.first.next;
        return data;
    }

    public T peek() {
        if (this.first == null) {
            throw new NoSuchElementException();
        }
        return this.first.data;
    }

    public boolean isEmpty() {
        return this.first == null;
    }
}
