import java.util.*;

public class Increasing_sequence {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int n = s.nextInt();
		int[] dp = new int[n + 1];
		int[] arr = new int[n + 1];
		
		for (int i = 1; i <= n; i++)
			arr[i] = s.nextInt();
		
		dp[1] = arr[1];
		
		for (int i = 2; i <= n; i++) {
			dp[i] = arr[i];
			for (int j = 1; j < i; j++) { 
				if (arr[j] < arr[i])
					dp[i] = Math.max(dp[i], dp[j] + arr[i]);
			}
		}
		int max = dp[1];
		for (int i= 2; i <= n; i++) {
			if (dp[i] > max)
				max = dp[i];
		}
		System.out.println(max);
	}

}
