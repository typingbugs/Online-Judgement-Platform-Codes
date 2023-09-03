import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        int n = sc.nextInt(), m = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            q.add(i);
        }
        int cnt = 1;
        while (!q.isEmpty()) {
            int ans = q.poll();
            if (cnt % m == 0) {
                System.out.print(ans + " ");
                cnt = 0;
            } else {
                q.add(ans);
            }
            cnt++;
        }
    }
}
