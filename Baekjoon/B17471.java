package Baekjoon;

import java.util.*;

/**
 * @author mustsave
 * @date 2024.02.22
 * @link  https://www.acmicpc.net/problem/17471
 * @keyword_solution
 * 메모리가 리셋된 상황 - 원래의 메모리로 되돌리기위한 회수 파악하기
 * 한 자리를 변경하면 맨 뒤까지 모두 바꿔버림
 *  - 그대로 처리하면 모든 자리에서 매번 배열 교체 - O(N^2)
 *  - 그냥 현재 변경하는 비트를 고정하고 이 값이랑만 비교하면 끝 - O(N)
 * @input
 * N제한이 50이어서 브루투포스로 처리 하기에 충분함
 * @output
 * 일반적인 swexpert 방식으로 출력
 * @time_complex
 * O(N)
 * @perf 메모리 100, 소요시간 1000ms
 */

public class B17471 {
	static int N;
	static int ans = Integer.MAX_VALUE;
	static int selector;
	static int[] memo;
	static City[] cities;

	static Queue<Integer> queue;
	static Map<Integer, City> cityMap = new HashMap<>();


	public static void main(String[] args) throws Exception {
		Reader reader = new Reader();
		N = reader.nextInt();
		cities = new City[N];
		selector = (1<<N) - 1;
		memo = new int[selector];
		queue = new ArrayDeque<>(selector);

		for (int i = 0; i < N; i++) {
			int population = reader.nextInt();
			cities[i] = new City(population);
			memo[1<<i] = population;
			cityMap.put(1<<i, cities[i]);
		}

		for (int i = 0; i < N; i++) {
			int numNeighbor = reader.nextInt();

			for (int j = 0; j < numNeighbor; j++) {
				int n = reader.nextInt() - 1;
				cities[i].add(n);
			}
		}

		solve();
		System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
	}

	private static void solve() {
		doBfs();

		int half = 1 << (N-1);
		for (int set = 1; set < half; set++) {
			int complement = getComplement(set);

			if (memo[set] > 0 && memo[complement] > 0) {
				int abs = Math.abs(memo[set] - memo[complement]);
				ans = Math.min(ans, abs);
			}
		}
	}

	private static void doBfs() {
		for (int i = 0; i < N; i++) {
			if (cities[i].neighbors != 0) queue.offer(1<<i);
		}

		while (!queue.isEmpty()) {
			int set = queue.poll();
			int complement = getComplement(set);

			for (int cityBit = findFirstNoneZeroBit(complement); cityBit != 0; complement ^= cityBit, cityBit = findFirstNoneZeroBit(complement)) {
				int newSet = set | cityBit;
				if (newSet == selector || memo[newSet] > 0) continue;

				City city = cityMap.get(cityBit);
				if (!city.canConnectTo(set)) continue;

				memo[newSet] = memo[set] + city.population;
				queue.offer(newSet);
			}
		}
	}

	static int findFirstNoneZeroBit(int n) {
		return  n & (-n);
	}
	
	static int getComplement(int n) {
		return ~n & selector;
	}

	static class City {
		int population;
		int neighbors;
		public City(int population) {
			this.population = population;
		}

		public void add(int n) {
			neighbors |= 1 << n;
		}

		public boolean canConnectTo(int set) {
			return (neighbors & set) != 0;
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