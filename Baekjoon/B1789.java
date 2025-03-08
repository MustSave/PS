package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B1789 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long S = Long.parseLong(br.readLine());

        int left = 0, right = 100000;

        while (left < right) {
            int mid = (left + right) >>> 1;
            long sum = prefixSum(mid);

            if (sum <= S) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        System.out.println(right - 1);
    }

    static long prefixSum(long to) {
        return (to * (to + 1)) >>> 1;
    }
}
