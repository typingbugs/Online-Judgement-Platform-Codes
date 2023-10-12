import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();
        while((t--) > 0) {
            Main m = new Main();
            m.solve();
        }
    }

    void solve() {
        long n = sc.nextLong(), k = sc.nextLong(), b = sc.nextLong(), s = sc.nextLong();
        if (n * (k - 1) + b * k < s || b * k > s) {
            System.out.println(-1);
        }else {
            System.out.print(Math.min(((b + 1) * k - 1), s) + " ");
            s -= (b + 1) * k - 1;
            for (int i = 0; i < n - 1; i++) {
                if (s <= 0) {
                    System.out.print(0 + " ");
                }else {
                    System.out.print(Math.min(k - 1, s) + " ");
                    s -= k - 1;
                }
            }
            System.out.println();
        }
    }
}