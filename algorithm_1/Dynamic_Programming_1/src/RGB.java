import java.util.*;

public class RGB {

	final static int RED = 0;
	final static int GREEN = 1;
	final static int BLUE = 2;
	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		int n = s.nextInt();
		int cost = 0;
		int[][] dp = new int[n][3];
		
		for (int i = 0; i < n; i++) {
			dp[i][RED] = s.nextInt();
			dp[i][GREEN] = s.nextInt();
			dp[i][BLUE] = s.nextInt();
		}
		
		for (int i = 1; i < n; i++) {
			dp[i][RED] += Math.min(dp[i - 1][GREEN], dp[i - 1][BLUE]);
			dp[i][GREEN] += Math.min(dp[i - 1][RED], dp[i - 1][BLUE]);
			dp[i][BLUE] += Math.min(dp[i - 1][GREEN], dp[i - 1][RED]);
		}
		
		cost = Math.min(Math.min(dp[n - 1][RED], dp[n - 1][GREEN]), dp[n - 1][BLUE]);
		System.out.println(cost);
		
	}

}
