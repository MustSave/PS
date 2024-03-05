package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class 애너그램_6443 {
	static char[] inputs;
	static char[] anagram;
	static boolean[] used;
	static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			inputs = br.readLine().toCharArray();
			Arrays.sort(inputs);
			anagram = new char[inputs.length];
			used = new boolean[inputs.length];
			solve(0);
		}
		System.out.println(sb);
	}

	private static void solve(int depth) {
		if (depth == inputs.length) {
			sb.append(anagram);
			sb.append('\n');
			return;
		}
		char prev = 0;
		for (int i = 0; i < inputs.length; i++) {
			if (used[i] || inputs[i] == prev) continue;

			used[i] = true;
			anagram[depth] = inputs[i];
			solve(depth+1);
			used[i] = false;
			anagram[depth] = 0;
			prev = inputs[i];
		}
	}
}