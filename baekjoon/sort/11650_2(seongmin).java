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
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        list = new ArrayList<Point>();
        for(int i = 0; i< N; i++){
           int x = sc.nextInt();
           int y = sc.nextInt();
           list.add(new Point(x,y));
        }

        Collections.sort(list, new Comparator<Point>() {
            @Override
            public int compare(Point s1, Point s2) {
                if (s1.getX() == s2.getX()) {
                    return s1.getY() - s2.getY();
                } else{
                    return s1.getX() - s2.getX();
                }
            }
        });

        for(int i = 0; i< N; i++) {
        	System.out.println(list.get(i).getX()+ " " + list.get(i).getY());
        }
        
    }

}