import java.util.*;

class P1004 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.nextLine();
        String high = "";
        String low = "";
        int min = 100;
        int max = 0;
        while (n-- != 0) {
            String[] temp;

            String delimeter = in.nextLine();
            
            temp = delimeter.split(" ");

            if (Integer.parseInt(temp[2]) >= max)
            {
                high = temp[0] + " " + temp[1];
                max = Integer.parseInt(temp[2]);
            }
            if (Integer.parseInt(temp[2]) <= min)
            {
                low = temp[0] + " " + temp[1];
                min = Integer.parseInt(temp[2]);
            }
        }
        System.out.println(high);
        System.out.println(low);
        in.close();
    }
}