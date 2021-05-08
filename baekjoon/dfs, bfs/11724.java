import java.util.ArrayList;
import java.util.Scanner;


class AdjListGraph {
	private ArrayList<ArrayList<Integer>> adjListGraph;
	private boolean visited[] = new boolean[1001];
	
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
	        }
	    }
	}
	
	public boolean[] getVisited() {
		return visited;
	}

}

public class CountConnection {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int node, edge;
		
		node = sc.nextInt();
		edge = sc.nextInt();
		
		AdjListGraph alg = new AdjListGraph(node);
		
		for(int i = 0; i < edge; i++) {
			int first, end;
			first = sc.nextInt();
			end = sc.nextInt();
			alg.put(first, end);
		}
		
		int connectionCount = 0;
		for (int i = 1; i < node + 1; i++) {
			boolean[] visited = alg.getVisited();
			if (!visited[i]) {
				connectionCount++;
				alg.DFS(i);
			}
		}
		System.out.println(connectionCount);

	}
}
