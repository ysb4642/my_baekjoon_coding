import java.util.*;

public class Remote {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int target = sc.nextInt();
		int b = sc.nextInt();
		
		boolean[] broken = new boolean[10];
		for (int i = 0; i < b; i++) {
			int n = sc.nextInt();
			broken[n] = true;
		}
		
		int result = Math.abs(target - 100);
		for (int i = 0; i <= 999999; i++) {
			String str = String.valueOf(i);
			int len = str.length();
			
			boolean isBreak = false;
			for (int j = 0; j < len; j++) {
				if (broken[str.charAt(j) - '0']) { // 고장난 버튼을 눌러야 하
					isBreak = true;
					break ; // 탐색하지 않고 빠져나옴
				}
			}
			if (!isBreak) { // i를 누를 떄 고장난 버튼을 누르지 않는다
				int min = Math.abs(target - i) + len; // i를 누른 후 (len) target까지 이동하는 횟수(target - i)
				result = Math.min(min, result);
			}
		}
		System.out.println(result);
	}

}
