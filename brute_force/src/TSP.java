import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class TSP {

	public static int N;
	public static int[][] w;
	public static boolean[] isvisited;
	public static long result = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		w = new int[N][N];
		
		for (int i = 0; i < w.length; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < w[i].length; j++) {
				w[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for (int i = 0; i < N; i++) {
			isvisited = new boolean[N];
			isvisited[i] = true;
			dfs(i, i, 0);
		}
		System.out.println(result);
	}
	
	public static void dfs(int start, int now, long cost) {
		if (allVisited()) {
			if (w[now][start] != 0) {
				result = Math.min(result, cost + w[now][0]);
			}
			return ;
		}
		
		for (int i = 1; i < N; i++) {
			if (!isvisited[i] && w[now][i] != 0) {
				isvisited[i] = true;
				dfs(start, i, cost + w[now][i]);
				isvisited[i] = false;
			}
		}
	}
	
	public static boolean allVisited() {
		for (int i = 0; i < N; i++) {
			if (!isvisited[i]) {
				return false;
			}
		}
		return true;
	}

}
