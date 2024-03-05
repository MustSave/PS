package Baekjoon;

import java.io.*;

public class B14891 {
	static int[] gears = new int[4];
	static int msbSelector = 1<<7;
	static int rightSelector = 1<<5;
	static int leftSelector = 1<<1;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int i = 0; i < 4; i++) {
			gears[i] = Integer.parseInt(br.readLine(), 2);
		}

		int N = Integer.parseInt(br.readLine());
		int sum = 0;

		for (int n = 0; n < N; n++) {
			String s = br.readLine();

			int gearIdx = s.charAt(0) - '0' - 1;
			boolean cw = s.charAt(2) == '1';

			operate(gearIdx, cw, -2);
		}

		for (int i = 0; i < 4; i++) {
			if (getTop(gears[i])) sum += 1<<i;
		}
		System.out.println(sum);
	}

	private static void operate(int gearIdx, boolean cw, int prev) {
		int gear = gears[gearIdx];
		boolean l = getLeft(gear);
		boolean r = getRight(gear);

		gears[gearIdx] = rotate(gear, cw);

		int leftIdx = gearIdx-1;
		int rightIdx = gearIdx+1;

		if (leftIdx >= 0 && leftIdx != prev && getRight(gears[leftIdx]) != l) {
			operate(leftIdx, !cw, gearIdx);
		}

		if (rightIdx < 4 && rightIdx != prev && getLeft(gears[rightIdx]) != r) {
			operate(rightIdx, !cw, gearIdx);
		}
	}

	static boolean getRight(int n) {
		return (n & rightSelector) != 0;
	}

	static boolean getLeft(int n) {
		return (n & leftSelector) != 0;
	}

	static boolean getTop(int n) {
		return (n & msbSelector) != 0;
	}

	static int rotate(int n, boolean isCw) {
		if (isCw) {
			int lsb = n & 1;
			n = lsb == 1 ? (n >>> 1) | msbSelector : (n >>> 1) & (~msbSelector);
		} else {
			int msb = n & msbSelector;
			n = msb == 0 ? (n << 1) : (n << 1) | 1;
		}

		return n;
	}

}