import java.util.Scanner;

public class ATMProblem {
	
	static int[] sortingTime(int[] time) {
		int minIndex;
		int i, j;
		for (i = 0; i < time.length - 1; i++) {
			minIndex = i;
			for (j = i + 1; j < time.length; j++) 
				if (time[j] < time[minIndex])
					minIndex = j;
			
			int tmp = time[i];
			time[i] = time[minIndex];
			time[minIndex] = tmp;
		}
		return time;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int num;
		int[] time;
		
		Scanner sc = new Scanner(System.in);
		num = sc.nextInt();
		
		time = new int[num];
		for (int i = 0; i< num; i++) {
			time[i] = sc.nextInt();
		}
		
		time = sortingTime(time);
		
		int sum = 0;
		for(int i = 0; i< time.length; i++) {
			int k = i;
			while(k>=0) {
				sum += time[k--];
			}
		}
		System.out.println(sum);
	}
}
