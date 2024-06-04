import java.util.EmptyStackException;
import java.util.LinkedList;
import java.util.NoSuchElementException;

public class AnimalQueue {
    private static abstract class Animal {
        private int order;
        private String name;

        public Animal(String name, int order) {
            this.order = order;
            this.name = name;
        }

        public void setOrder(int order) {
            this.order = order;
        }

        public int getOrder() {
            return this.order;
        }
    }

    private static class Dog extends Animal {
        public Dog(String name, int order) {
            super(name, order);
        }
    }

    private static class Cat extends Animal {
        public Cat(String name, int order) {
            super(name, order);
        }
    }

    private LinkedList<Dog> dogs;
    private LinkedList<Cat> cats;
    private int order;

    public AnimalQueue() {
        this.dogs = new LinkedList<>();
        this.cats = new LinkedList<>();
    }

    public void enqueue(Animal animal) {
        animal.setOrder(this.order);
        if (animal instanceof Dog) {
            this.dogs.add((Dog) animal);
        } else if (animal instanceof Cat) {
            this.cats.add((Cat) animal);
        } else {
            throw new NoSuchElementException();
        }
        this.order++;
    }

    public Animal dequeueAny() {
        Animal dog = this.dogs.peek();
        Animal cat = this.cats.peek();
        Animal shouldPop = getOlder(dog, cat);
        if (shouldPop == dog) {
            this.dogs.pop();
        } else {
            this.cats.pop();
        }
        return shouldPop;
    }

    public Dog dequeueDog() {
        if (this.dogs.size() == 0) {
            throw new EmptyStackException();
        }
        return this.dogs.pop();
    }

    public Cat dequeueCat() {
        if (this.cats.size() == 0) {
            throw new EmptyStackException();
        }
        return this.cats.pop();
    }

    public Animal peek() {
        if (this.dogs.size() == 0 && this.cats.size() == 0) {
            throw new EmptyStackException();
        } else if (this.dogs.size() == 0) {
            return this.cats.peek();
        } else if (this.cats.size() == 0) {
            return this.dogs.peek();
        } else {
            return getOlder(this.dogs.peek(), this.cats.peek());
        }
    }

    private Animal getOlder(Animal dog, Animal cat) {
        if (dog.getOrder() < cat.getOrder()) {
            return dog;
        } else {
            return cat;
        }
    }
}
