package SWEA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class S5215 {
	static int N, L;
	static int[][] ingredients = new int[20][2];
	static int[] dp = new int[10001];

	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				ingredients[i][0] = Integer.parseInt(st.nextToken());
				ingredients[i][1] = Integer.parseInt(st.nextToken());
			}

			sb.append('#').append(tc+1).append(' ').append(solve()).append('\n');
		}
		System.out.println(sb);
	}

	private static int solve() {
		Arrays.sort(ingredients, ((o1, o2) -> Integer.compare(o2[1], o1[1])));
		Arrays.fill(dp, 0);
		for (int i = 0; i < N; i++) {
			for (int cal = L; cal > 0; cal--) {
				int newCal = cal - ingredients[i][1];
				if (newCal <= 0) break;

				dp[cal] = Math.max(dp[newCal] + ingredients[i][0], dp[cal]);
			}
		}
		return dp[L];
	}
}
