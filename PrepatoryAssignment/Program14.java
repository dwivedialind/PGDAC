import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Program14 {
    public static void main(String[] args) throws IOException {
        System.out.println("Enter a string to check: ");
        System.out.flush();
        String input = getString();
        if(input.length()<=1){
            System.out.println("Either a single character or no character String");
            return ;
        }
        String compare = "";
        for(int i = input.length()-1; i>=0; i--){
            compare += input.charAt(i);
        }
        if(input.equals(compare))
            System.out.println("Palindrome");
        else
        {
            System.out.println("Not a palindrome");
        }
    }
    public static String getString() throws IOException{
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        String s = br.readLine();
        return s;
    }
}
