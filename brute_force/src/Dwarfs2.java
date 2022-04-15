import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Dwarfs2 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();
		
		int[] height = new int[9];
		int sum = 0;
		
		for (int i = 0; i < 9; i++) {
			st = new StringTokenizer(br.readLine());
			height[i] = Integer.parseInt(st.nextToken());
			sum += height[i];
		}
		Arrays.sort(height);;
		for (int i = 0; i < 9; i++) {
			for (int j = i + 1; j < 9; j++) {
				if (sum - height[i] - height[j] == 100) {
					for (int k = 0; k < 9; k++) {
						if (k == i || k == j) {
							continue ;
						}
						sb.append(height[k]).append('\n');
					}
					System.out.println(sb);
					System.exit(0);
				}
			}
		}	
	}
}

