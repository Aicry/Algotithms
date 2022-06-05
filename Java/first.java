import java.util.*;

import java.math.*;

class first {
    public static void main(String[] args) {
        System.out.println("Hello");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println(n);
        in.close();
        label: while (true) {
            for (;;)
                break label;
        }
        System.out.println("Hello");
        BigDecimal bigDecimal = BigDecimal.valueOf(10, n);
        System.out.println(bigDecimal);
    }
}

