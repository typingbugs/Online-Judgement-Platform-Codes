import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = sc.nextInt();
        n++;
        int[] hv = new int[n + 1], nd = new int[n + 1];
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            hv[i] = sc.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            nd[i] = sc.nextInt();
        }
        for (int i = n; i >= 1; i--) {
            int tmp = nd[i] - hv[i];
            if (tmp <= 0) {
                continue;
            }
            if (tmp % 2 == 1) {
                tmp++;
            }
            tmp /= 2;
            ans += tmp;
            nd[i - 1] += tmp;
        }
        if (nd[1] > hv[1]) {
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
    }
}
