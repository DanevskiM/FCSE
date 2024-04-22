//package lab01;
/*
За потребите на софтвер за евиденција на приходите остварени од вработените во одделот за продажба, да се дефинира класа QuarterlySales во која се чуваат бројот на продажби остварени во одреден квартал, приходот добиен од секоја продажба и бројот на кварталот.

Потоа, да се дефинира друга класа SalesPerson за кој се чува име (string) и низа од квартали (точно 4). За класите да се имплементираат соодветните конструктори и методи за правилно извршување на програмата. Да се имплементираат следните барања:

• Метод int sumSales(SalesPerson sp) кој ќе врати сума од сите приходи остварени од дадениот вработен во одделот за продажба во сите квартали.

• Метод SalesPerson salesChampion(SalesPerson [] arr) кој за дадената низа од работници ќе го врати работникот со најголем остварен приход (од сите квартали).

• Да се дополни main методот во кој ќе се иницијализира низа од вработени во одделот за продажба и квартали согласно влезните тест примери. Во првиот ред се чита број на вработени, а понатаму прво во еден ред се чита името, па за секој квартал во еден ред бројот на продажби, и во следниот ред приходот добиен од секоја од тие продажби.

• На стандарден излез да се испечати низата од вработени во одделот за продажба со помош на методата void table(SalesPerson [] arr) која за низата од вработени ќе отпечати приказ во следниот формат (за простор при печатење се користат три празни места):
*/
import java.util.Scanner;

class QuarterlySales {
    private int numOfSales;
    private int[] revenues;
    private int quarterNo;

    public QuarterlySales(int numOfSales, int[] revenues, int quarterNo) {
        this.numOfSales = numOfSales;
        this.revenues = revenues;
        this.quarterNo = quarterNo;
    }

    public int getNumOfSales() {
        return numOfSales;
    }

    public int[] getRevenues() {
        return revenues;
    }

    public int getQuarterNo() {
        return quarterNo;
    }

    @Override
    public String toString() {
        return "Quarter " + quarterNo + ": " + numOfSales + " sales, " + "Revenues: " + java.util.Arrays.toString(revenues);
    }
}

class SalesPerson {
    private String name;
    private QuarterlySales[] quarters;

    public SalesPerson(String name, QuarterlySales[] quarters) {
        this.name = name;
        this.quarters = quarters;
    }

    public String getName() {
        return name;
    }

    public QuarterlySales[] getQuarters() {
        return quarters;
    }

    @Override
    public String toString() {
        return "Name: " + name;
    }
}

public class Main {
    public static int sumSales(SalesPerson sp) {
        int sum = 0;
        for (QuarterlySales quarter : sp.getQuarters()) {
            int[] revenues = quarter.getRevenues();
            for (int revenue : revenues) {
                sum += revenue;
            }
        }
        return sum;
    }


    public static SalesPerson salesChampion(SalesPerson[] arr) {
        SalesPerson champion = arr[0];
        int maxRevenue = sumSales(champion);

        for (SalesPerson sp : arr) {
            int revenue = sumSales(sp);
            if (revenue > maxRevenue) {
                maxRevenue = revenue;
                champion = sp;
            }
        }

        return champion;
    }

    public static void table(SalesPerson[] arr) {
        System.out.printf("%s   %s   %s   %s   %s   %s%n", "SP", "1", "2", "3", "4", "Total");
        for (SalesPerson sp : arr) {
            int totalSales = 0;
            int[] quarterlyTotal = new int[4];
            System.out.printf("%s   ", sp.getName());
            for (QuarterlySales quarter : sp.getQuarters()) {
                int sum = java.util.Arrays.stream(quarter.getRevenues()).sum();
                System.out.printf("%d   ", sum);
                totalSales += sum;
                quarterlyTotal[quarter.getQuarterNo() - 1] = sum;
            }
            System.out.printf("%d%n", totalSales);
        }
    }


    public static void main(String[] args) {
        int n;
        Scanner input = new Scanner(System.in);
        n = input.nextInt();
        SalesPerson[] arr = new SalesPerson[n];

        for (int i = 0; i < n; i++) {
            String name = input.next();
            QuarterlySales[] quarters = new QuarterlySales[4];

            for (int j = 0; j < 4; j++) {
                int numOfSales = input.nextInt();
                int[] revenues = new int[numOfSales];
                for (int k = 0; k < numOfSales; k++) {
                    revenues[k] = input.nextInt();
                }
                quarters[j] = new QuarterlySales(numOfSales, revenues, j + 1);
            }

            arr[i] = new SalesPerson(name, quarters);
        }
        table(arr);
        System.out.println();
        System.out.println("SALES CHAMPION: " + salesChampion(arr).getName());
    }
}
