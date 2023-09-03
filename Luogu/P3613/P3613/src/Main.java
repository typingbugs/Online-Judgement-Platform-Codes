import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int n = sc.nextInt(), q = sc.nextInt();
        Map<Point, Integer> input = new HashMap<>();
        for (int iter = 0; iter < q; iter++) {
            int a = sc.nextInt(), i = sc.nextInt(), j = sc.nextInt();
            Point p = new Point(i, j);
            if (a == 1) {
                int k = sc.nextInt();
                input.put(p, k);
            } else {
                System.out.println(input.get(p));
            }
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
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Point p = (Point) obj;
        return this.x == p.x && this.y == p.y;
    }
    public int hashCode() {
        return Objects.hash(this.x, this.y);
    }
}