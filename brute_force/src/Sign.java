import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Sign {

	static int K;	// 부등호 개수 (2 <= k <= 9)
	static boolean[] isVisited = new boolean[10]; // 0~9 숫자 방문. 중복 불
	static char[] signs;
	static List<String> result = new ArrayList<>();
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		K = Integer.parseInt(br.readLine());
		signs = new char[K];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < K; i++) {
			signs[i] = st.nextToken().charAt(0);
		}
		dfs("", 0);
		Collections.sort(result);
		sb.append(result.get(result.size() - 1)).append('\n').append(result.get(0));
		// 최댓값, 최소값
		System.out.println(sb);
	}
	
	static void dfs(String num, int depth) {
		
		if (depth == K + 1) {
			result.add(num);
			return ;
		}
		
		for (int i = 0; i <= 9; i++) {
				// 처음건 비교할게 없으므로 통과 || 방문 안한 숫자 && 비교
			 if (depth == 0 || !isVisited[i] && compare(num.charAt(num.length() - 1) - '0', i, signs[depth - 1])) {
				 isVisited[i] = true;
				 dfs(num + i, depth + 1);
				 isVisited[i] = false;
			 }
		}
	}
	
	static boolean compare(int a, int b, char c) {
		if (c == '<')	return a < b;
		else			return a > b;
	}

}
