//
// Created by hiking on 2017/3/3.
//

#include <jni.h>
#include <stdlib.h>

int doRand(){
    return rand();
}
JNIEXPORT jint JNICALL
Java_hiking_com_jnidemo01_JNIUtils_intmethod (
        JNIEnv *env,
        jobject jobject1/* this */) {

    return doRand();
}

JNIEXPORT void JNICALL
Java_hiking_com_jnidemo01_JNIUtils_callbackAdd (
                JNIEnv *env,
                jobject jobj/* this */) {



    //1、得到字节码 FindClass(env,类的全路径);
    jclass class = (*env)->FindClass(env, "hiking/com/jnidemo01/JNIUtils");
    //2、得到方法 GetMethodID(env,jclass,方法名,方法签名);
    //方法签名是要调用的方法名对应的签名
    jmethodID methodID = (*env)->GetMethodID(env, class, "add", "(II)I");
    //3、实例化该类
    jobject obj = (*env)->AllocObject(env, class);
    //4.调用Java类中的方法
    //成功调用add方法;第二三个参数是我们调用add方法传入的参数。value就是add方法的返回值
    jint value = (*env)->CallIntMethod(env, obj, methodID, 145, 23);
}