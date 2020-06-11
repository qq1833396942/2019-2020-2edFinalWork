/*
 * @Author: your name
 * @Date: 2020-06-07 02:28:29
 * @LastEditTime: 2020-06-07 02:29:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \新建文件夹\question1.java
 */ 
class Node{
    Node next;
    String name;
    int need;
    int turn;
    public Node(String name,int need,int turn){
        this.name = name;
        this.need = need;
        this.turn = turn;
        this.next = null;
    }
}

public class question1 {
    static int clock = 0,piecetime = 7,max=1000;

    public static void test(int clock,int piecetime){
        //设置数组和新建一些节点
        String[] name1 = {"p1","p2","p3","p4","p5"};
        String[] name2 = {"p6","p7","p8","p9","p10"};
        int[] need1 = {16,11,14,13,15};
        int[] wait1 = {6,5,4,3,2};
        int[] need2 = {21,18,10,7,14};
        int[] wait2 = {1,2,3,4,5};
        Node RQ1 = new Node(name1[0], need1[0], wait1[0]);
        Node RQ2 = new Node(name2[0], need2[0], wait2[0]);
        Node p,q,s=null,Finish = null;

        //轮转调度法 RoundRobin
        p = RQ1;
        for(int i = 1; i<5; i++){
            q = new Node(name1[i], need1[i], wait1[i]);
            //System.out.print(q.name+"-"+q.need+"-"+q.turn+"; ");
            p.next = q;
            p=p.next;
        }
        p = RQ1;
        while(p!=null){
            boolean flag = false;
            if(p.need!=0){
                q=p;
                while(q.next!=null){
                    q=q.next;   //q指针指向最后一个结点
                }
                if(p.need>piecetime){   //如果该节点表示的进程还需的时间大于一个时间片
                    clock += piecetime;
                    p.need -= piecetime;
                    //把刚运行了一个时间片的结点放到队列尾部
                    q.next = p;
                    p=p.next;
                    q.next.next = null;
                }
                else{
                    clock += p.need;
                    p.turn += clock;
                    p.need = 0;
                    if(s==null){
                        s=p;
                        Finish = s;
                        flag = true;    //Finish指针指向最后运行后的链表的第一个节点
                    }
                    else{
                        s.next = p;
                    }
                    if(flag==false){
                        s=s.next;
                    }
                }
            }
            else{
                p=p.next;
            }
        }
        RQ1 = Finish;

        //短进程优先调度，ShortestJobFirst
        p=RQ2;
        for(int i = 1; i<5; i++){
            q = new Node(name2[i], need2[i], wait2[i]);
            p.next = q;
            p=p.next;
        }

        for(int i=0; i<5; i++){
            q = RQ2;
            p = RQ2;
            //p.need = max;
            //p.next = null;
            while(q!=null){
                if(q.need!=0 && q.need<p.need)
                    p=q;
                q=q.next;
            }
            clock += p.need;
            p.turn += clock;
            p.need = max;
        }
        //输出结果
        System.out.println("轮转调度法：");
        for (int i = 0; i < 5;i++)
        {
            System.out.println(RQ1.name+"周转时间为："+RQ1.turn);
            RQ1= RQ1.next;
        }
        System.out.println("短进程优先调度：");
        for(int i=0;i<5;i++){
            System.out.println(RQ2.name+"周转时间为："+RQ2.turn);
            RQ2 = RQ2.next;
        }
    }


    public static void main(String[] args){

        test(clock,piecetime);
        //System.out.println("短进程优先调度法");
        //shorestJobFirst(clock,piecetime);
    }
}
