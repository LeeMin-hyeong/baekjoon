import java.util.Arrays;

class Solution {
    public long solution(int[][] land, int P, int Q) {
        long answer = 1_000_000_000L * 100 * 300 * 300;

        int n = land.length;
        int size = n * n;

        long[] heights = new long[size];
        int index = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                heights[index++] = land[i][j];
            }
        }

        Arrays.sort(heights);

        long[] prefixSum = new long[size];
        prefixSum[0] = heights[0];

        for (int i = 1; i < size; i++) {
            prefixSum[i] = prefixSum[i - 1] + heights[i];
        }

        long previous = -1;

        for (int i = 0; i < size; i++) {
            if (previous == heights[i]) {
                continue;
            }

            previous = heights[i];

            long addCount = 0;
            long removeCount = 0;

            for (int j = i - 1; j >= 0; j--) {
                if (heights[j] != heights[i]) {
                    addCount =
                        heights[i] * (j + 1L) - prefixSum[j];
                    break;
                }
            }

            for (int j = i + 1; j < size; j++) {
                if (heights[j] != heights[i]) {
                    removeCount =
                        prefixSum[size - 1]
                        - prefixSum[j - 1]
                        - heights[i] * (size - j);
                    break;
                }
            }

            long cost = addCount * P + removeCount * Q;
            answer = Math.min(answer, cost);
        }

        return answer;
    }
}