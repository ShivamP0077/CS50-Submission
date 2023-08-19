class Vector1
{
    double x, y , z;

    Vector1(double n1, double n2, double n3)
    {

      this.x = n1;
      this.y = n2;
      this.z = n3;
    }

    public

    Vector1 addVector(Vector1 other)
     {
      double x1 = this.x + other.x;
      double x2 = this.y + other.y;
      double x3 = this.z + other.z;

      return new Vector1(x1,x2,x3);
      }

    Vector1 subtractVector(Vector1 other)
     {
      double x1 = this.x - other.x;
      double x2 = this.y - other.y;
      double x3 = this.z - other.z;

      return new Vector1(x1,x2,x3);
      }

      double dotVector(Vector1 other)
     {
      double x1 = this.x * other.x;
      double x2 = this.y * other.y;
      double x3 = this.z * other.z;

      return x1+x2+x3;
      }

     Vector1 crosVector(Vector1 other)
     {
      double x1 = (this.y * other.z) - (this.z * other.y);
      double x2 = (this.x * other.z) - (this.z * other.x);
      double x3 = (this.x * other.y) - (this.y * other.x);

      return new Vector1(x1,x2,x3);
      }


}

class P2
{
   public static void main(String args[])
   {
    Vector1 v1 = new Vector1(1,3,5);

    Vector1 v2 = new Vector1(3,6,3);

    Vector1 sum = v1.addVector(v2);
    System.out.println("sum of 2 vector is : " + sum.x + "i + " + sum.y + "j + " + sum.z + "k");

    Vector1 sub = v1.subtractVector(v2);
    System.out.println("subtract of 2 vector is : " + sub.x + "i + " + sub.y + "j + " + sub.z + "k");

    double dot = v1.dotVector(v2);
    System.out.println("dotproduct of 2 vector is : " + dot);

    Vector1 cross = v1.crosVector(v2);
    System.out.println("cross product of 2 vector is : " + cross.x + "i + " + cross.y + "j + " + cross.z + "k");
   }
}