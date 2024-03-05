package Baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
/**
 * @author 윤성하
 * @date 2024-02-06
 * @link https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AV141176AIwCFAYD&solveclubId=AY0LFFoqrIIDFAXz&problemBoxTitle=0205%EC%A3%BC&problemBoxCnt=2&probBoxId=AY13IwlKMEcDFAWX
 * @keyword_solution
 * 	트리의 형태는 완전 이진 트리, 왼쪽 자식 노드의 번호 = 부모 * 2, 오른쪽 = 부모 * 2 + 1
 * 	임의의 정점에 연산자가 있으면, 왼쪽 서브트리 결과와 오른쪽 서브트리 결과에 연산자 적용
 * 	==> 부모노드가 연산자면, 자식노드는 2개 있으야 하며 자식노드는 계산 가능한 서브트리
 * 	==> 리프노드는 숫자, 나머지는 연산자
 * @input
 * @output
 * @time_complex O(N)
 * @perf
 */
public class S1233 {
	static int N;
	static int[] tree = new int[402];

	public static void main(String[] args) throws IOException {
		StringBuilder sb = new StringBuilder();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int tc = 0; tc < 10; tc++) {
			Arrays.fill(tree, 0);
			N = Integer.parseInt(br.readLine());

			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int nodeNum = Integer.parseInt(st.nextToken());

				String s = st.nextToken();
				int nodeData = Character.isDigit(s.charAt(0)) ? Integer.parseInt(s) : -s.charAt(0);

				tree[nodeNum] = nodeData;
			}

			int ans = solve();
			sb.append('#').append(tc+1).append(' ').append(ans).append('\n');
		}

		System.out.println(sb);
	}

	static int solve() {
		if (N % 2 == 0) return 0;

		for (int i = 1; i <= N; i++) {
			if (tree[i] < 0) { // 연산자
				if (tree[i*2] == 0 || tree[i*2+1] == 0) return 0; // 자식 노드가 2개 미만
			} else { // 숫자
				if (tree[i*2] != 0 || tree[i*2+1] != 0) return 0; // 자식 노드가 존재
			}
		}

		return 1;
	}
}
