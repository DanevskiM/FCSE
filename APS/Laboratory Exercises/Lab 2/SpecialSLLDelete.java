package lab02;

import java.util.Scanner;

public class SpecialSLLDelete<E> {
    public void specialDelete(SLL<E> list, int m) {
        SLLNode<E> current = list.getFirst();
        SLLNode<E> nareden = current.succ;
        while (current != null) {
            for (int i = 1; i < m && current != null; i++) {
                current = current.succ;
                nareden = nareden.succ;
                if (nareden==null)
                    return;
            }
            if (current == null)
                return;
            list.delete(current);
            current=nareden;
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        SLL<Integer> list = new SLL<>();
        for (int i = 0; i < n; i++) {
            list.insertLast(input.nextInt());
        }

        int m = input.nextInt();

        SpecialSLLDelete<Integer> tmp = new SpecialSLLDelete<>();

        tmp.specialDelete(list, m);

        System.out.println(list);
    }
}
