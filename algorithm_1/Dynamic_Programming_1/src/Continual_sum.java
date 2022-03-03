import java.util.*;

public class Continual_sum {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int n = s.nextInt();
		int[] arr = new int[n];
		int[][] dp = new int[2][n];
		
		for (int i = 0; i < n; i++)
			arr[i] = s.nextInt();
		int max = arr[0];
		dp[0][0] = arr[0];
		dp[1][0] = arr[0];
		
		for(int i = 1; i < n; i++) {
			dp[0][i] = Math.max(dp[0][i - 1] + arr[i], arr[i]);
			dp[1][i] = Math.max(dp[0][i - 1], dp[1][i - 1] + arr[i]);
			max = Math.max(max, Math.max(dp[0][i], dp[1][i]));
		}
		System.out.println(max);
	}

}
