import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    int times = 0, valid = 0;
    double v, ans = 0, pro = 1, eps = 1e-8;
    double[] cmp = new double[3];

    public static void main(String[] args) {
        int t = sc.nextInt();
        while(t > 0) {
            Main m = new Main();
            m.Solve();
            t--;
        }
    }

    void Solve(){
        for(int i = 0; i < 3; i++){
            cmp[i] = sc.nextDouble();
            if(cmp[i] > eps){
                valid++;
            }
        }
        v = sc.nextDouble();
        for(int i = 0; i < 3; i++){
            if(cmp[i] > eps){
                dfs(i);
            }
        }
        System.out.printf("%.12f\n", ans);
    }

    void dfs(int cur){
        if(cur == 2){
            ans += (times + 1) * pro * cmp[cur];
            return;
        }else{
            times++;
            pro *= cmp[cur];
            double[] temp = { 0, 0, 0 };
            if (cmp[cur] - v > eps) {
                cmp[cur] += (temp[cur] = -v);
                for (int j = 0; j < 3; j++) {
                    if (cmp[j] >= eps && j != cur) {
                        cmp[j] += (temp[j] = v / (valid - 1));
                    }
                }
            }
            else {
                cmp[cur] += (temp[cur] = -cmp[cur]);
                for (int j = 0; j < 3; j++) {
                    if (cmp[j] >= eps && j != cur) {
                        cmp[j] += (temp[j] = -temp[cur] / (valid - 1));
                    }
                }
                valid--;
            }

            for (int i = 0; i < 3; i++) {
                if (cmp[i] > eps) {
                    dfs(i);
                }
            }

            for (int j = 0; j < 3; j++) {
                cmp[j] -= temp[j];
            }
            if (cmp[cur] - v < eps) {
                valid++;
            }
            pro /= cmp[cur];
        }
        times--;
    }
}