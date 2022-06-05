import java.util.Scanner;

public class P1003 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 0; i < n; i++) {
            String line = s.next();
            // 1.只有PAT这三种字符。2.xPATx是正确的
            boolean isRight = line.matches("A*PA+TA*");
            // 3.如果 aPbTc 是正确的，那么 aPbATca 也是正确的，这里有规律。即a*b=c，这也是测试案例中APAAATAA为NO的原因
            int a = line.indexOf("P"); // 获取P前面A的个数，如果P为0则前面a的个数为0。其他同理
            int index = line.indexOf("T");
            int b = index - a - 1;// 获取T前面A的个数
            int c = line.length() - a - b - 2; // 获取T后面A的个数
            System.out.println(isRight && (a * b == c) ? "YES" : "NO");
        }
        s.close();
	}
}
