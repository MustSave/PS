package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Map;

public class B17136 {
	static boolean visited[][] = new boolean[10][10];
	static int[][] board = new int[10][10];
	static int[][] boardBackup = new int[10][10];
	static int[] squares = {0, 5, 5, 5, 5, 5};
	static int[] squaresBackup = new int[6];
	static int countOne;
	static int answer;
	static int maxDepth;

	static int[][] dirs = {
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}
	};

	static int[][] squareCheckDirs = {
		{1, 1},
		{1, -1},
		{-1, 1},
		{-1, -1}
	};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int i = 0; i < 10; i++) {
			String input = br.readLine();
			for (int j = 0; j < 10; j++) {
				board[i][j] = input.charAt(j<<1) - '0';
				if (board[i][j] == 1) countOne++;
			}
		}

		solve();
		System.out.println(answer);
	}

	private static void solve() {
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				if (board[x][y] == 0 || visited[x][y]) continue;

				maxDepth = 0;
				int dfsResult = dfs(0, x, y, Arrays.copyOf(squares, squares.length));
				if (dfsResult == -1) {
					answer = -1;
					return;
				}
				System.out.println("DFS "+x+", "+y+" = "+dfsResult);
				answer += dfsResult;
			}
		}
	}

	private static int dfs(int depth, int x, int y, int[] squareArr) {
		maxDepth = Math.max(maxDepth, depth);
		if (x == 3 && y == 4) {
			System.out.println();
		}
		// 종료조건...?
		int ans = Integer.MAX_VALUE;
		visited[x][y] = true;

		if (board[x][y] != 1) {
			int result = coreLogic(depth, x, y, squareArr, 0);
			if (result != -1) {
				visited[x][y] = false; //
				return result;
			}
		} else {
			int answer = Integer.MAX_VALUE;
			for (int n = 5; n > 0; n--) {
				if (squareArr[n] == 0) continue;
				boolean revert[] = new boolean[6];
				int d = 0;
				int sum = 0;

				for (; d < 4; d++) {
					if (n == 1 && d > 0) continue;
					int dx = squareCheckDirs[d][0], dy = squareCheckDirs[d][1];

					if (!checkSquare(x, y, n, dx, dy)) continue;

					revert[n] = true;
					fillSquare(x, y, n, n+1, dx, dy);
					squareArr[n]--;

					int result = coreLogic(depth, x, y, squareArr, 1);

					fillSquare(x, y, n, 1, dx, dy);
					squareArr[n]++;
				}

				for (d -= 1; d >= 0; d--) {
					if (!revert[d]) continue;
					int dx = squareCheckDirs[d][0], dy = squareCheckDirs[d][1];
				}
			}
		}

		visited[x][y] = false;
		return -1;
	}

	static void printer(Object ...obj) {
		StringBuilder sb = new StringBuilder();
		for (Object o: obj) {
			sb.append(o).append(' ');
		}
		System.out.println(sb);
	}

	private static int coreLogic(int depth, int x, int y, int[] squareArr, int r) {
		int ret = r;
		for (int[] dir: dirs) {
			int nx = x + dir[0], ny = y + dir[1];
			if (!doDfs(nx, ny)) continue;

			int dfsResult = dfs(depth+1, nx, ny, squareArr);
			if (dfsResult == -1) {
				ret = -1;
				break;
			}
			ret += dfsResult;
		}
		return ret;
	}

	static int sumSquares(int[] squares) {
		int n = 0;
		for (int i = 1; i < 6; i++) {
			n += squares[i];
		}
		return n;
	}

	private static boolean doDfs(int x, int y) {
		if (x < 0 || y < 0 || x >= 10 || y >= 10 || board[x][y] == 0) return false;
		if (visited[x][y]) return false;
		return true;
	}

	static void backup(int[] sq) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				boardBackup[i][j] = board[i][j];
			}
		}

		for (int i = 0; i < 6; i++) {
			squaresBackup[i] = sq[i];
		}
	}

	static void restore() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				board[i][j] = boardBackup[i][j];
			}
		}

		for (int i = 0; i < 6; i++) {
			squares[i] = squaresBackup[i];
		}
	}

	private static boolean checkSquare(int x, int y, int n, int dx, int dy) {
		if (squares[n] == 0) return false;
		for (int i = 0; i < n; i++) {
			int nx = x + i * dx;
			for (int j = 0; j < n; j++) {
				int ny = y + j * dy;
				if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10) return false;
				if (board[nx][ny] != 1) return false;
				// if (nx != x && ny != y && visited[nx][ny]) return false;
			}
		}
		return true;
	}

	private static void fillSquare(int x, int y, int n, int val, int dx, int dy) {
		if (val == 1) {
			System.out.printf("Revert Square %d, %d with size %d, dx=%d, dy=%d\n", x, y, n, dx, dy);
		} else {
			System.out.printf("Fill Square %d, %d with size %d, val %d, dx=%d, dy=%d\n", x, y, n, val, dx, dy);
		}
		for (int i = 0; i < n; i++) {
			int nx = x + i * dx;
			for (int j = 0; j < n; j++) {
				int ny = y + j * dy;
				board[nx][ny] = val;
			}
		}
		// print();
	}

	static void print() {
		System.out.println("****************************************************");
		for (int[] a: board) {
			System.out.println(Arrays.toString(a));
		}
		System.out.println("****************************************************");
	}

	//	private static void fillSquare(int x, int y, int n, int val) {
	//		if (val == 1) {
	//			System.out.printf("Revert Square %d, %d with size %d\n", x, y, n);
	//		} else {
	//			System.out.printf("Fill Square %d, %d with size %d, val %d\n", x, y, n, val);
	//		}
	//		for (int nx = x; nx < x + n; nx++) {
	//			for (int ny = y; ny < y + n; ny++) {
	//				board[nx][ny] = val;
	//			}
	//		}
	//	}
}