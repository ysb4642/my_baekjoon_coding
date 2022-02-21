import java.util.*;

public class zoo {

	public static void main(String[] args) {
		final int MOD = 9901;
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		long[][]dp = new long[n + 1][3];
		dp[1][0] = dp[1][1] = dp[1][2] = 1;
		
		for (int i = 2; i <= n; i++) {
			dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
			dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
			dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		}
		long res = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
		System.out.println(res);

	}

}
