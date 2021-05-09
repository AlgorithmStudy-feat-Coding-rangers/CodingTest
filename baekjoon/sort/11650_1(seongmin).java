import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class Point {
	int x;
	int y;

	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	int getX() {
		return x;
	}
	
	int getY() {
		return y;
	}
}


public class Main {
	static ArrayList<Point> list;
	static int N ;
	
	static void swap(int first, int second) {
		Point tmpFirst = list.get(first);
		list.set(first, list.get(second));
		list.set(second, tmpFirst);
	}
	
	static void sorting() {
		for(int i = 0; i< N-1; i++) {
			int least = i;
			for(int j = i+1; j < N; j++) {
				if(list.get(j).getX() < list.get(least).getX()) {
					least = j;
				}
				else if (list.get(j).getX() == list.get(least).getX()) {
					if(list.get(j).getY() < list.get(least).getY()) {
						least = j;
					}
				}
			}
			swap(i, least);
		}
	}
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        list = new ArrayList<Point>();
        for(int i = 0; i< N; i++){
           int x = sc.nextInt();
           int y = sc.nextInt();
           list.add(new Point(x,y));
        }

        sorting();
        for(int i = 0; i< N; i++) {
        	System.out.println(list.get(i).getX()+ " " + list.get(i).getY());
        }
        
    }

}