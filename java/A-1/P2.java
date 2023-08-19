import java.math.BigInteger;

class Factorial{
    int n;
    BigInteger  factorial = BigInteger.ONE;

    Factorial()
    {
        this.n = 20;
    }
    Factorial(int x)
    {
        this.n = x;
    }
  public
    void getFactorial()
    {
         for(int i = 1; i <= n ; i++){
            factorial = factorial.multiply(BigInteger.valueOf(i));
        }
        System.out.println("Factorial of " + n +" is :  " + factorial);
    }



};

public class P2 {
    public static void main(String[] args) {
      Factorial fac = new Factorial();
      fac.getFactorial();
       
    }
}
