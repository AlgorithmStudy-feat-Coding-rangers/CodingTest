import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	static int N;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		String[] word = new String[N];
		for(int i = 0; i< N; i++) {
			word[i] = sc.next();
		}
		
		Arrays.sort(word, new Comparator<String>() {		
			@Override
			public int compare(String s1, String s2) {
				if(s1.length() == s2.length()) {
					return s1.compareTo(s2);
				}else {
					return s1.length() - s2.length();
				}
			}
		});
		
		System.out.println(word[0]);
		
		for(int i = 1; i< N; i++) {
			if(!word[i].equals(word[i-1]))
				System.out.println(word[i]);
		}
	}

}
