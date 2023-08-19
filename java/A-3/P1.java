class Secounds{


    int sec;
     Secounds(int s){
     this.sec = s;
     }

  }

  class Minutes extends Secounds{


    int min;
   Minuits(int m, int s){
     super(s);
     this.min= m;
     }
  }

  class Hour extends Minutes{


     int hour;
   Hour(int h,int m, int s){
     super(m,s);
     this.hour= h;
     }

    int getTimeInSecounds(){
     return hour*3600 + min*60 + sec;
    }
  }

  public class P1{

   public static void main(String args[]){

    Hour o1 = new Hour(3,20.56);
    Hour o2 = new Hour(2,10,34);

    int temp = Math.abs(o1.getTimeInSecounds - o2.getTimeInSecounds);

    int hour = temp/3600;
    int min = (temp % 3600) / 60 ;
    int sec = temp % 60;

   System.out.print(hour + ":" + min + ":" + sec);

  }
  }