import java.awt.*;
import java.awt.event.*;
import java.awt.event.WindowEvent;
import javax.swing.*;

public class TestThird extends Frame implements ActionListener{
    int size=20;
    Label labelTitle2,lb1,lb2,lb3,lb4,lbxx,labelBottom,labelBottom2,labelBottom_,labelBottom__;
    JLabel labelTitle1;
    TextField in1,in2,in3;
    Button btn;
    double d1,d2,d3;


    public TestThird(String title){
        super(title);
        labelBottom2=new Label();labelBottom_=new Label();labelBottom__=new Label();
        labelTitle1=new JLabel("一元二次方程求根器");
        labelTitle1.setFont(new Font("Serif",Font.PLAIN,size));
        labelTitle1.setHorizontalAlignment(SwingConstants.CENTER);
        labelTitle2=new Label("请在下面空白处分别填入相应x系数：");
        lb1=new Label("");
        lb2=new Label("X^2+");
        lb3=new Label("X+");
        lb4=new Label("=0");
        lbxx=new Label("消息");
        btn=new Button("开始求解");
        btn.addActionListener(this);
        in1=new TextField();in2=new TextField();in3=new TextField();
        labelBottom=new Label("方程根为:");
        setLayout(new GridBagLayout());
        GridBagConstraints gridBag=new GridBagConstraints();//设置布局方式为网格块布局
        gridBag.fill=GridBagConstraints.HORIZONTAL;//以水平填充方式布局
        gridBag.weightx=0;//行长不变
        gridBag.weighty=0;//列高不变
        //addToBag(labelTitle1,gridBag,1,0,1,1);//标题标签LabelTitle1
        addToBag(labelTitle2,gridBag,0,1,1,1);				 //标签LabelTitle2：请在下面空白处分别填入相应x系数：

        Panel p=new Panel();
        p.add(lb1);
        p.add(in1);
        p.add(lb2);
        p.add(in2);
        p.add(lb3);
        p.add(in3);
        p.add(lb4);
        addToBag(p,gridBag,0,2,20,1);
        addToBag(btn,gridBag,0,3,1,1);								 //按钮   ：  开始求解
        addToBag(lbxx,gridBag,0,5,1,1);								//标签lbxx（消息）
        addToBag(labelBottom,gridBag,0,7,23,1);				//标签labelBottom（方程的根为:）
        addToBag(labelBottom_,gridBag,0,8,30,1);
        addToBag(labelBottom__,gridBag,0,9,20,1);
        addToBag(labelBottom2,gridBag,0,11,20,1);			//标签labelBottom2（输出异常信息）

        addWindowListener(new WindowAdapter(){		//实现窗口关闭功能实现
                              public void windowClosing(WindowEvent e){
                                  System.exit(0);
                              }
                          }
        );
    }
    void addToBag(Component c,GridBagConstraints gbc,int x,int y,int w,int h){//编写部件约束对象
        gbc.gridx=x;
        gbc.gridy=y;
        gbc.gridheight=h;
        gbc.gridwidth=w;
        add(c,gbc);
    }

    public void actionPerformed(ActionEvent e){			//触发按钮所执行的事件
        try{
            labelBottom.setText("");
            labelBottom2.setText("");
            labelBottom_.setText("");
            labelBottom__.setText("");

            d1=Double.parseDouble(in1.getText());
            d2=Double.parseDouble(in2.getText());
            d3=Double.parseDouble(in3.getText());
            double y[]=root(d1,d2,d3);
            labelBottom.setText("方程("+d1+")x*x+("+d2+")x+("+d3+")=0的根为:");
            labelBottom_.setText("x1="+y[0]);
            labelBottom__.setText("x2="+y[1]);
        }
        catch(NumberFormatException a){
            String str;
            str=a.getMessage();
            labelBottom_.setText("格式不正确,错误信息:"+str);
        }
        catch(Exception ex){
            String str;
            str=ex.getMessage();
            //labelBottom2(ex);
            double dbsc=d2*d2-4*d1*d3;
            labelBottom_.setText("无解！b^2-4*a*c="+dbsc+"<0");
            labelBottom2.setText(str);
        }

    }

    public static void main(String args[]){
        TestThird fr=new TestThird("一元二次方程求解器");
        fr.setSize(500,300);			//设置窗口大小
        fr.setVisible(true);			//显示窗口
    }




    static double[]root(double a,double b,double c)throws IllegalArgumentException {
        double x[]=new double[2];
        if(a==0){
            throw new IllegalArgumentException ("a 不能为零。");
        }
        else{
            double disc=b*b-4*a*c;
            if(disc<0)
            {
                throw new IllegalArgumentException(" b^2-4*a*c值不能小于零.");}
            x[0]=(-b+Math.sqrt(disc))/(2*a);
            x[1]=(-b-Math.sqrt(disc))/(2*a);
            return x;
        }
    }
}



