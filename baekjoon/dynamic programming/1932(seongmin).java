import java.util.Scanner;

public class Main {

	static int piramid[][];
	
	static int maxSum(int size) {
		int max = piramid[0][0];
		for(int i = 1; i < size; i++) {
			for(int j = 0; j<= i; j++) {
				if(j == 0) piramid[i][j] = piramid[i-1][j] + piramid[i][j];
				else if(j == i) piramid[i][j] = piramid[i-1][j-1] + piramid[i][j];
				else {
					piramid[i][j] = check(piramid[i-1][j-1], piramid[i-1][j]) + piramid[i][j];
				}
				max = check(max, piramid[i][j]);
			}
		}
		return max;
	}
	
	static int check(int a, int b) {
		return (a > b) ? a : b;
	}
	
	
	
	public static void main(String[] args){
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		piramid = new int[n][n];
		for(int i = 0; i< n; i++) {
			for(int j = 0; j<= i ; j++) {
				piramid[i][j] = sc.nextInt();
			}
		}
		int sum = maxSum(n);
		
		System.out.println(sum);
		
	}

}
