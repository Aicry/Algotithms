import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class P1005 {
    public static void main(String[] args) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        in.nextLine();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = in.nextInt();
        }
        in.close();
        Arrays.sort(nums);
        for (int i = 0; i < n; i++) {
            int temp = nums[i];

            while (temp != 1) {
                if (map.containsKey(temp))
                    map.put(temp, map.get(temp) - 1);
                else
                    map.put(temp, 1);

                if (temp % 2 == 0)
                    temp /= 2;
                else
                    temp = (temp * 3 + 1) / 2;
            }
        }
        String res = "";
        for (int i = n - 1; i >= 0; i--) {
            if (map.get(nums[i]) == 1) {
                res += nums[i] + " ";
            }
        }
        res = res.substring(0, res.length() - 1);
        System.out.println(res);

    }
}
