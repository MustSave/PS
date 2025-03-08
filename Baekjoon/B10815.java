package Baekjoon;

import java.util.BitSet;

public class B10815 {
    public static void main(String[] args) throws Exception {
        Reader reader = new Reader();
        StringBuilder sb = new StringBuilder();
        BitSet bitSet = new BitSet(20000009);

        int N = reader.nextInt();
        for (int i = 0; i < N; i++) {
            bitSet.set(reader.nextInt() + 10000000);
        }

        N = reader.nextInt();
        for (int i = 0; i < N; i++) {
            sb.append(bitSet.get(reader.nextInt() + 10000000) ? 1 : 0).append(' ');
        }

        System.out.print(sb);
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
