import java.util.*;

public class RGB2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] arr = new int[n + 1][3];
		int[][] dp = new int[n + 1][3];
		int res = 1000001;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		
		// k = 0 red, k = 1 green, k = 2 blue
		for (int k = 0; k < 3; k++) {
			for (int i = 0; i < 3; i++) {
				if (i == k)
					dp[1][i] = arr[1][i];
				else
					dp[1][i] = 1000001;
			}
			
			for (int i = 2; i <= n; i++) {
				dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
				dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
				dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
			}
			
			for (int i = 0; i < 3; i++) {
				if (i != k)
					res = Math.min(res, dp[n][i]);
			}
		}
		System.out.println(res);
	}

}
