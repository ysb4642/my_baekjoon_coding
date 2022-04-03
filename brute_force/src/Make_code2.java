import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Make_code2 {

	public static int L;
	public static int C;
	public static char[] arr;
	public static char[] res;
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		arr = new char[C];
		res = new char[L];
		
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < arr.length; i++)
			arr[i] = st.nextToken().charAt(0);
		Arrays.sort(arr);
		dfs(0, 0);
		System.out.println(sb);
	}

public static void dfs(int at, int depth) {
		
		if (depth == L) {
			if(isValid()) {
				for (char ch : res) {
					sb.append(ch);
				}
				sb.append('\n');
			}
			return ;
		}
		for (int i = at; i < arr.length; i++) {
			res[depth] = arr[i];
			dfs(i + 1, depth + 1);
		}
	}
	
	public static boolean isValid() {
		int mo = 0;
		int ja = 0;
		
		for (char ch : res) {
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
				mo++;
			} else {
				ja++;
			}
		}
		if (mo >= 1 && ja >= 2) {
			return true;
		}
		return false;
	}

}