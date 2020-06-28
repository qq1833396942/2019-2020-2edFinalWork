//191181-20181001095-常文瀚
import java.io.*;

public class TestFirst {
    public static void test(){
        String s1,s2="",s3="";
        char ch,ch1,ch2;
        int n,i1,i2,i,n1;
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);
        try{
            System.out.println("请输入原文");
            s1 = br.readLine();
            n = s1.length();
            for (i=0;i<n;i++){
                ch = s1.charAt(i);
                i1 = ch / 32;
                i2 = ch % 32;
                s2 = s2+(char)i1+(char)i2;
            }
            System.out.println("加密后文内容为");
            n = s2.length();
            for (i=0;i<n;i++){
                ch1 = s2.charAt(i);
                ch2 = s2.charAt(i+1);
                n1 = ch1*32+ch2;
                s3 = s3+(char)n1;
                i++;
            }
            System.out.println("解密后的原文："+s3);
        }
        catch (IOException e){
            e.printStackTrace();
        }

    }

    public static void main(String[] args) {
        test();
    }
}
