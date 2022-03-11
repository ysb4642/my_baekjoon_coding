import java.util.*;

public class N_M1 {
	
	public static int[] arr;
	public static boolean[] visit;
	public static int N;
	public static int M;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		
		arr = new int[M];
		visit = new boolean[N];
		dfs(0);		
	}
	
	public static void dfs(int depth) {
		if (depth == M) {
			for (int val : arr) {
				System.out.print(val + " ");
			}
			System.out.println();
			return ;
		}
		for (int i = 0; i < N; i++) {
			if (!visit[i]) {
				visit[i] = true;
				arr[depth] = i + 1;
				dfs(depth + 1);
				visit[i] = false;
			}
		}
		
	}
	
}
