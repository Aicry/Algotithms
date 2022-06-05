import java.util.Scanner;

public class P1002 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String[] spell = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
		String n = s.nextLine();
		s.close();
		int sum = 0;
		for (int i = 0; i < n.length(); i++) {
			sum = sum + Integer.valueOf(n.substring(i, i + 1));
		}
		String sumStr = String.valueOf(sum);
		String result = "";
		for (int i = 0; i < sumStr.length(); i++) {
			int numUnit = Integer.parseInt(sumStr.substring(i, i + 1));
			result = result + spell[numUnit] + " ";
		}
		String rst = result.substring(0, result.length() - 1);
		System.out.println(rst);
	}
}
