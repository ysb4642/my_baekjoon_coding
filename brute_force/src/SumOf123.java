import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class SumOf123 {
	
	public static int T;
	public static int[] arr;
	public static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		arr = new int[10];
		
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 4;
		
		for (int i = 3; i < 10; i++) {
			arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
		}
		
		for (int i = 0; i < T; i++) {
			int n = Integer.parseInt(br.readLine());
			sb.append(arr[n - 1]);
			System.out.println(sb);
			sb.setLength(0);
		}

	}

}
