package Baekjoon;

import java.io.*;
import java.util.*;

public class B1780 {
	static int N;
	static int[][] paper;
	static int[] answer = new int[3];

	public static void main(String[] args) throws Exception {
		Reader in = new Reader();
		N = in.nextInt();
		paper = new int[N][N];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				paper[i][j] = in.nextInt();
			}
		}

		int res = solve(0, 0, N);
		if (res != -1) answer[res]++;
		System.out.println(answer[0]+"\n"+answer[1]+"\n"+answer[2]);
	}

	private static int solve(int r, int c, int size) {
		if (size == 1) {
			return paper[r][c]+1;
		}

		int prev = paper[r][c]+1;
		boolean allSame = true;
		for (int i = r; i < r + size; i += size/3) {
			for (int j = c; j < c + size; j += size / 3) {
				int res = solve(i, j, size / 3);
				if (res != -1) answer[res]++;
				if (res != prev) allSame = false;
			}
		}

		if (allSame) {
			answer[prev]-=9;
			return prev;
		} else {
			return -1;
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
