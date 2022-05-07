import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class N_M10_2 {
	public static int N, M;
	public static int[] arr;
	public static int[] res;
	public static boolean[] isvisit;
	public static StringBuffer sb = new StringBuffer();
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];
		res = new int[M];
		isvisit = new boolean[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		dfs(0, 0);
		System.out.println(sb);
	}
	public static void dfs(int at, int depth) {
		if (depth == M) {
			for (int val : res) {
				sb.append(val).append(' ');
			}
			sb.append('\n');
			return ;
		}
		
		int before = 0;
		for (int i = at; i < N; i++) {
			if (!isvisit[i] && before != arr[i]) {
				isvisit[i] = true;
				res[depth] = arr[i];
				before = arr[i];
				dfs(i + 1, depth + 1);
				isvisit[i] = false;
			}
		}
	}
}
