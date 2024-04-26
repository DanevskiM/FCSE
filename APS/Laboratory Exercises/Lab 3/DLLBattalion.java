package lab03;

import java.util.Scanner;

public class DLLBattalion {
    //TODO: implement function
    public static void battalion(DLL<Integer> list, int a, int b) {
        DLLNode<Integer> current = null;
        DLLNode<Integer> last = null;
        current = list.find(a);
        last = list.find(b);
        while (current!=last){
            int  swap = current.element;
            current.element = last.element;;
            last.element = swap;
            current = current.succ;
            if (current==last)
                break;
            last = last.pred;
        }
    }

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        DLL<Integer> list = new DLL<>();
        for (int i = 0; i < n; i++) {
            list.insertLast(input.nextInt());
        }

        int a = input.nextInt();
        int b = input.nextInt();

        battalion(list, a, b);

        System.out.println(list);
        System.out.println(list.toStringR());


    }
}
