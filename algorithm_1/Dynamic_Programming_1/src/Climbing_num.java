import java.util.*;

public class Climbing_num {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[][] dp = new int[n + 1][10];
		
		for(int i = 0; i < 10; i++)
			dp[1][i] = 1;
		for(int i = 2; i <= n; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = j; k < 10; k++) {
					dp[i][j] += dp[i - 1][k];
					dp[i][j] %= 10007;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < 10; i++)
			res += dp[n][i];
		System.out.println(res % 10007);
	}

}
