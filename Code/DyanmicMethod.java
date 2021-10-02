
class phone{
    public void ShowTime(){
        System.out.println("It's 8:11 am");
    }
    public void on(){
        System.out.println("Turning on Phone......");
    }
}
class Smartphone extends phone{
    public void on(){
        System.out.println("Turning on SmartPhone....");
    }
    public void ring(){
        System.out.println("Ringing.....");
    }
}
public class DyanmicMethod  {
    public static void main(String[] args) {
//        Smartphone m40 = new phone();  ----> It's Not allowed here
        phone m30 = new Smartphone();  // It's Allowed
        m30.on();
        m30.ShowTime();
//        m30.ring();  --> not allowed
    }
}
