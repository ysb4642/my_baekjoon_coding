
import java.util.*;

public class SumOf123 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		long[] dp = new long[1_000_001];
		
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		int n = 0;
		for (int i = 0; i < t; i++) {
			n = s.nextInt();
			
			if (n > 3) {
				for (int j = 4; j <= n; j++)
					dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1_000_000_009;
			}
			System.out.println(dp[n]);
		}
	}

}
