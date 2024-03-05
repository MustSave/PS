package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class B15659 {
	static int N;
	static int[] nums = new int[11];
	static int[] operators = new int[4]; // + - * /
	static int[] tmp = new int[10];
	static Deque<Integer> dq = new ArrayDeque<>(22);
	static int max = Integer.MIN_VALUE;
	static int min = Integer.MAX_VALUE;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			nums[i] = Integer.parseInt(st.nextToken());
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < 4; i++) {
			operators[i] = Integer.parseInt(st.nextToken());
		}

		dfs(0);
		System.out.println(max);
		System.out.println(min);
	}

	static void dfs(int depth) {
		if (depth == N-1) {
			calculate();
			return;
		}

		for (int i = 0; i < 4; i++) {
			if (operators[i] == 0) continue;

			operators[i]--;
			tmp[depth] = i;
			dfs(depth+1);
			operators[i]++;
		}
	}

	private static void calculate() {
		dq.addLast(nums[0]);
		for (int i = 0; i < N-1; i++) {
			int n = nums[i+1];
			if (tmp[i] > 1) {
				n = operate(tmp[i], dq.pollLast(), n);
			} else {
				dq.addLast(tmp[i]);
			}
			dq.addLast(n);
		}

		int ans = dq.pollFirst();
		while (!dq.isEmpty()) {
			ans = operate(dq.pollFirst(), ans, dq.pollFirst());
		}

		max = Math.max(max, ans);
		min = Math.min(min, ans);
	}

	private static int operate(int op, int a, int b) {
		switch (op) {
			case 0:
				return a + b;
			case 1:
				return a - b;
			case 2:
				return a * b;
			case 3:
				return a / b;
			default:
				throw new RuntimeException();
		}
	}
}
