import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Resignation2 {

	public static int N;
	public static int[] T;
	public static int[] P;
	public static int[] DP;
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		T = new int[N];
		P = new int[N];
		DP = new int[N + 1];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			T[i] = Integer.parseInt(st.nextToken());
			P[i] = Integer.parseInt(st.nextToken());
		}
		
		for (int i = 0; i < N; i++) {
			if (i + T[i] <= N) {
				DP[i + T[i]] = Math.max(DP[i + T[i]], DP[i] + P[i]);
			}
			DP[i + 1] = Math.max(DP[i + 1], DP[i]);
		}
		System.out.println(DP[N]);
		
	}

}
