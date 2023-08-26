import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int t = sc.nextInt();
        while((t--) > 0){
            Main m = new Main();
            m.solve();
        }
    }
    void solve() {
        int a, b;
        a = sc.nextInt();
        b = sc.nextInt();
        int m = Math.max(a, b), n = Math.min(a, b);
        if (m == 1 && n == 1) {
            System.out.println(0);
        }else if (n == 1) {
            System.out.println(m);
        }else {
            System.out.println(2 * (n - 1) + m);
        }
    }
}
