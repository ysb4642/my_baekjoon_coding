import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Start_link {
	
	static int N;
	static int[][] map;
	static boolean[] isvisited;
	static int MIN = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		map = new int[N][N];
		isvisited = new boolean[N];
		
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for (int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		combination(0, 0);
		System.out.println(MIN);
		
	}
	
	// inx : 인덱스, cnt : 조합개수(재귀 깊이)
	static void combination(int idx, int cnt) {
		// 팀 조합이 완성될 경우
		if (cnt == N / 2) {
			// 방문한 팀과 방문하지 않은 팀을 각각 나누어
			// 각 팀의 점수를 구한 뒤 최솟값을 찾는다.
			diff();
			return ;
		}
		
		for (int i = idx; i < N; i++) {
			if (!isvisited[i]) {
				isvisited[i] = true;
				combination(i + 1, cnt + 1);
				isvisited[i] = false ;
			}
		}
	}
	
	static void diff() {
		int teamStart = 0;
		int teamLink = 0;
		
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				// i번째 사람과 j번째 사람이 true라면 스타트팀으로 점수 플러스
				if (isvisited[i] == true && isvisited[j] == true) {
					teamStart += map[i][j];
					teamStart += map[j][i];
				}
				// i번째 사람과 j번째 사람이 false라면 링크팀으로 점수 플러스
				else if (isvisited[i] == false && isvisited[j] == false) {
					teamLink += map[i][j];
					teamLink += map[j][i];
				}
			}
		}
		
		// 두 팀의 점수 차이(절대값)
		int val = Math.abs(teamStart - teamLink);
		// 점수가 0이라면 가장 낮은 최소값이기 때문에 
		// 더이상의 탐색 필요 없이 0을 출력하고 종료하면 됨.
		if (val == 0) {
			System.out.println(val);
			System.exit(0);
		}
		
		MIN = Math.min(val, MIN);
	}

}
