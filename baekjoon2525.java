import java.util.Scanner;

public class baekjoon2525 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int h=sc.nextInt(), m=sc.nextInt(), t=sc.nextInt();
        System.out.println((h+((m+t)/60))%24+" "+(m+t)%60);
        sc.close();
    }
}
