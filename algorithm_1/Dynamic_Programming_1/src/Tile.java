import java.util.*;

public class Tile {
	
	private static int n;
	private static int[] arr;
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		n = s.nextInt();
		
		arr = new int[n + 1];
		if (n % 2 == 0) {
			arr[0] = 1;
			arr[2] = 3;
			
			for (int i = 4; i <= n; i += 2) {
				arr[i] = arr[i - 2] * arr[2];
				
				for (int j = i - 4; j >= 0; j -= 2) {
					arr[i] += (arr[j] * 2);
				}
			}
		}
		
		System.out.println(arr[n]);
	}

}
