import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int [] arr = new int[n];

        for(int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }

        int m = in.nextInt(), p = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] > m) {
                p++;
            }
        }

        System.out.println(p + 1);
    }
}