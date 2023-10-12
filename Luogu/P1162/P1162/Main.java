import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = 1;
        while (t-- > 0)
            new Solve(scanner);
        scanner.close();
    }
}

class Solve {
    int[][] matrix;
    boolean[][] vis;

    public Solve(Scanner scanner) {
        int n = scanner.nextInt();
        matrix = new int[n + 1][n + 1];
        vis = new boolean[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }
    }

    int dfs(int x, int y) {
        return 0;
    }
}