import java.util.*;

public class Bitonic_sequence {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int n = s.nextInt();
		int[] arr = new int[n + 1];
		int[][] dp = new int[2][n + 1];
		
		for (int i = 1; i <= n; i++)
			arr[i] = s.nextInt();
		
		dp[0][1] = 1;		// 왼쪽에서 시작하는 LIS;
		dp[1][n] = 1;		// 오른쪽에 시작하는 LIS;
		
		for (int i = 2; i <= n; i++) {
			dp[0][i] = 1;
			for (int j = 1; j < i; j++) {
				if (arr[i] > arr[j]) {
					dp[0][i] = Math.max(dp[0][i], dp[0][j] + 1);
				}
			}
		}
		
		for (int i = n - 1; i > 0; i--) {
			dp[1][i] = 1;
			for(int j = n; j > i; j--) {
				if (arr[i] > arr[j]) {
					dp[1][i] = Math.max(dp[1][i], dp[1][j] + 1);
				}
			}
		}
		
		int max = 0;
		for (int i = 1; i <= n; i++) {
			dp[0][i] += dp[1][i];
		}
		
		for (int i = 1; i <= n; i++) {
			if(dp[0][i] > max)
				max = dp[0][i];
		}
		System.out.println(max - 1);	// 겹치는거 하나 제외
	}

}
