import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    double eps = 1.0E-8;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();
        while ((t--) > 0) {
            Main m = new Main();
            m.solve();
        }
    }

    Queue<Node> q = new LinkedList<>();
    double v, ans = 0;

    void bfs() {
        while (!this.q.isEmpty()) {
            Node now = this.q.poll();
            int cur = now.cur;
            if (cur == 2) {
                ans += (now.times + 1) * now.pro * now.cmp[2];
            } else {
                now.pro *= now.cmp[cur];
                if (now.cmp[cur] - this.v > eps) {
                    now.cmp[cur] -= this.v;
                    for (int i = 0; i < 3; i++) {
                        if (now.cmp[i] >= eps && i != cur) {
                            now.cmp[i] += this.v / (now.valid - 1);
                        }
                    }
                } else {
                    double temp;
                    now.cmp[cur] -= (temp = now.cmp[cur]);
                    for (int i = 0; i < 3; i++) {
                        if (now.cmp[i] >= eps && i != cur) {
                            now.cmp[i] += temp / (now.valid - 1);
                        }
                    }
                    now.valid--;
                }
                now.times++;
                for (int i = 0; i < 3; i++) {
                    if (now.cmp[i] > eps) {
                        Node node = new Node(i, now.times, now.valid, now.pro, now.cmp);
                        this.q.offer(node);
                    }
                }
            }
        }
    }

    void solve() {
        ans = 0;
        double[] cmp = new double[3];
        int valid = 0;
        for (int i = 0; i < 3; i++) {
            cmp[i] = sc.nextDouble();
            if (cmp[i] > 0) {
                valid++;
            }
        }
        this.v = sc.nextDouble();

        for (int i = 0; i < 3; i++) {
            Node node = new Node(i, valid, cmp);
            this.q.offer(node);
        }
        this.bfs();
        System.out.printf("%.12f\n", ans);
    }
}

class Node {
    Node(int cur, int times, int valid, double pro, double[] cmp) {
        this(cur, valid, cmp);
        this.times = times;
        this.pro = pro;
    }

    Node(int cur, int valid, double[] cmp) {
        this.cur = cur;
        this.times = 0;
        this.valid = valid;
        this.pro = 1;
        this.cmp = new double[3];
        for (int i = 0; i < 3; i++) {
            this.cmp[i] = cmp[i];
        }
    }

    int cur, times, valid;
    double pro;
    double[] cmp;
}