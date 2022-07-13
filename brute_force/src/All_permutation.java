import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class All_permutation {
	
	public static int N;
	public static int[] arr;
	public static int[] res;
	public static boolean[] isvisited;
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		res = new int[N];
		isvisited = new boolean[N];
		
		for (int i = 0; i < arr.length; i++)
			arr[i] = i + 1;
		dfs(0);
		System.out.println(sb);
	}
	
	public static void dfs(int depth) {
		
		if (depth == N) {
			for (int val : res) {
				sb.append(val).append(' ');
			}
			sb.append('\n');
			return ;
		}
		
		for (int i = 0; i < arr.length; i++) {
			if (!isvisited[i]) {
				isvisited[i] = true;
				res[depth] = arr[i];
				dfs(depth + 1);
				isvisited[i] = false;
			}
		}
	}

}
