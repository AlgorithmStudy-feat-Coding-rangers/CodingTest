import java.util.Scanner;

public class Main {

	static int [] zero;
	static int [] one;
	
	static int fibonnacci(int n, int i) {
		if(n==0) {
			zero[i]++;
			return 0;
		}else if(n ==1) {
			one[i]++;
			return 1;
		}else {
			return fibonnacci(n-1, i) + fibonnacci(n-2, i);
		}
	}
	
	static void initArray(int size) {
		for(int i = 0; i < size; i++) {
			zero[i] = 0;
			one[i] = 0;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		zero = new int[T];
		one = new int[T];
		initArray(T);
		
		for(int i = 0; i< T; i++) {
			int tmp = sc.nextInt();
			fibonnacci(tmp, i);
		}
		
		for(int i = 0; i< T; i++) {
			System.out.println(zero[i] + " " + one[i]);
		}
		
	}
}
