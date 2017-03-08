package hiking.com.jnidemo01;

/**
 * Created by hiking on 2017/3/7.
 */

public class CounterNative {
    private long mObject;
    static {
        System.loadLibrary("native-lib");
    }
    public CounterNative(int number){
        nativeSetup(number);
    }
    public int doint(){
       return nativeExec(mObject);
    }
    private native void nativeSetup(int n);
    public  native int nativeExec(long object);
}
