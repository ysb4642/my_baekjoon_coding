import java.util.*;

public class Continuing_num2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int cnt = 1;
		int len = 10;
		int tmp = 0;
		
		for(int i = 1; i <= num; i++) {
			if (i == len) {
				cnt++;
				len *= 10;
			}
			tmp += cnt;
		}
		System.out.println(tmp);
	}
}
