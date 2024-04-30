package lab07;

import java.io.BufferedReader;
import java.util.Hashtable;
import java.io.IOException;
import java.io.InputStreamReader;


public class Lozinki {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Hashtable<String, String> hashtable = new Hashtable<>();
        for (int i = 1; i <= n; i++) {
            String user = br.readLine();
            String[] array = user.split(" ");
            hashtable.put(array[0], array[1]);
        }
        while (true) {
            String line = br.readLine();
            if (line.equals("KRAJ")) break;
            String[] data = line.split(" ");
            if (hashtable.containsKey(data[0]) && hashtable.get(data[0]).equals(data[1])) {
                System.out.println("Najaven");
                break;
            }
            System.out.println("Nenajaven");
        }
    }
}