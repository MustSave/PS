package Baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B16168 {
	static int V, E;
	static int[] graph;
	static int[] parent;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());

		graph = new int[V+1];
		parent = new int[V+1];
		for (int i = 1; i <= V; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());

			int pa = find(a);
			int pb = find(b);
			if (pa != pb) {
				union(pa, pb);
			}

			graph[a]++;
			graph[b]++;
		}

		System.out.println(solve() ? "YES" : "NO");
	}

	static boolean solve() {
		int oddDegree = 0;
		int root = find(1);
		for (int i = 1; i < V; i++) {
			if (graph[i] % 2 == 1 && ++oddDegree > 2) return false;
			if (root != find(i)) return false;
		}

		return true;
	}

	static int find(int n) {
		if (parent[n] != n) {
			parent[n] = find(parent[n]);
		}
		return parent[n];
	}

	static void union(int pa, int pb) {
		if (pa > pb) {
			parent[pa] = pb;
		} else {
			parent[pb] = pa;
		}
	}
}
