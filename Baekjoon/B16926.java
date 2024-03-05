package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B16926 {
	static int[][] arr;
	static int[][] ans;
	static int N, M, R;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		arr = new int[N][M];
		ans = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int min = Math.min(N, M);
		for (int i = 0; i*2 < min; i++) {
			int n = N - i*2;
			int m = M - i*2;
			Iterator iterator = new Iterator(i, i, n, m);
			Iterator iterator2 = iterator.getRotatedIterator(R);

			int k = (n+m-2)<<1;
			while (k-- > 0) {
				int[] a = iterator.getNext();
				int[] b = iterator2.getNext();
				ans[b[0]][b[1]] = arr[a[0]][a[1]];
			}
		}

		print();
	}

	private static void print() {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append(ans[i][j]);
				if (j != M-1) sb.append(' ');
			}
			if (i != N-1) sb.append('\n');
		}
		System.out.print(sb);
	}
}

class Iterator {
	int x1, y1, x2, y2;
	int n, m;
	int[] cur = {0, 0};
	int dirIdx;
	boolean b = true;
	static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	public Iterator(int x1, int y1, int n, int m) {
		super();
		this.x1 = x1;
		this.y1 = y1;
		this.n = n;
		this.m = m;
		this.x2 = x1 + n -1;
		this.y2 = y1 + m -1;
		cur[0] = x1;
		cur[1] = y1;
	}

	public Iterator getRotatedIterator(int r) {
		r = r % ((n+m-2)<<1);
		int dx = 0, dy = 0, nd = 0;

		for (int i = 0 ; i < 4; i++) {
			int m = Math.min(r, (i&1) == 0 ? this.n-1 : this.m-1);
			switch (i) {
				case 0:
					dx += m;
					break;
				case 1:
					dy += m;
					break;
				case 2:
					dx -= m;
					break;
				case 3:
					dy -= m;
					break;
			}
			r -= m;
			if (r > 0) nd = i+1;
		}

		Iterator it = new Iterator(x1, y1, n, m);
		it.cur[0] += dx;
		it.cur[1] += dy;
		it.dirIdx = nd;

		return it;
	}

	public int[] getNext() {
		if (b) {
			b = false;
			return cur;
		}

		int nx = cur[0] + dir[dirIdx][0], ny = cur[1] + dir[dirIdx][1];
		if (x1 > nx || y1 > ny || x2 < nx || y2 < ny) {
			dirIdx = (dirIdx +1) % 4;
			nx = cur[0] + dir[dirIdx][0];
			ny = cur[1] + dir[dirIdx][1];
		}

		cur[0] = nx;
		cur[1] = ny;

		return cur;
	}
}