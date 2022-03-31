import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Lotto {
	
	public static int N;
	public static int[] arr;
	public static int[] res;
	public static boolean[] isvisited;
	
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		while(true) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			
			if (N == 0) {
				break ;
			}
			arr = new int[N];
			res = new int[6];
			isvisited = new boolean[N];
			for (int i = 0; i < arr.length; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			dfs(0, 0);
			System.out.println(sb);
			sb.setLength(0);
		}
		
	}
	public static void dfs(int at, int depth) {
		
		if (depth == 6) {
			for (int val : res) {
				sb.append(val).append(' ');
			}
			sb.append('\n');
			return ;
		}
		for (int i = at; i < N; i++) {
			if (!isvisited[i]) {
				isvisited[i] = true;
				res[depth] = arr[i];
				dfs(i + 1, depth + 1);
				isvisited[i]  = false;
			}
		}
	}

}
