import java.util.Scanner;

public class Main {
    int[][] matrix;
    boolean[][] vis;
    static Scanner scanner;

    public static void main(String[] args) {
        scanner = new Scanner(System.in);
        int t = 1;
        while (t-- > 0)
            solve();
        scanner.close();
    }

    void solve() {
        int n = scanner.nextInt();
        matrix = new int[n + 1][n + 1];
        vis = new boolean[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
    }
}