import java.util.EmptyStackException;

public class ThreeStacksWithOneArray {
    private int numOfStacks = 3;
    private int stackSize;
    private int[] values;
    private int[] sizes;

    public ThreeStacksWithOneArray(int stackSize) {
        this.stackSize = stackSize;
        this.values = new int[numOfStacks * this.stackSize];
        this.sizes = new int[numOfStacks];
    }

    public void push(int stackNum, int data) {
        this.values[indexOfStack(stackNum)] = data;
        this.sizes[stackNum]++;
    }

    public int pop(int stackNum) {
        if (isEmpty(stackNum)) {
            throw new EmptyStackException();
        }
        int value = this.values[indexOfStack(stackNum)];
        this.values[indexOfStack(stackNum)] = -1;
        this.sizes[stackNum]--;
        return value;
    }

    public int peek(int stackNum) {
        return this.values[indexOfStack(stackNum)];
    }

    public int indexOfStack(int stackNum) {
        return stackNum * this.stackSize + this.sizes[stackNum] - 1;
    }

    public boolean isFull(int stackNum) {
        return this.sizes[stackNum] == this.stackSize;
    }

    public boolean isEmpty(int stackNum) {
        return this.sizes[stackNum] == 0;
    }
};
