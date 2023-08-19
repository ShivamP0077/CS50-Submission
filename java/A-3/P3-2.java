
class ChemicalCompound {
    private String name;

    public ChemicalCompound(String name) {
        this.name = name;
    }

    public void describe() {
        System.out.println("This is " + name + ".");
    }
}

class Element extends ChemicalCompound {
    public Element(String name) {
        super(name);
    }

    public void displayProperties() {
        System.out.println("Properties of " + name + ": ...");
    }
}

class Compound extends ChemicalCompound {
    public Compound(String name) {
        super(name);
    }

    public void analyzeComposition() {
        System.out.println("Analyzing composition of " + name + "...");
    }
}

class OrganicCompound extends Compound {
    public OrganicCompound(String name) {
        super(name);
    }

    public void performTests() {
        System.out.println("Conducting tests on " + name + "...");
    }
}

class InorganicCompound extends Compound {
    public InorganicCompound(String name) {
        super(name);
    }

    public void classify() {
        System.out.println("Classifying " + name + " as inorganic.");
    }
}

public class P3-2 {
    public static void main(String[] args) {
        Element hydrogen = new Element("Hydrogen");
        hydrogen.describe();
        hydrogen.displayProperties();

        System.out.println();

        OrganicCompound glucose = new OrganicCompound("Glucose");
        glucose.describe();
        glucose.analyzeComposition();
        glucose.performTests();
    }
}
