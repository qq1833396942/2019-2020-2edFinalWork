import java.util.Scanner;

public class question2 {
    static int p = 5;
    static int r = 3;

    public static boolean com(int[] m,int[] n){
        for(int i=0;i<m.length;i++){
            if(m[i]<n[i])
                return false;
        }
        return true;
    }

    public static boolean IsSafe(int allo[][],int need[][],int ava[]){
        boolean[] finish = new boolean[p];
        for(int i=0;i<p;i++)
            finish[i] = false;
        for(int i=0;i<p;i++){
            if(finish[i])
                finish[i]=false;
            else {
                int[] temp = new int[r];
                for(int j = 0;j<r;j++)
                    temp[j] = need[i][j];
                if(com(ava,temp)){
                    finish[i] = true;
                    int a = i+1;
                    System.out.println("第"+ a +"个进程安全");
                    for(int k = 0;k<3;k++)
                        ava[k]+=allo[i][k];
                }
            }
        }
        for(int i=0;i<p;i++){
            if(!finish[i]){
                int a = i+1;
                System.out.println("第"+ a +"个进程不安全");
                return false;
            }
        }
        return true;
    }

    public static void Apply(int allo[][], int need[][], int ava[], int req[], int n){
        n=n-1;
        int[] temp = new int[r];
        for(int i=0;i<r;i++)
            temp[i] = need[n][i];
        if(!com(temp,req)){
            System.out.println("请求违法");
            return;
        }
        else if(!com(ava,req)){
            System.out.println("发生阻塞");
            return;
        }
        else {
            for(int j=0;j<r;j++){
                allo[n][j] = allo[n][j] + req[j];
                need[n][j] = need[n][j] - req[j];
                ava[j] = ava[j] - req[j];
            }
            if (IsSafe(allo, need, ava)){
                int a = n+1;
                System.out.println("同意"+a+"个进程申请资源");
            }
            else {
                int a=n+1;
                System.out.println("不同意"+a+"个进程申请资源");
                System.out.println("恢复之前的状态");
                for (int j = 0; j < r; j++)
                {
                    allo[n][j] = allo[n][j] - req[j];
                    need[n][j] = need[n][j] + req[j];
                    ava[j] = ava[j] + req[j];
                }
            }
        }
    }

    public static void main(String[] args) {
        int[][] allo = new int[p][r];
        int[][] need = new int[p][r];
        int[] ava = new int[r];
        int[] req= new int[r]; int n;
        Scanner sc = new Scanner(System.in);

        System.out.println(" 输入每个进程已分配的资源数据");
        for(int i=0;i<p;i++)
            for(int j=0;j<r;j++)
                allo[i][j] = sc.nextInt();
        System.out.println(" 输入每个进程还需要的资源数据");
        for (int i = 0; i < p; i++)
            for (int j = 0; j < r; j++)
                need[i][j] = sc.nextInt();
        System.out.println("输入可用的资源数据");
        for (int j = 0; j < r; j++)
            ava[j] = sc.nextInt();

        if (IsSafe(allo, need, ava))
            System.out.println("初始状态安全");
        else
            System.out.println("初始状态不安全");
        while (true){
            System.out.println("输入申请的资源");
            for (int i = 0; i < r; i++)
                req[i] = sc.nextInt();
            System.out.println("第n个进程申请资源——n的值");
            n=sc.nextInt();
            Apply(allo,need,ava,req,n);
        }
    }
}

//2 1 2
//4 0 2
//3 0 5
//2 0 4
//3 1 4

//3 4 7
//1 3 4
//0 0 3
//2 2 1
//1 1 0

//2 3 3