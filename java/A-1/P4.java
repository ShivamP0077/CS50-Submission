class Fibonacci {
    int n;

    Fibonacci() {
        this.n = 50;
    }

    Fibonacci(int x) {
        this.n = x;
    }

    public

            void getFionacci() {

        long fib1 = 0;
        long fib2 = 1;
        long temp;

        System.out.print(fib1 + " ");
        System.out.print(fib2 + " ");

        for (int i = 1; i <= n-2; i++) {

            temp = fib1 + fib2;
            fib1 = fib2;
            fib2 = temp;
            System.out.print(fib2 + " ");
        }
    }
}

public class P4 {
    public static void main(String[] args) {
      Fibonacci f = new Fibonacci();
      f.getFionacci();

    }
}
