import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Passenger implements Comparable<Passenger> {
    int time;
    boolean isBoarded;

    Passenger(int time, boolean isBoarded) {
        this.time = time;
        this.isBoarded = isBoarded;
    }

    @Override
    public int compareTo(Passenger o) {
        return Integer.compare(time, o.time);
    }
}

public class Main {
    public static boolean result(List<Passenger> list, int k) {
        list.sort(Passenger::compareTo);
        int curr = 0, max = 0;
        for(Passenger passenger : list) {
            curr = passenger.isBoarded ? curr + 1 : curr - 1;
            max = Math.max(curr, max);
            if(curr > k) return false;
        }
        return true;
    }

    public static int getTime(String time) {
        String [] split = time.split(":");
        return Integer.parseInt(split[0]) * 60 + Integer.parseInt(split[1]);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        int n = in.nextInt();
        ArrayList<Passenger> list = new ArrayList<>();
        in.nextLine();

        for(int i = 0; i < n; i++) {
            String [] line = in.nextLine().split(" ");
            list.add(new Passenger(getTime(line[0]), true));
            list.add(new Passenger(getTime(line[1]), false));
        }

        System.out.println(result(list, k));
    }
}