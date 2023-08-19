class Factorial
{
    public

    double getFactorial(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        return n * getFactorial(n-1);
    }
}


public class P5 {

    public static void main(String[] args) {
        Factorial f = new Factorial();
        double ans = f.getFactorial(50);
        System.out.println("Factoria of 50 is : " + ans);
    }
}
