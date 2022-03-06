import java.util.*;

public class Dwarfs {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] height = new int[9];
		int sum = 0;
		
		for (int i = 0; i < 9; i++) {
			height[i] = sc.nextInt();
			sum += height[i];
		}
		Arrays.sort(height);
		for (int i = 0; i < 9; i++) {
			for (int j = i + 1; j < 9; j++) {
				if (sum - height[i] - height[j] == 100) {
					for (int k = 0; k < 9; k++) {
						if (k == i || k == j) {
							continue ;
						}
						System.out.println(height[k]);
					}
					System.exit(0);
				}
			}
		}	
	}
}
