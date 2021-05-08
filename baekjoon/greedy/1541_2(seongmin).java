import java.util.ArrayList;
import java.util.Scanner;

public class LostBracketProb {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String expression;
		
		Scanner sc = new Scanner(System.in);
		expression = sc.next();
		
		String [] tmp = expression.split("");
		int sum = 0;
		boolean minusCheck = false;
		StringBuilder sb = new StringBuilder();
		
		/** ������ - �� ���� ��� �տ� �ִ� ���� �����ְ� �ڿ� �ִ� ���� -�� �ϵ��� minusCheck�� ���ش�.*/
		/** ex) 1+3-4+5 �� 1+3-(4+5)=-5 **/
		for(String s : tmp) {
			if(!minusCheck && s.equals("-")) { 
				minusCheck = true;
				String num = sb.toString();
				sum += Integer.parseInt(num);
				sb.setLength(0);
			}else if(!minusCheck && s.equals("+")) {
				String num = sb.toString();
				sum += Integer.parseInt(num);
				sb.setLength(0);
			}else if(minusCheck && (s.equals("+") || s.equals("-"))) {
				String num = sb.toString();
				sum -= Integer.parseInt(num);
				sb.setLength(0);
			}else {
				sb.append(s);	
			}
		}
		
		/** ���� �ִ� number�� ó�� **/
		if (minusCheck) {
			String num = sb.toString();
			sum -= Integer.parseInt(num);
		} else {
			String num = sb.toString();
			sum += Integer.parseInt(num);
		}
		
		System.out.println(sum);
	}

}
