package Baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B13905 {
	static int N, M, s, e;
	static List<int[]>[] graph;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		s = Integer.parseInt(st.nextToken());
		e = Integer.parseInt(st.nextToken());

		graph = new List[N+1];
		for (int i = 1; i <= N; i++) {
			graph[i] = new ArrayList<>();
		}

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());

			graph[a].add(new int[]{b, c});
			graph[b].add(new int[]{a, c});
		}

		System.out.println(solve());
	}

	private static int solve() {
		PriorityQueue<Item> pq = new PriorityQueue<>((o1, o2) -> {
			return -Integer.compare(o1.minWeight, o2.minWeight);
		});
		boolean[] visited = new boolean[N+1];

		pq.add(new Item(s, Integer.MAX_VALUE));

		while (!pq.isEmpty()) {
			Item cur = pq.poll();

			if (visited[cur.house]) continue;
			visited[cur.house] = true;

			if (cur.house == e) {
				return cur.minWeight;
			}

			for (int[] next: graph[cur.house]) {
				if (visited[next[0]]) continue;
				pq.add(new Item(next[0], Math.min(cur.minWeight, next[1])));
			}
		}

		return 0;
	}

	static class Item {
		int house;

		public Item(int house, int minWeight) {
			this.house = house;
			this.minWeight = minWeight;
		}

		int minWeight;
	}
}
