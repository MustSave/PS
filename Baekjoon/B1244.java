package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
/**
 * @author mustsave
 * @date 2024-01-30
 * @link https://www.acmicpc.net/problem/1244
 * @keyword_solution
 * 	남학생의 경우 숫자 배수의 스위치 토글
 * 	여학생의 경우 숫자를 기준으로 좌우 대칭인 범위 전부 토글
 * @input
 * 	남학생의 경우 숫자의 배수로 계산하기에 스위치 입력을 1부터 시작
 * @output 20번째마다 개행하기
 * @time_complex O(NM) N: #student, M: #switch
 * @perf
 */
public class B1244 {
	static int numSwitch;
	static long[] switches = {0, 0};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		numSwitch = Integer.parseInt(br.readLine());
		int m = Math.min(numSwitch, 63);

		String sw = br.readLine();
		for (int i = 1; i <= m; i++) {
			if (sw.charAt((i-1) << 1) == '0') continue;
			switches[0] |= (1L << i);
		}
		for (int i = 64; i <= numSwitch; i++) {
			if (sw.charAt((i-1) << 1) == '0') continue;
			switches[1] |= (1L << (i^64));
		}

		int numStudent = Integer.parseInt(br.readLine());
		for (int i = 0; i < numStudent; i++) {
			String st = br.readLine();
			int switchNum = Integer.parseInt(st, 2, st.length(), 10);
			if (st.charAt(0) == '1') {
				m(switchNum);
			} else {
				w(switchNum);
			}
		}

		print();
	}

	private static void print() {
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= numSwitch; i++) {
			sb.append(testBit(i) ? 1 : 0);
			if (i % 20 == 0) {
				if (i != numSwitch) {
					sb.append('\n');
				}
			} else {
				sb.append(' ');
			}
		}
		System.out.println(sb);
	}

	private static void m(int switchNum) {
		for (int i = 1; switchNum*i <= numSwitch; i++) {
			flip(switchNum*i);
		}
	}

	private static void w(int switchNum) {
		int l = switchNum - 1;
		int r = switchNum + 1;

		flip(switchNum);
		while (l > 0 && r <= numSwitch && (testBit(l) == testBit(r))) {
			flip(l--);
			flip(r++);
		}
	}

	private static boolean testBit(int switchNum) {
		if ((switchNum & 64) == 0) {
			return (switches[0] & (1L << switchNum)) != 0;
		}
		return (switches[1] & (1L << (switchNum ^ 64))) != 0;
	}

	private static void flip(int switchNum) {
		if ((switchNum & 64) == 0) {
			switches[0] ^= 1L << switchNum;
		} else {
			switches[1] ^= 1L << (switchNum ^ 64);
		}
		// switches[switchNum/64] ^= (1L << (switchNum % 64));
	}
}