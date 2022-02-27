import java.util.*;

public class Decreasing_sequence {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int n = s.nextInt();
		int[] arr = new int[n + 1];
		int[] dp = new int[n + 1];
		
		for (int i = 1; i <= n; i++)
			arr[i] = s.nextInt();
		int max = 0;
		for (int i = 1; i <= n; i++) {
			dp[i] = 1;
			for (int j = 1; j < i; j++) {
				if (arr[j] > arr[i])
					dp[i] = Math.max(dp[i], dp[j] + 1);
			}
			max = Math.max(max, dp[i]);
		}
		System.out.println(max);
	}
}
