import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = 1;
        while (t-- > 0) {
            new Solve(scanner);
        }
    }
}

class Solve {
    public Solve(Scanner scanner) {
        int n = scanner.nextInt();
        int[][] metrix = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                metrix[i][j] = scanner.nextInt();
            }
        }

    }
}