import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Remote2 {
	
	static int target;
	static int b;
	static int res;
	static boolean[] broken;
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		target = Integer.parseInt(br.readLine());
		b = Integer.parseInt(br.readLine());
		broken = new boolean[10];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < b; i++) {
			int n = Integer.parseInt(st.nextToken());
			broken[n] = true;
		}
		
		res = Math.abs(target - 100);
		for(int i = 0; i <= 999999; i++) {
			String str = String.valueOf(i);
			int len = str.length();
			
			boolean isBreak = false;
			for (int j = 0; j < len; j++) {
				if (broken[str.charAt(j) - '0']) {
					isBreak = true;
					break ;
				}
			}
			if (!isBreak) {
				int min = Math.abs(target - i) + len;
				res = Math.min(min, res);
			}
		}
		sb.append(res);
		System.out.println(res);
	}

}
