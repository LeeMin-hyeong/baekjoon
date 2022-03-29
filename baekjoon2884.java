import java.util.Scanner;

public class baekjoon2884 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int h=sc.nextInt(), m=sc.nextInt();
        if(m<45)
            System.out.println((h==0?23:(h-1))+" "+(m+60-45));
        else
            System.out.println(h+" "+(m-45));
        sc.close();
    }
}