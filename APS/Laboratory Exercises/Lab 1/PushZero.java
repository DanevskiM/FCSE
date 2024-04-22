//За дадена низа од случајни броеви кои се внесуваат од стандарден влез, 
//да се направи преместување на сите нули на почеток на низата. На стандарден 
//излез да се испечати трансформираната низа.

package lab01;

import java.util.Scanner;

public class PushZero {
    static void pushZerosToBeginning(int arr[], int n) {
        int j = 0;
        int[] transformed = new int[n];
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                transformed[j] = 0;
                j++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                transformed[j] = arr[i];
                j++;
            }
        }
        System.out.println("Transformiranata niza e:");
        for (int i = 0; i < n; i++) {
            System.out.print(transformed[i] + " ");
        }
    }

    public static void main(String[] args) {
        int array[] = new int[100];
        int n;
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        for (int i = 0; i < n; i++) {
            array[i] = input.nextInt();
        }
        pushZerosToBeginning(array, n);
    }
}
