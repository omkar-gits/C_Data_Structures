public class test{
    static{
        System.loadLibrary("myclib");
    }

    public static void main(String arg[]){
        System.out.println("\ni am in Java\n");
        test obj = new test();

        obj.Display();
        obj.DisplayString("Hello from Java");
        obj.Add(Integer.parseInt(arg[0]) , Integer.parseInt(arg[1]));

        obj.CallMe();
        obj.CallMeString();
    }

    public native void Display();
    public native void Add(int iNo1 , int iNo2);
    public native void DisplayString(String str);

    public native void CallMe();
    public native void CallMeString();

    public static void DisplayJava(){
        System.out.println("This is reverse JNI \n");
    }

    public static void DisplayJavaString(String str){
        System.out.println(str);
    }

}