import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Link_start2 {
	
	static int N;
	static int P;
	static int[][] map;
	static boolean[] isvisited;
	static int MIN = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		isvisited = new boolean[N];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		P = 1;
		while (P < N) {
			combination(0, 0);
			P++;
		}
		System.out.println(MIN);
	}
	
	static void combination(int depth, int start) {
		
		if (depth == P) {
			MIN = Math.min(MIN, diff());
			
			if (MIN == 0) {
				System.out.println(MIN);
				System.exit(0);
			}
			return;
		}
		
		for (int i = start; i < N; i++) {
			if (!isvisited[i]) {
				isvisited[i] = true;
				combination(depth + 1, i + 1);
				isvisited[i] = false;
			}
		}
	}
	
	static int diff() {
		int teamStart = 0;
		int teamLink = 0;
		
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (isvisited[i] && isvisited[j]) {
					teamStart += (map[i][j] + map[j][i]);
				}
				else if (!isvisited[i] && !isvisited[j]) {
					teamLink += (map[i][j] + map[j][i]);
				}
			}
		}
		return Math.abs(teamStart - teamLink);
	}

}
