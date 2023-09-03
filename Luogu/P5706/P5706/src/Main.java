import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		double t = scan.nextDouble();
		int n = scan.nextInt();
		System.out.printf("%.3f\n", t / n);
		System.out.println(2 * n);
		scan.close();
	}
}
