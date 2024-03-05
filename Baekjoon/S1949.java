package Baekjoon;

import java.util.*;

public class S1949 {
	static int N, K;
	static int max, ans;
	static int[][] map = new int[8][8];
	static boolean[][] visited = new boolean[8][8];
	static int[][] dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	static List<int[]> top = new ArrayList<>();

	public static void main(String[] args) throws Exception {
		StringBuilder sb = new StringBuilder();
		Reader reader = new Reader();
		int T = reader.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			max = 0;
			ans = 0;
			N = reader.nextInt();
			K = reader.nextInt();

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = reader.nextInt();
					if (max <= map[i][j]) {
						if (max < map[i][j]) {
							max = map[i][j];
							top.clear();
						}
						top.add(new int[]{i, j});
					}
				}
			}

			solve();
			sb.append('#').append(tc).append(' ').append(ans).append('\n');
		}
		System.out.println(sb);
	}

	private static void solve() {
		for (int[] coord: top) {
			int i = coord[0], j = coord[1];
			visited[i][j] = true;
			dfs(i, j, max, false, 1);
			visited[i][j] = false;
		}
	}

	static void dfs(int r, int c, int height, boolean 깎음, int len) {
		if (len + height <= ans) return;

		boolean finished = true;

		for (int[] dir: dirs) {
			int nr = r + dir[0], nc = c + dir[1];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N || visited[nr][nc]) continue;
			if (map[nr][nc] >= height) {
				if (!깎음 && height-1 >= map[nr][nc] - K) {
					finished = false;
					visited[nr][nc] = true;
					dfs(nr, nc, height-1, true, len+1);
					visited[nr][nc] = false;
				}
				continue;
			}

			finished = false;
			visited[nr][nc] = true;
			dfs(nr, nc, map[nr][nc], 깎음, len+1);
			visited[nr][nc] = false;
		}

		if (finished) {
			ans = Math.max(ans, len);
		}
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