import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
public class Main {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int T = Integer.parseInt(br.readLine());
		int [] zero = new int[41];
		int [] one = new int[41];
		
		zero[0] = 1;
		zero[1] = 0;
		one[0] = 0;
		one[1] = 1;
		
		for(int i = 0; i< T; i++) {
			int tmp = Integer.parseInt(br.readLine());
			for(int j = 2; j <= tmp; j++) {
				zero[j] = zero[j-1] + zero[j-2];
				one[j] = one[j-1] + one[j-2];
			}
			bw.write(zero[tmp] + " " + one[tmp] + "\n");
		}
		br.close();
		bw.close();
	}
}
