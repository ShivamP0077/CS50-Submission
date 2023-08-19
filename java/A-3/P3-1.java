
class LivingOrganism {
    private String name;
    private int age;

    public LivingOrganism(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void breathe() {
        System.out.println(name + " is breathing.");
    }

    public void eat() {
        System.out.println(name + " is eating.");
    }
}

class Animal extends LivingOrganism {
    public Animal(String name, int age) {
        super(name, age);
    }

    public void move() {
        System.out.println(name + " is moving.");
    }
}

class Bird extends Animal {
    public Bird(String name, int age) {
        super(name, age);
    }

    public void fly() {
        System.out.println(name + " is flying.");
    }
}



public class P3-1 {
    public static void main(String[] args) {
        Bird eagle = new Bird("Eagle", 5);
        eagle.breathe();
        eagle.eat();
        eagle.move();
        eagle.fly();




}
