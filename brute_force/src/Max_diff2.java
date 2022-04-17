import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Max_diff2 {
	
	public static int N;
	public static int[] arr;
	public static int[] res;
	public static boolean[] isvisited;
	public static int ans = Integer.MIN_VALUE;
	
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		res = new int[N];
		isvisited = new boolean[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < arr.length; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		dfs(0);
		System.out.println(ans);
	}

	public static void dfs(int depth) {
		
		if (depth == N) {
			ans = Math.max(ans, getMax());
			return ;
		}
		
		for (int i = 0; i < N; i++) {
			if (!isvisited[i]) {
				isvisited[i] = true;
				res[depth] = arr[i];
				dfs(depth + 1);
				isvisited[i] = false;
			}
		}
	}
	
	public static int getMax() {
	
		int sum = 0;
		for (int i = 0; i < N - 1; i++) {
			sum += Math.abs(res[i] - res[i + 1]);
		}
		return sum;
	}
}
