import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
	
class Point {
	int x;
	int y;

	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

public class Maze { //2178
	
	private static int[][] maze;
	private static int row, col;
	private static boolean[][] visited;
    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, -1, 0, 1 };

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		row = sc.nextInt();
		col = sc.nextInt();
		
		maze = new int[row][col];
		visited = new boolean[row][col];
		
		String tmp = null;
		for(int i = 0; i< row; i++) {
			tmp = sc.next();
			String [] ary = tmp.split("");
			for(int j = 0; j< ary.length; j++) {
				maze[i][j]= Integer.parseInt(ary[j]); // tmp.charAt(j)-'0'; 도 같은 기능!
				visited[i][j] = false;
			}
		}
		
		visited[0][0] = true;
		BFS(0,0);
		System.out.println(maze[row-1][col-1]);
	}

	
	private static void BFS(int x, int y) {
		Queue<Point> q = new LinkedList<Point>();
        q.add(new Point(x, y));
        while (!q.isEmpty()) {
        	Point d = q.poll();
            for (int i = 0; i < 4; i++) {
                int nextX = d.x + dx[i];
                int nextY = d.y + dy[i];
                
                if (nextX < 0 || nextY < 0 || nextX >= row || nextY >= col) {
                    continue;
                }
                if (visited[nextX][nextY] || maze[nextX][nextY] == 0) {
                    continue;
                }
                q.add(new Point(nextX, nextY));
                
                maze[nextX][nextY] = maze[d.x][d.y] + 1;
                
                visited[nextX][nextY] = true;
            }
        }
	}


}
