package Baekjoon;

import java.util.*;

public class B1647 {
	static int N, M;
	static PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o[2]));
	static int[] parent;

	public static void main(String[] args) throws Exception {
		Reader reader = new Reader();
		N = reader.nextInt();
		M = reader.nextInt();
		parent = new int[N+1];
		for (int i = 1; i <= N; i++) parent[i] = i;

		for (int i = 0; i < M; i++) {
			int a = reader.nextInt();
			int b = reader.nextInt();
			int c = reader.nextInt();

			pq.offer(new int[]{a, b, c});
		}

		System.out.println(solve());
	}

	static long solve() {
		int connected = 1;
		long cost = 0;
		long maxCost = 0;
		while (!pq.isEmpty()) {
			int[] e = pq.poll();
			if (union(e[0], e[1])) {
				cost += e[2];
				maxCost = Math.max(maxCost, e[2]);
				if (++connected == N) return cost - maxCost;
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

	static class Reader {
		final int SIZE = 1 << 15;
		byte[] buffer = new byte[SIZE];
		int index, size;

		int nextInt() throws Exception {
			int n = 0;
			byte c;
			while ((c = read()) <= 32)
				;
			boolean neg = c == '-' ? true : false;
			if (neg)
				c = read();
			do
				n = (n << 3) + (n << 1) + (c & 15);
			while (isNumber(c = read()));
			return neg ? -n : n;
		}

		boolean isNumber(byte c) {
			return 47 < c && c < 58;
		}

		byte read() throws Exception {
			if (index == size) {
				size = System.in.read(buffer, index = 0, SIZE);
				if (size < 0)
					buffer[0] = -1;
			}
			return buffer[index++];
		}
	}
}
