import java.util.Scanner;

public class P1003 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 0; i < n; i++) {
            String line = s.next();
            // 1.ֻ��PAT�������ַ���2.xPATx����ȷ��
            boolean isRight = line.matches("A*PA+TA*");
            // 3.��� aPbTc ����ȷ�ģ���ô aPbATca Ҳ����ȷ�ģ������й��ɡ���a*b=c����Ҳ�ǲ��԰�����APAAATAAΪNO��ԭ��
            int a = line.indexOf("P"); // ��ȡPǰ��A�ĸ��������PΪ0��ǰ��a�ĸ���Ϊ0������ͬ��
            int index = line.indexOf("T");
            int b = index - a - 1;// ��ȡTǰ��A�ĸ���
            int c = line.length() - a - b - 2; // ��ȡT����A�ĸ���
            System.out.println(isRight && (a * b == c) ? "YES" : "NO");
        }
        s.close();
	}
}
