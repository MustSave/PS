package SWEA;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class S4012 {
	static int N;
	static int[][] synergy = new int[16][16];
	static int[] teamA = new int[8];
	static int[] teamB = new int[8];
	static boolean[] used = new boolean[16];
	static int ans = Integer.MAX_VALUE;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());

		for (int tc = 0; tc < T; tc++) {
			ans = Integer.MAX_VALUE;
			N = Integer.parseInt(br.readLine());
			for (int i = 0; i < N; i++) {
				Arrays.fill(synergy[i], 0);
				used[i] = false;
			}
			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					int n = Integer.parseInt(st.nextToken());
					synergy[i][j] += n;
					synergy[j][i] += n;
				}
			}

			teamA[0] = 0;
			used[0] = true;

			solve(1, 0, 1);
			sb.append('#').append(tc+1).append(' ').append(ans).append('\n');
		}
		System.out.println(sb);
	}

	private static void solve(int depthA, int depthB, int startIdx) {
		if (depthA == N/2) {
			for (int i = startIdx; i < N; i++) {
				teamB[depthB++] = i;
			}
			check();
			return;
		}

		for (int i = startIdx; i < N; i++) {
			if (!used[i-1]) {
				if (depthB >= N/2) break;
				teamB[depthB++] = i-1;
			}
			teamA[depthA] = i;
			used[i]= true;
			solve(depthA+1, depthB, i+1);
			used[i]= false;
		}
	}

	private static void check() {
		int synergyA = getTotalSynergy(teamA), synergyB = getTotalSynergy(teamB);
		ans = Math.min(ans, Math.abs(synergyA - synergyB));
	}

	static int getTotalSynergy(int[] team) {
		int n = N/2, sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i+1; j < n; j++) {
				sum += synergy[team[i]][team[j]];
			}
		}
		return sum;
	}
}

