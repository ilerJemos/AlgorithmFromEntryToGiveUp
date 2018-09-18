import java.io.*;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;

public final class Tool {

    private Tool(){
        throw new AssertionError();
    }

    public static void quickSort(int[] arr){
        qsort(arr,0,arr.length-1);
    }
    private static void qsort(int[] arr,int low,int high){
        if(low<high){
            int pivot = partition (arr,low,high);
            qsort(arr,low,pivot-1);
            qsort(arr,pivot+1,high);
        }
    }
    private static int partition(int[] arr,int low,int high){
        int pivot =arr[low];
        while(low<high){
            while(low<high&&arr[high]>=pivot) high--;
            arr[low]=arr[high];
            while(low<high&&arr[low]<=pivot) low++;
            arr[high]=arr[low];
        }
        arr[low]=pivot;
        return low;
    }
    //获取基本数据类型的范围
    public static void getPrimitiveType(){
        //byte
        System.out.println("基本类型:byte 二进制位数："+Byte.SIZE);;
        System.out.println("包装类：java.lang.Byte");
        System.out.println("最小值：Byte.MIN_VALUE="+Byte.MIN_VALUE);
        System.out.println("最大值：Byte.MAX_VALUE="+Byte.MAX_VALUE);
        System.out.println();
        // int
        System.out.println("基本类型：int 二进制位数：" + Integer.SIZE);
        System.out.println("包装类：java.lang.Integer");
        System.out.println("最小值：Integer.MIN_VALUE=" + Integer.MIN_VALUE);
        System.out.println("最大值：Integer.MAX_VALUE=" + Integer.MAX_VALUE);
        System.out.println();

        // long
        System.out.println("基本类型：long 二进制位数：" + Long.SIZE);
        System.out.println("包装类：java.lang.Long");
        System.out.println("最小值：Long.MIN_VALUE=" + Long.MIN_VALUE);
        System.out.println("最大值：Long.MAX_VALUE=" + Long.MAX_VALUE);
        System.out.println();

        // float
        System.out.println("基本类型：float 二进制位数：" + Float.SIZE);
        System.out.println("包装类：java.lang.Float");
        System.out.println("最小值：Float.MIN_VALUE=" + Float.MIN_VALUE);
        System.out.println("最大值：Float.MAX_VALUE=" + Float.MAX_VALUE);
        System.out.println();

        // double
        System.out.println("基本类型：double 二进制位数：" + Double.SIZE);
        System.out.println("包装类：java.lang.Double");
        System.out.println("最小值：Double.MIN_VALUE=" + Double.MIN_VALUE);
        System.out.println("最大值：Double.MAX_VALUE=" + Double.MAX_VALUE);
        System.out.println();

        // char
        System.out.println("基本类型：char 二进制位数：" + Character.SIZE);
        System.out.println("包装类：java.lang.Character");
        // 以数值形式而不是字符形式将Character.MIN_VALUE输出到控制台
        System.out.println("最小值：Character.MIN_VALUE="
                + (int) Character.MIN_VALUE);
        // 以数值形式而不是字符形式将Character.MAX_VALUE输出到控制台
        System.out.println("最大值：Character.MAX_VALUE="
                + (int) Character.MAX_VALUE);
    }

    //使用递归实现字符串反转
    public static String reverse(String originStr){
        if (originStr==null||originStr.length()<=1){
            return originStr;
        }
        return reverse(originStr.substring(1))+originStr.charAt(0);
    }
    //
    //文件拷贝
    public static  void fileCopy(String source,String target) throws IOException {
        try(InputStream in = new FileInputStream(source)){
            try(OutputStream out = new FileOutputStream(target)){
                byte[] buffer = new byte[4096];
                int bytesToRead;
                while((bytesToRead=in.read(buffer))!=-1)
                    out.write(buffer,0,bytesToRead);
            }
        }

    }
    //另一种方法实现文件拷贝
    public static void fileCopyNIO(String source,String target) throws IOException{
        try(InputStream in = new FileInputStream(source)){
            try(OutputStream out = new FileOutputStream(target)){
                FileChannel inChannel = ((FileInputStream) in).getChannel();
                FileChannel outChannel = ((FileOutputStream) out).getChannel();
                ByteBuffer buffer = ByteBuffer.allocate(4096);
                while(inChannel.read(buffer)!=-1){
                    buffer.flip();
                    outChannel.write(buffer);
                    buffer.clear();
                }
            }
        }
    }

    /**
     * 统计给定文件中给定字符串的出现次数
     * @param  filename 文件名
     * @param word 字符串
     * @return 字符串在文件中出现的词素
     */
    public static int countWordInFile(String filename,String word){
        int counter = 0;
        try(FileReader fr = new FileReader(filename)){
            try(BufferedReader br = new BufferedReader(fr)){
                String line = null;
                while ((line = br.readLine())!=null){
                    int index = -1;
                    while ((index = line.indexOf(word))!=-1){//
                        counter++;
                        line =line.substring(index+word.length());
                    }
                }
            }
        }catch (Exception ex){
            ex.printStackTrace();
        }
        return counter;
    }

    //列出目录下的所有文件
    public static void listFiles(String s){
        File f = new File(s);
        for(File temp:f.listFiles()){
            if(temp.isFile()){
                System.out.println(temp.getName());
            }
        }
    }

    //通过反射获取和设置对象私有字段的值
    /**
     * @param target 目标对象
     * @param fieldName 字段名字
     * @return 字段值
     */
    public static Object getValue(Object target,String fieldName){
        Class<?> clazz  = target.getClass();
        String[] fs = fieldName.split("\\.");
        try{
            for(int i = 0;i<fs.length-1;i++){
                Field f = clazz.getDeclaredField(fs[i]);
                f.setAccessible(true);
                target=f.get(target);
                clazz = target.getClass();
            }
            Field f = clazz.getDeclaredField(fs[fs.length-1]);
            f.setAccessible(true);
            return f.get(target);
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
        return null;
    }
    /**
     * 通过反射给指定字段赋值
     * @param target 目标对象
     * @param fieldName 字段名称
     * @param value 值
     */
    public static void setValue(Object target,String fieldName,Object value){
        Class<? extends Object> clazz = target.getClass();
        String[] fs = fieldName.split("\\.");
        try{
            for (int i = 0;i<fs.length-1;i++){
                Field f = clazz.getDeclaredField(fs[i]);
                f.setAccessible(true);
                Object val = f.get(target);
                if(val==null){
                    Constructor<?> c = f.getType().getDeclaredConstructor();
                    c.setAccessible(true);
                    val = c.newInstance();
                    f.set(target,val);
                }
                target = val;
                clazz = target.getClass();
            }
            Field f = clazz.getDeclaredField(fs[fs.length-1]);
            f.setAccessible(true);
            f.set(target,value);
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        }
    }

}
