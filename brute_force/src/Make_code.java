import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Make_code {

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
			if(isVowel(res) && isConsonant(res)) {
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
	
	public static boolean isVowel(char[] test) {
		
		for (int i = 0; i < test.length; i++) {
			if (test[i] == 'a' || test[i] == 'e' || test[i] == 'i' || test[i] == 'o' || test[i] == 'u') {
				return true;
			}
		}
		return false;
	}
	
	public static boolean isConsonant (char[] test) {
		
		int cnt = 0;
		for (int i = 0; i < test.length; i++) {
			if (test[i] != 'a' && test[i] != 'e' && test[i] != 'i' && test[i] != 'o' && test[i] != 'u') {
				cnt++;
				if (cnt == 2) {
					return true;
				}
			}
		}
		return false;
	}

}
