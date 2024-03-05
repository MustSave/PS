package Baekjoon;

import java.util.*;

public class B20056 {
	static int fireballId = 0;
	static int N, M, K;
	static FireBall[][] map;
	static int[][] dirs = {
		{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1},
	};

	static Deque<FireBall> queue = new ArrayDeque<>();

	public static void main(String[] args) throws Exception {
		Reader reader = new Reader();
		N = reader.nextInt();
		M = reader.nextInt();
		K = reader.nextInt();
		map = new FireBall[N][N];

		for (int i = 0; i < M; i++) {
			FireBall fireBall = new FireBall(reader.nextInt()-1, reader.nextInt()-1, reader.nextInt(), reader.nextInt(), reader.nextInt(), 0);
			queue.offerLast(fireBall);
		}

		solve();
		int ans = 0;
		while (!queue.isEmpty()) {
			FireBall fireBall = queue.pollFirst();
			ans += fireBall.합체 ? fireBall.mass / 5 * 4 : fireBall.mass;
		}
		System.out.print(ans);
	}

	private static void solve() {
		int 시간 = 0;
		while (!queue.isEmpty() && 시간 < K) {
			int 큐_크기 = queue.size();
			for (; 큐_크기 > 0; 큐_크기--) {
				FireBall 파이어볼 = queue.pollFirst();
				FireBall tmp = map[파이어볼.r][파이어볼.c];
				if (tmp != null && tmp.id == 파이어볼.id) map[파이어볼.r][파이어볼.c] = null;

				if (파이어볼.합체) {
					큐_크기 += 파이어볼.쪼개기();
					continue;
				}

				파이어볼.이동();
				tmp = map[파이어볼.r][파이어볼.c];
				if (tmp == null || tmp.version < 파이어볼.version) {
					map[파이어볼.r][파이어볼.c] = 파이어볼;
					queue.offerLast(파이어볼);
				} else {
					tmp.합체(파이어볼);
				}
			}
			시간++;
		}
	}

	static class FireBall {
		int id;
		int r, c, mass, dirIdx, speed, version;
		int 합체수 = 1;
		boolean 합체, 같은방향 = true;

		public FireBall(int r, int c, int mass, int speed, int dirIdx, int version) {
			this.id = fireballId++;
			this.r = r;
			this.c = c;
			this.mass = mass;
			this.speed = speed;
			this.dirIdx = dirIdx;
			this.version = version;
		}

		public void 이동() {
			r = (r + dirs[dirIdx][0] * speed) % N;
			c = (c + dirs[dirIdx][1] * speed) % N;
			if (r < 0) r += N;
			if (c < 0) c += N;
			version++;
		}

		public void 합체(FireBall fireBall) {
			mass += fireBall.mass;
			speed += fireBall.speed;
			if (같은방향 && dirIdx % 2 != fireBall.dirIdx % 2) 같은방향 = false;
			합체수++;
			합체 = true;
		}

		public int 쪼개기() {
			int newMass = mass / 5;
			if (newMass == 0) return 0;
			int newSpeed = speed/합체수;

			for (int i = 0; i < 4; i++) {
				FireBall fireBall = new FireBall(r, c, newMass, newSpeed, (i<<1) + (같은방향 ? 0 : 1), version);
				queue.offerFirst(fireBall);
			}
			return 4;
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