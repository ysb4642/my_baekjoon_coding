import java.util.*;

public class SumOfsquare_num {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[] dp = new int[num + 1];
		
		for (int i = 1; i <= num; i++) {
			dp[i] = i;
			for (int j = 1; j * j <= i; j++) {
				if (dp[i - j * j] + 1 < dp[i])
					dp[i] = dp[i - j * j] + 1;
			}
		}
		System.out.println(dp[num]);

	}

}
