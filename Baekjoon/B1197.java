package Baekjoon;

import java.util.*;

public class B1197 {
	static int V, E;
	static PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1[0], o2[0]));
	static int[] parent;

	public static void main(String[] args) throws  Exception {
		Reader reader = new Reader();
		V = reader.nextInt();
		E = reader.nextInt();
		parent = new int[V+1];
		for (int i = 1; i <= V; i++) parent[i] = i;

		for (int e = 0; e < E; e++) {
			int a = reader.nextInt();
			int b = reader.nextInt();
			int c = reader.nextInt();

			pq.offer(new int[]{c, a, b});
		}

		System.out.println(solve());
	}

	static int solve() {
		int ans = 0, connected = 1;

		while (!pq.isEmpty()) {
			int[] edge = pq.poll();

			if (union(edge[1], edge[2])) {
				ans += edge[0];
				if (++connected == V) break;
			}
		}

		return ans;
	}

	static int find(int n) {
		if (parent[n] != n) {
			parent[n] = find(parent[n]);
		}
		return parent[n];
	}

	static boolean union(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return false;

		if (a < b) {
			parent[b] = a;
		} else {
			parent[a] = b;
		}
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
