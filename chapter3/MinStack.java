public class MinStack {
    private static class MinStackNode {
        private int data;
        private int mini;
        private MinStackNode next;

        public MinStackNode(int data, int mini) {
            this.data = data;
            this.mini = mini;
        }
    }

    private MinStackNode top;

    public void push(int data) {
        if (this.top == null) {
            this.top = new MinStackNode(data, data);
        } else {
            int mini = Math.min(this.top.data, data);
            MinStackNode newNode = new MinStackNode(data, mini);
            MinStackNode curTop = this.top;
            curTop.next = newNode;
            this.top = newNode;
        }
    }

    public int pop() {
        int data = this.top.data;
        this.top = this.top.next;
        return data;
    }

    public int min() {
        int mini = this.top.mini;
        return mini;
    }
}
