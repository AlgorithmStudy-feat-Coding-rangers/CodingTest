import java.util.ArrayList;
import java.util.Scanner;

class AdjListGraph {
	private ArrayList<ArrayList<Integer>> adjListGraph;
	private boolean visited[] = new boolean[1000];
	private int count = 0;
	
	public AdjListGraph(int size) {
		this.adjListGraph = new ArrayList<ArrayList<Integer>>(); // 그래프 생성
		for (int i = 0; i < size + 1; i++) {
			adjListGraph.add(new ArrayList<Integer>());
		}
	}

	public ArrayList<ArrayList<Integer>> getGraph() {
		return this.adjListGraph;
	}

	public ArrayList<Integer> getNode(int i) {
		return this.adjListGraph.get(i);
	}

	public int getNodeSize(int i) {
		return this.adjListGraph.get(i).size();
	}

	public void put(int x, int y) {
		adjListGraph.get(x).add(y);
		adjListGraph.get(y).add(x);
	}

	public void printGraphToAdjList() {
		for (int i = 1; i < adjListGraph.size(); i++) {
			System.out.print("정점 " + i + "의 인접리스트");

			for (int j = 0; j < adjListGraph.get(i).size(); j++) {
				System.out.print(" -> " + adjListGraph.get(i).get(j));
			}
			System.out.println();
		}
	}


	public void resetVisited() {
		for (int i = 0; i < 1000; i++) {
			visited[i] = false;
		}
	}

	public void DFS(int v) {
		visited[v] = true;
	    for (int i=0; i <adjListGraph.get(v).size(); i++) {
	    	int y = adjListGraph.get(v).get(i);
	        if (visited[y] == false){
	        	DFS(y);
	        	count++;
	        }
	    }
	}
	
	public int getCount() {
		return count;
	}

}

public class Virus {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int count, num;
		
		Scanner sc = new Scanner(System.in);
		count = sc.nextInt();
		num = sc.nextInt();
		
		AdjListGraph list = new AdjListGraph(count);
		
		for(int i = 0; i < num; i++) {
			int first, end;
			first = sc.nextInt();
			end = sc.nextInt();
			list.put(first, end);
		}
		
		list.DFS(1);
		
		System.out.println(list.getCount());
	}

}
