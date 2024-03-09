import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Program07 {
    public static void main(String[] args) throws IOException {
        System.out.println("Give a number: ");
        System.out.flush();
        int n = getInt();
        for(int i = 1; i<=10; i++){
            System.out.print(n + "*" +i+ "="+ n*i);
            System.out.println("");
        }
        
    }

    public static int getInt() throws IOException{
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int n = Integer.parseInt(br.readLine());
        return n;
    }
    
}
