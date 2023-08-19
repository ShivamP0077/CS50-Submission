import java.util.Random;

class RandomString{
    public
     
       void getRendomString()
       {
         String alphabet = "ABCD";

         StringBuilder sb = new StringBuilder();

         Random random = new Random();

         int length = 5;
         for (int i = 1; i <= length; i++)
         {
            int index = random.nextInt(alphabet.length());
            char random_char = alphabet.charAt(index);
            sb.append(random_char);
         }
           
          
         String newString = sb.toString();

         System.out.println(newString);
       }
    
}

public class P6 {

    public static void main(String[] args) {
        RandomString s = new RandomString();
        s.getRendomString();
    }
    
}
