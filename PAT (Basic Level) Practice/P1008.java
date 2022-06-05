import java.util.Scanner;

public class P1008 {

  public static void reverse(int[] nums, int l, int r) {
        while (l < r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l++;r--;
        }  
    }
    public static void main(String[] args) {
        int N, M;
        Scanner in = new Scanner(System.in);
        N = in.nextInt();
        M = in.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = in.nextInt();
        }
        in.close();
        int pos = M % N;
        reverse(nums, 0, N - pos - 1);
        reverse(nums, N  - pos, N - 1);
        reverse(nums, 0, N - 1);
        for (int i : nums) {
            System.out.printf("%d ",i);
        }
    }

    
}
