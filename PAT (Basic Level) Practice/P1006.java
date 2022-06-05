import java.util.*;
public class P1006{
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        int b = 0;
        int s = 0;
        s = (n/10)%10;
        b = n/100;
        System.out.print(String.join("",Collections.nCopies(b,"B")));
        System.out.print(String.join("",Collections.nCopies(s,"S")));
        for (int i = 1; i <= (n % 10); i++) {
            System.out.print(i);
        }
        
    }
}
