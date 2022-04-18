import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Previous_permutation2 {
	
	public static int N;
	public static int[] arr;
	public static StringBuilder sb = new StringBuilder();
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		if (prevPermutation(arr)) {
			for (int val : arr) {
				sb.append(val).append(' ');
			}
		}else {
			sb.append(-1);
		}
		System.out.println(sb);

	}
	
	public static boolean prevPermutation(int[] arr) {
		int i = arr.length - 1;
		
		while (i > 0 && arr[i] > arr[i - 1]) {
			i--;
		}
		if (i == 0) {
			return false;
		}
		int j = arr.length - 1;
		while (arr[i - 1] < arr[j]) {
			j--;
		}
		swap(arr, i - 1, j);
		j = arr.length - 1;
		while (i < j) {
			swap(arr, i, j);
			i++;
			j--;
		}
		return true;
	}
	
	public static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

}
