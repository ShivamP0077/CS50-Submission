class ComplexNumber
{
    double real;
    double img;

    ComplexNumber(double n1 , double n2)
    {
        this.real = n1;
        this.img = n2;
    }

    public
      
      ComplexNumber add (ComplexNumber other)
      {
         return new ComplexNumber(this.real + other.real, this.img + other.img);
      }
      
      ComplexNumber substract (ComplexNumber other)
      {
         return new ComplexNumber(this.real - other.real, this.img - other.img);
      }

      ComplexNumber multyply (ComplexNumber other)
      {
        double realpart = this.real * other.real + this.img * other.img;
        double imgpart = this.real * other.img + this.img * other.real;
         return new ComplexNumber(realpart,imgpart);
      }

      ComplexNumber dived (ComplexNumber other)
      {
        double denominater = other.real * other.real + other.img * other.img;
        double realpart = (this.real * other.real + this.img * other.img)/denominater;
        double imgpart = (this.img * other.real + this.real * other.img)/denominater;
         return new ComplexNumber(realpart,imgpart);
      }


}

public class P1
{
    public static void main(String[] args) {
        ComplexNumber o1 = new ComplexNumber(2, 3);
        ComplexNumber o2 = new ComplexNumber(3,4);

        ComplexNumber sum = o1.add(o2);
        System.out.println("sum is : " +"(" + sum.real + " + " + sum.img + "i)");

         ComplexNumber sub = o1.substract(o2);
        System.out.println("substract is : " +"(" + sub.real + " + " + sub.img + "i)");

         ComplexNumber mult = o1.multyply(o2);
        System.out.println("multyply is : " +"(" + mult.real + " + " + mult.img + "i)");

        ComplexNumber div = o1.dived(o2);
        System.out.println("dived is : " +"(" + div.real + " + " + div.img + "i)");       

    }
}