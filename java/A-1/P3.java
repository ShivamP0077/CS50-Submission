
      if (count == 2) {
        System.out.println(j + " ");
        temp++;
      }
    }
  }

}

public class P3 {
  public static void main(String[] args) {

      Prime p = new Prime();
      p.getPrime();
  }class Prime {
  int n;

  Prime() {
    this.n = 20;
  }

  Prime(int x) {
    this.n = x;
  }

  public

      void getPrime() {
    int count, temp = 0;

    for (int j = 2; temp <= n; j++) {
      count = 0;
      for (int i = 1; i <= j; i++) {

        if (j % i == 0) {
          count++;
        }
      }
}
