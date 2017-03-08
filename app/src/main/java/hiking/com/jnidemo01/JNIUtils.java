package hiking.com.jnidemo01;

import android.util.Log;

/**
 * Created by hiking on 2017/3/3.
 */

public   class JNIUtils {
    static {
        System.loadLibrary("hello_lib");
    }
    /**
     * 当执行这个函数的时候，让C代码调用add(int a, int b)
     */
    public static native void callbackAdd();

    /**
     * 这个函数让C调用
     */
    public int add(int a, int b) {
        Log.d("TAG", "我是add函数被C调用了a = " + a + ";b = " + b);
        return a + b;
    }
    public static native int intmethod();
}
