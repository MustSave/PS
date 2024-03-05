package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B23030 {
	static int[] input = new int[4];
	static int[][] dij;
	static StringBuilder sb = new StringBuilder();
	static List<Q>[][] graph;

	public static void main(String[] args) throws Exception {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		dij = new int[N+1][];
		graph = new List[N+1][];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			int n = Integer.parseInt(st.nextToken());
			dij[i] = new int[n+1];
			graph[i] = new List[n+1];
			for (int j = 1; j < graph[i].length; j++) {
				graph[i][j] = new ArrayList<>();
				if (j > 1) graph[i][j].add(new Q(1, i, j-1));
				if (j+1 < graph[i].length) graph[i][j].add(new Q(1, i, j+1));
			}
		}

		int M = Integer.parseInt(br.readLine());
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			Station stationA = new Station(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			Station stationB = new Station(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			graph[stationA.line][stationA.nth].add(new Q(-1, stationB));
			graph[stationB.line][stationB.nth].add(new Q(-1, stationA));
		}

		int K = Integer.parseInt(br.readLine());
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			int T = Integer.parseInt(st.nextToken());
			for (int j = 0; j < 4; j++) {
				input[j] = Integer.parseInt(st.nextToken());
			}

			solve(T);
		}

		System.out.println(sb);
	}

	private static void solve(int t) {
		int startLine = input[0];
		int startStation = input[1];

		PriorityQueue<Q> pq = new PriorityQueue<>();
		for (int i = 1; i < dij.length; i++) {
			Arrays.fill(dij[i], Integer.MAX_VALUE);
		}

		dij[startLine][startStation] = 0;
		pq.offer(new Q(0, startLine, startStation));

		while (!pq.isEmpty()) {
			Q item = pq.poll();
			Station station = item.station;
			if (item.time > dij[station.line][station.nth]) continue;

			for (Q q : graph[station.line][station.nth]) {
				Station s = q.station;
				int nextCost = item.time + (q.time == -1 ? t : 1);
				if (dij[s.line][s.nth] > nextCost) {
					dij[s.line][s.nth] = nextCost;
					pq.offer(new Q(nextCost, s));
				}
			}
		}

		sb.append(dij[input[2]][input[3]]).append('\n');
	}
}

class Station {
	int line;
	int nth;
	public Station(int line, int nth) {
		super();
		this.line = line;
		this.nth = nth;
	}
}

class Q implements Comparable<Q>{
	int time;
	Station station;
	public Q(int time, int line, int stationNum) {
		super();
		this.time = time;
		this.station = new Station(line, stationNum);
	}

	public Q(int time, Station station) {
		this.time = time;
		this.station = station;
	}

	@Override
	public int compareTo(Q o) {
		return Integer.compare(time, o.time);
	}
}
