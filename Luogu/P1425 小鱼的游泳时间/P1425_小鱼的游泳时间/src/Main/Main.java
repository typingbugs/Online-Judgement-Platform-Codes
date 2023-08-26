package Main;
import java.util.Scanner;
public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int st_h = sc.nextInt(), st_min = sc.nextInt(), en_h = sc.nextInt(), en_min = sc.nextInt();
        int ans_h = (en_h - st_h + 24) % 24, ans_min = (en_min - st_min + 60) % 60;
        if(en_min < st_min)
            ans_h--;
        System.out.println(ans_h + " " + ans_min);
    }
}