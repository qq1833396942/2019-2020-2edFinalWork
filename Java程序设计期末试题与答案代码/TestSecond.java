//191181-20181001095-常文瀚
interface Shape{
    double area();
    double perimeter();
}

class square implements Shape{
    double a;
    public square(double a){
        this.a = a;
    }
    public double area(){
        return a*a;
    }
    public double perimeter(){
        return 4*a;
    }
}

class Rectangle implements Shape{
    double a;
    double b;
    public Rectangle(double a, double b) {
        this.a = a;
        this.b = b;
    }
    public double area() {
        return a*b;
    }
    public double perimeter() {
        return 2*(a+b);
    }
}

class CircleShape implements Shape {
    double r;
    //double p = Math.PI;
    public CircleShape(double r){
        this.r = r;
    }
    public double area(){
        return Math.PI*r*r;
    }
    public double perimeter(){
        return 2*Math.PI*r;
    }
}


public class TestSecond {
    public static void main(String[] args) {
        Shape num1 = new Rectangle(5,6);
        Shape num2 = new CircleShape(2);
        Shape num3 = new square(9);
        System.out.println("三角形面积："+num1.area());
        System.out.println("三角形周长："+num1.perimeter());
        System.out.println("圆形面积："+num2.area());
        System.out.println("圆形周长："+num2.perimeter());
        System.out.println("矩形面积："+num3.area());
        System.out.println("矩形周长："+num3.perimeter());
    }
}
