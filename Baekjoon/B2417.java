package Baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class B2417 {
    public static void main(String[] args) throws Exception {
        String s = new BufferedReader(new InputStreamReader(System.in)).readLine();
        long l = Long.parseLong(s);

        long left = 0;
        long right = (long)(Math.sqrt((1L << 63) - 1)) + 1;

        while (left < right) {
            long mid = (left + right) >>> 1L;

            if (mid * mid < l) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        System.out.print(right);
    }
}
