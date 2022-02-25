import java.util.*;

public class Integer_Triangle {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[][] arr = new int[n][];
		
		for (int i = 0; i < n; i++) {
			arr[i] = new int[i + 1];
			
			for (int j = 0; j <= i; j++)
				arr[i][j] = s.nextInt();
		}
		
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < i; j++)
				arr[i - 1][j] += Math.max(arr[i][j], arr[i][j + 1]);
		}
		System.out.println(arr[0][0]);
	}
}
