import java.util.Scanner;

public class baekjoon2480 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt(), b=sc.nextInt(), c=sc.nextInt();
        if(a==b&&b==c)
            System.out.println(10000+a*1000);
        else if(a!=b&&b!=c&&c!=a)
            System.out.println((a>b?(a>c?a:c):(b>c?b:c))*100);
        else
            System.out.println(1000+(a==b?a:c)*100);
        sc.close();
    }
}
