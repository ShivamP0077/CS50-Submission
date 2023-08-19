class Vehicle
{

    String compney;
    String modle;

    public

    Vehicle(String compney,String modle)
    {
        this.compney = compney;
        this.modle = modle;
    }

    void display()
    {
        System.out.println("Compney name is : "+compney+ " Modle is : "+modle);

    }
}

class Bike extends Vehicle{

    int Capecity;

    public

    Bike(String compney,String modle ,int sits)
    {
        super(compney,modle);
        this.Capecity = sits;
    }

    void display()
    {
        super.display();
        System.out.println("Capacity is "+ Capecity);
    }
}

public class P2
{
    public static void main(String[] args){

        Vehicle v = new Vehicle("hero","Splander ");
        v.display();

        Bike b = new Bike("hero","super Splander ",3);
        b.display();
    }
}