import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StudentRecord sr = new StudentRecord();

        for (int i = 0; i < sr.marks.length; i++) {
            sr.addMarks(i, sc.nextInt());
        }

        int index = sc.nextInt();
        sr.displayMarks(index);
        sc.close();
    }
}
