import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static Queue<Character> s = new LinkedList<>();
    static int[] nums = new int[51];
    static int i_n = 0;

    public static void main(String[] args) {

        String input = sc.next();
        boolean num_mode = true;
        for (int i = 0; i < input.length(); i++) {
            char now = input.charAt(i);
            if (now == '@') {
                calculate();
                break;
            } else if (now >= '0' && now <= '9') {
                if (!num_mode) {
                    calculate();
                    num_mode = true;
                }
                nums[i_n] = nums[i_n] * 10 + now - '0';
            } else if (now == '.') {
                i_n++;
            } else {
                num_mode = false;
                s.add(now);
            }
        }
        System.out.println(nums[0]);
    }
    static void calculate() {
        i_n--;
        while (i_n != 0 && !s.isEmpty()) {
            char sign = s.poll();
            if (sign == '+') {
                nums[i_n - 1] += nums[i_n];
                nums[i_n--] = 0;
            } else if (sign == '-') {
                nums[i_n - 1] -= nums[i_n];
                nums[i_n--] = 0;
            } else if (sign == '*') {
                nums[i_n - 1] *= nums[i_n];
                nums[i_n--] = 0;
            } else if (sign == '/') {
                nums[i_n - 1] /= nums[i_n];
                nums[i_n--] = 0;
            }
        }
        i_n++;
    }
}
