package SWEA;

import java.util.Arrays;

class UserSolution {
	Team teams[] = new Team[5];
	byte teamOfSoldier[] = new byte[100001];
	public void init() {
		for (int i = 0; i < teams.length; i++) {
			if (teams[i] == null)
				teams[i] = new Team();
			else
				teams[i].init();
		}
	}

	public void hire(int mID, int mTeam, int mScore) {
		int quotient = mID/64;
		long bit = 1L << (mID%64);
		teams[mTeam-1].hire(quotient, bit, mScore);
		teamOfSoldier[mID] = (byte)(mTeam-1);
	}

	public void fire(int mID) {
		int quotient = mID/64;
		long bit = 1L << (mID%64);
		Team team = teams[teamOfSoldier[mID]];
		int scoreIndex = team.getScoreIndexIfSoldierExist(quotient, bit);
		team.fire(scoreIndex, quotient, bit);
	}

	public void updateSoldier(int mID, int mScore) {
		int quotient = mID/64;
		long bit = 1L << (mID%64);
		Team team = teams[teamOfSoldier[mID]];
		int scoreIndex = team.getScoreIndexIfSoldierExist(quotient, bit);
		team.updateSoldier(scoreIndex, quotient, bit, mScore);
	}

	public void updateTeam(int mTeam, int mChangeScore) {
		Team team = teams[mTeam-1];
		team.updateScore(mChangeScore);
	}

	public int bestSoldier(int mTeam) {
		return teams[mTeam-1].bestSoldier();
	}
}

class Team {
	static long[][] tmp = new long[5][1563];
	long[][] soldiersByScore = new long[5][1563];

	public void hire(int quotient, long bit, int mScore) {
		soldiersByScore[mScore-1][quotient] |= bit;
	}

	public void fire(int scoreIndex, int quotient, long bit) {
		soldiersByScore[scoreIndex][quotient] ^= bit;
	}

	public int getScoreIndexIfSoldierExist(int quotient, long bit) {
		for (int score = 0; score < soldiersByScore.length; score++) {
			if ((soldiersByScore[score][quotient] & bit) != 0) return score;
		}
		throw new RuntimeException();
	}

	public void updateSoldier(int scoreIndex, int quotient, long bit, int mScore) {
		fire(scoreIndex, quotient, bit);
		hire(quotient, bit, mScore);
	}

	public void updateScore(int mChangeScore) {
		store(soldiersByScore);
		init();

		for (int i = 0; i < soldiersByScore.length; i++) {
			int clamped = clampScore(i+mChangeScore);
			a(soldiersByScore[clamped], tmp[i]);
		}
	}

	private void store(long[][] arr) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = 0; j < arr[0].length; j++) {
				tmp[i][j] = arr[i][j];
			}
		}
	}

	private void a(long[] a, long[] b) {
		for (int i = 0; i < a.length; i++) {
			a[i] |= b[i];
		}
	}

	private int clampScore(int scoreIndex) {
		return Math.min(Math.max(scoreIndex, 0), 4);
	}

	public int bestSoldier() {
		for (int scoreIndex = soldiersByScore.length - 1; scoreIndex >= 0; scoreIndex--) {
			long[] soldiers = soldiersByScore[scoreIndex];
			for (int i = soldiers.length-1; i >= 0; i--) {
				if (soldiers[i] != 0) {
					return 64 * i + leftMostBitPosition(soldiers[i]);
				}
			}
		}
		throw new RuntimeException();
	}

	private int leftMostBitPosition(long n) {
		long l = 1L << 63;
		int position = 63;
		while ((n&l) == 0) {
			l >>= 1;
			position--;
		}
		return position;
	}

	public void init() {
		for (int i = 0; i < soldiersByScore.length; i++) {
			Arrays.fill(soldiersByScore[i], 0);
		}
	}
}
