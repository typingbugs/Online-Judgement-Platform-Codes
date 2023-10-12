import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int[] dx = new int[]{ 0, -1, 0, 1 }, dy = new int[]{ 1, 0, -1, 0 };
    public static void main(String[] args) {
        int n = sc.nextInt();
        int[][] ans = new int[n][2];
        Map<Point, Integer> input = new HashMap<>();
        Set<Point> st = new HashSet<>(), points = new HashSet<>();
        for(int i = 0; i < n; i++) {
            int x = sc.nextInt(), y = sc.nextInt();
            input.put(new Point(x, y), i);
            points.add(new Point(x, y));
            for (int j = 0; j < 4; j++) {
                st.add(new Point(x + dx[j], y + dy[j]));
            }
        }
        Queue<Arr4> q = new ArrayDeque<>();
        for (Point iter : st) {
            if (!points.contains(iter)) {
                q.add(new Arr4(iter.x, iter.y, iter.x, iter.y));
            }
        }
        Arr4 arr4;
        Point p1 = new Point();
        while (!q.isEmpty()) {
            arr4 = q.poll();
            for (int i = 0; i < 4; i++) {
                p1.x = arr4.a + dx[i];
                p1.y = arr4.b + dy[i];
                if (points.contains(p1)) {
                    int pos = input.get(p1);
                    ans[pos][0] = arr4.c;
                    ans[pos][1] = arr4.d;
                    points.remove(p1);
                    q.add(new Arr4(p1.x, p1.y, arr4.c, arr4.d));
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.println(ans[i][0] + " " + ans[i][1]);
        }
    }
}
class Point {
    int x, y;
    Point() {

    }
    Point(int a, int b) {
        x = a;
        y = b;
    }
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point p = (Point) o;
        return this.x == p.x && this.y == p.y;
    }
    public int hashCode() {
        return Objects.hash(this.x, this.y);
    }
}

class Arr4{
    int a, b, c, d;
    Arr4(int a, int b, int c, int d) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }
}