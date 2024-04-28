package lab05;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class OddEvenSort {
    static void sortAscending(int[] array, int n) {
        int temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    static void sortDescending(int[] array, int n) {
        int temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (array[j] < array[j + 1]) {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    static void oddEvenSort(int[] array, int n) {
        int[] even = new int[n];
        int[] odd = new int[n];
        int odd_count = 0;
        int even_count = 0;
        for (int i = 0; i < n; i++) {
            if ((array[i] & 1) == 0) {
                even[even_count++] = array[i];
            } else {
                odd[odd_count++] = array[i];
            }
        }
        sortAscending(odd, odd_count);
        sortDescending(even, even_count);
        for (int i = 0; i < odd_count; i++) {
            array[i] = odd[i];
        }
        int index = 0;
        for (int i = odd_count; i < n; i++) {
            array[i] = even[index++];
        }
    }

    public static void main(String[] args) throws IOException {
        int i;
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String s = stdin.readLine();
        int n = Integer.parseInt(s);

        s = stdin.readLine();
        String[] pom = s.split(" ");
        int[] a = new int[n];
        for (i = 0; i < n; i++)
            a[i] = Integer.parseInt(pom[i]);
        oddEvenSort(a, n);
        for (i = 0; i < n - 1; i++)
            System.out.print(a[i] + " ");
        System.out.print(a[i]);
    }
}