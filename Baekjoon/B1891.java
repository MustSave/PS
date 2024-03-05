package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class B1891 {
	static int d;
	static long dx, dy;
	static String quadNum;
	static char[] ans;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		StringTokenizer st = new StringTokenizer(br.readLine());
		d = Integer.parseInt(st.nextToken());
		quadNum = st.nextToken();
		ans = new char[quadNum.length()];

		st = new StringTokenizer(br.readLine());
		dy = Long.parseLong(st.nextToken());
		dx = -Long.parseLong(st.nextToken());

		System.out.print(solve());
	}

	private static char[] solve() {
		long width = 1;
		for (int i = 0; i < quadNum.length(); i++, width <<= 1) {}

		long[] coord = toCoord(quadNum);
		coord[0] += dx; coord[1] += dy;

		if (coord[0] < 0 || coord[0] >= width || coord[1] < 0 || coord[1] >= width) return new char[]{'-','1'};
		return toQuadNum(coord, width);
	}

	static long[] toCoord(String quadNum) {
		long dx = 0, dy = 0, multiplier = 1;

		for (int i = quadNum.length()-1; i >= 0; i--, multiplier <<= 1) {
			int quad = quadNum.charAt(i) - '0';

			if (quad > 2) dx += multiplier;
			if (quad == 1 || quad == 4) dy += multiplier;
		}

		return new long[]{dx, dy};
	}

	static char[] toQuadNum(long[] coord, long quadWidth) {
		quadWidth>>=1;
		for (int i = 0; quadWidth > 0; i++, quadWidth>>=1) {
			if (coord[0] < quadWidth) {
				ans[i] = coord[1] >= quadWidth ? '1' : '2';
			} else {
				ans[i] = coord[1] < quadWidth ? '3' : '4';
			}
			coord[0] %= quadWidth;
			coord[1] %= quadWidth;
		}
		return ans;
	}
}
