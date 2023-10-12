import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = sc.nextInt();
        String a = sc.next(), b = sc.next();
        int[] f = new int[n];
        for (int i = 0; i < n; i++) {
            if (a.charAt(i) == b.charAt(i)) {
                f[i] = 0;
            } else if (a.charAt(i) < b.charAt(i)) {
                f[i] = 1;
            } else {
                f[i] = -1;
            }
        }
        long num = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (f[i] == -1) {
                num = 0;
            }
            if (f[i] == 1) {
                num++;
                ans += num * (n - i);
                num = 0;
            }
            if (f[i] == 0) {
                num++;
            }
        }
        System.out.println(ans);
    }
}
