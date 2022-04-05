import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        StringBuilder sb=new StringBuilder();
        int testCase=sc.nextInt();
        for(int i=0; i<testCase; i++){
            int start=sc.nextInt(), end=sc.nextInt();
            int distance=end-start;

            int max=(int)Math.sqrt(distance);
            if(max==Math.sqrt(distance))
                sb.append(2*max-1+"\n");
            else if(distance<=max*max+max)
                sb.append(2*max+"\n");
            else
                sb.append(2*max+1+"\n");
        }
        System.out.println(sb);
        sc.close();
    }
}
