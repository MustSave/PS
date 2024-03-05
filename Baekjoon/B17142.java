package Baekjoon;

import java.util.*;

public class B17142 {
	static int N, M;
	static int[][] map;
	static int[][] viruses = new int[10][2];
	static int virusIdx;
	static int emptySpaceCount = 0;
	static int[][] selectedViruses;
	static Queue<int[]> queue = new ArrayDeque<>();
	static int version = 0;
	static int[][] dirs = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
	static int ans = Integer.MAX_VALUE;

	public static void main(String[] args) throws Exception {
		Reader reader = new Reader();
		N = reader.nextInt();
		M = reader.nextInt();
		map = new int[N][N];
		selectedViruses = new int[M][];

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				map[r][c] = reader.nextInt();
				if (map[r][c] == 2) {
					viruses[virusIdx][0] = r;
					viruses[virusIdx++][1] = c;
					map[r][c] = Integer.MIN_VALUE;
				} else if (map[r][c] == 0) {
					emptySpaceCount++;
				} else {
					map[r][c] = Integer.MAX_VALUE;
				}
			}
		}

		if (emptySpaceCount > 0) {
			solve();
			System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
		} else {
			System.out.println(0);
		}
	}

	static void swap(int[] p, int i, int j){
		p[i] ^= p[j];
		p[j]^= p[i];
		p[i] ^= p[j];
	}

	static boolean perm(int[] p) {
		int length = p.length;
		int i = length-1;
		while(i>0 && p[i-1]>=p[i]) i--;
		if(i==0) return false;

		int j = length-1;
		while(j>i && p[i-1] >= p[j]) j--;

		swap(p, i-1, j);

		int k = length - 1;
		while(i<k) swap(p, i++, k--);
		return true;
	}

	private static void solve() {
		int[] p = new int[virusIdx];
		for (int i = virusIdx - M; i < virusIdx; i++) {
			p[i]=1;
		}

		do {
			version++;
			queue.clear();
			for (int i = 0; i < virusIdx; i++) {
				if (p[i] == 1) {
					queue.offer(viruses[i]);
					map[viruses[i][0]][viruses[i][1]] = -version;
					if (queue.size() == M) break;
				}
			}
			int result = bfs();
			ans = Math.min(ans, result);
		} while(perm(p));
	}

	private static int bfs() {
		int emptySpaceFilled = 0;
		int time = 0;
		while (!queue.isEmpty() && time < ans-1) {
			int size = queue.size();
			time++;
			while (size-- > 0) {
				int[] coord = queue.poll();
				int r = coord[0], c = coord[1];

				for (int[] dir: dirs) {
					int nr = r + dir[0], nc = c + dir[1];
					if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;

					int val = map[nr][nc];
					if (val >= version || val == -version) continue; // 벽 = int max 또는 이번 버전에서 이미 방문

					if (val >= 0) { // 음수(비활성 바이러스)를 제외하고는 version보다 작으면 빈 공간임
						map[nr][nc] = version;
						if (++emptySpaceFilled == emptySpaceCount) return time;
					} else {  // 비활성 바이러스
						map[nr][nc] = -version;
					}
					queue.offer(new int[]{nr, nc});
				}
			}
		}

		return Integer.MAX_VALUE;
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
