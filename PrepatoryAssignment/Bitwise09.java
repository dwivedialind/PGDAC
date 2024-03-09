import java.util.Scanner;

public class Bitwise09 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num;

        System.out.print("Enter Number: ");
        num = scanner.nextInt();
        System.out.printf("Given Number: %d\n", num);
        int bnum = num;
        StringBuilder binary = new StringBuilder();
        while (bnum != 0) {
            char str[] = Integer.toString(bnum%2).toCharArray();
            binary.insert(0,str);
            bnum = bnum / 2;
        }
        int onum = num;
        StringBuilder octal = new StringBuilder();
        while(onum != 0){
            char str[] = Integer.toString(onum%8).toCharArray();
            octal.insert(0,str);
            onum = onum / 8;
        }
        int hnum = num;
        StringBuilder hexa = new StringBuilder();
        while(hnum != 0){
            char str[] = Integer.toString(hnum%16).toCharArray();
            hexa.insert(0,str);
            hnum = hnum / 16;
        }

        System.out.println("Binary Equivalent: " + binary.toString());
        System.out.println("Octal Equivalent: " + octal.toString());
        System.out.println("HexaDecimal Equivalent: " + hexa.toString());
    }

}
