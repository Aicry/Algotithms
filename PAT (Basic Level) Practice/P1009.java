import java.util.Scanner;

public class P1009 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] temp;
        String delimeter = in.nextLine();
        in.close();
        temp = delimeter.split(" ");
        int n = temp.length;
        for (int i = n-1; i > 0; i--) {
            System.out.print(temp[i] + " ");
        }
        System.out.println(temp[0]);
    }
}
