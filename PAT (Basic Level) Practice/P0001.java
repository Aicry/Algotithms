import java.util.Scanner;

public class P0001 {
    public static void main(String[] args) {
        int a;
        Scanner in = new Scanner(System.in);
        a = in.nextInt();
        in .close();
        int count =0;
        while(a!=1){
            
            if(a%2==0){
                a/=2;
            }
            else a=(3*a+1)/2;
            count++;
    }
    System.out.println(count);
    }
}
