package Baekjoon;

import java.io.*;
import java.util.*;

public class B1414 {
	static int N;
	static int totalLen = 0;
	static int[] parent;
	static PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[2]));

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		parent = new int[N];
		for (int i = 0; i < N; i++) parent[i] = i;

		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < N; j++) {
				char c = s.charAt(j);
				if (Character.isLowerCase(c)) {
					int len = c - 'a' + 1;
					totalLen += len;
					pq.offer(new int[]{i, j, len});
				} else if (Character.isUpperCase(c)) {
					int len = c - 'A' + 27;
					totalLen += len;
					pq.offer(new int[]{i, j, len});
				}
			}
		}

		System.out.println(solve());
	}

	static int solve() {
		if (N == 1) {
			return pq.size() == 0 ? 0 : pq.peek()[2];
		}
		int connected = 1;
		int cost = 0;
		while (!pq.isEmpty()) {
			int[] e = pq.poll();
			if (union(e[0], e[1])) {
				cost += e[2];
				if (++connected == N) return totalLen - cost;
			}
		}
		return -1;
	}

	static int find(int n) {
		if (parent[n] != n) parent[n] = find(parent[n]);
		return parent[n];
	}

	static boolean union(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return false;
		if (a < b) parent[b] = a;
		else parent[a] = b;
		return true;
	}
}
