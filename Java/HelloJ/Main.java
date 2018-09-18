import java.io.UnsupportedEncodingException;

class freshJuice{
    enum FreshJuiceSize{SMALL,MEDIUM,LARGE}
    FreshJuiceSize size;
}
public class Main {
    public static void main(String[] args) throws UnsupportedEncodingException {
        String s1 = "你好";
        String s2 = new String(s1.getBytes("GB2312"), "ISO-8859-1");
        //new echoServer();
        //test.RegExpTest();
        int arr[] = {3, 4, 1, 4, 13, 4, 6, 7, 8, 6, 9};
        MySort.mergeSort(arr);
        //Tool.getPrimitiveType();
//        tool.quickSort(arr);
        for (int a : arr) {
            System.out.println(a);
        }
//        String s1 = new StringBuilder("go")
//                .append("od").toString();
//        System.out.println(s1.intern() == s1);
//        System.out.println(s1=="good    ");
//
//        String s2 = new StringBuilder("go")
//                .append("od").toString();
//     //   System.out.println(s2);
//     //   System.out.println(s2.intern());
//        System.out.println(s2.intern() == s2);

//        String s1 = "hello";
//        String s2 = new String("hello");
//        System.out.println(s1==s2);
//        System.out.println(s2==s2.intern());
//        s2=s2.intern();
//        System.out.println(s2==s1);
//        String t = s1;
//        System.out.println(t==s1);\
//        String str2 = "SEUCalvin";//新加的一行代码，其余不变
//        String str1 = new String("SEU")+ new String("Calvin");
//        System.out.println(str1.intern() == str1);
//        System.out.println(str1 == "SEUCalvin");
//        System.out.println(str1.intern()==str2);
        }
}

