package Baekjoon;

import java.util.*;

public class B17144 {
	static int R, C, T;
	static Space[][] spaces;
	static int[] UP = {-1, 0};
	static int[] DOWN = {1, 0};
	static int[] LEFT = {0, -1};
	static int[] RIGHT = {0, 1};
	static int[][][] dirs = {
		{RIGHT, UP, LEFT, DOWN}, // ccw
		{RIGHT, DOWN, LEFT, UP}, // cw
	};
	static Queue<Space> queue = new ArrayDeque<>();
	static int[][] cleaners = new int[2][];

	public static void main(String[] args) throws  Exception {
		Reader reader = new Reader();
		R = reader.nextInt();
		C = reader.nextInt();
		T = reader.nextInt();
		spaces = new Space[R][C];
		int cleanerIdx = 0;

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				int dust = reader.nextInt();
				spaces[r][c] = new Space(r, c, dust);
				if (dust > 0) queue.offer(spaces[r][c]);
				else if (dust == -1) cleaners[cleanerIdx++] = new int[]{r, c};
			}
		}

		solve();

		int ans = 0;
		while (!queue.isEmpty()) {
			ans += queue.poll().getDust(T);
		}
		System.out.println(ans);
	}

	static void print(int time) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				System.out.printf("%3d ", spaces[i][j].getDust(time));
			}
			System.out.println();
		}
	}

	static void solve() {
		int time = 0;

		while (time < T) {
			int size = queue.size();

			while (size-- > 0) {
				Space space = queue.poll();
				int r = space.r, c = space.c;

				if (space.version < time) {
					queue.offer(space);
				}
				int dust = space.getDust(time);
				int dustToBeSpread = dust / 5;

				if (dustToBeSpread == 0) continue;

				for (int[] dir: dirs[0]) {
					int nr = r + dir[0], nc = c + dir[1];
					if (nr < 0 || nc < 0 || nr >= R || nc >= C || spaces[nr][nc].dust == -1) continue;

					Space nextSpace = spaces[nr][nc];
					if (nextSpace.version < time) {
						queue.offer(nextSpace);
					}
					nextSpace.addDust(time, dustToBeSpread);
					space.addDust(time, -dustToBeSpread);
				}
			}

			for (int i = 0; i < 2; i++) {
				int r = cleaners[i][0], c = cleaners[i][1];
				int[][] dir = dirs[i];
				int dirIdx = 0;

				r = r + dir[dirIdx][0]; c = c + dir[dirIdx][1];
				Space space = spaces[r][c];
				while (true) {
					int nr = r + dir[dirIdx][0], nc = c + dir[dirIdx][1];
					if (nr < 0 || nc < 0 || nr >= R || nc >= C) {
						nr = r + dir[++dirIdx][0]; nc = c + dir[dirIdx][1];
					}

					Space nextSpace = spaces[nr][nc];
					if (nextSpace.dust == -1) {
						space.reset();
						space.r = cleaners[i][0];
						space.c = cleaners[i][1] + 1;
						spaces[cleaners[i][0]][cleaners[i][1] + 1] = space;
						break;
					}

					space.r = nr;
					space.c = nc;
					spaces[nr][nc] = space;
					space = nextSpace;
					r = nr; c = nc;
				}
			}
			time++;
		}
	}

	static class Space {
		int r, c;
		int dust;
		int version = -1;
		int tmp;

		public Space(int r, int c, int dust) {
			this.r = r;
			this.c = c;
			this.dust = dust;
		}

		public int getDust(int t) {
			if (version < t) {
				dust += tmp;
				version = t;
				tmp = 0;
			}
			return dust;
		}

		public void addDust(int t, int amount) {
			if (version < t) {
				dust += tmp;
				version = t;
				tmp = 0;
			}
			tmp += amount;
		}

		public void reset() {
			dust = 0;
			version = -1;
			tmp = 0;
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
