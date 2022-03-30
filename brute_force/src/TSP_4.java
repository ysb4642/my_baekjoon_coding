import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class TSP_4 {
	
	public static int N;
	public static int[][] w;
	public static int res = Integer.MAX_VALUE;
	public static boolean[] isvisited;
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		w = new int[N][N];
		isvisited = new boolean[N];
		for (int i = 0; i < w.length; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < w[i].length; j++) {
				w[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		isvisited[0] = true;
		dfs(0, 0, 0);
		sb.append(res);
		System.out.println(sb);
	}
	
	public static  void dfs(int depth, int now, int cost) {
		if (cost >= res) {
			return ;
		}
		
		if (depth == N - 1) {
			if (w[now][0] != 0) {
				res = Math.min(res, cost + w[now][0]);
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (isvisited[i] || w[now][i] == 0) {
				continue ;
			}
			isvisited[i] = true;
			dfs(depth + 1, i, cost + w[now][i]);
			isvisited[i] = false;
		}
	}

}