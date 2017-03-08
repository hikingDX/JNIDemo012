#include <jni.h>
#include <string>
#include "CCounter.h"
extern "C" {
JNIEXPORT jstring JNICALL
Java_hiking_com_jnidemo01_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {


    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT void JNICALL
Java_hiking_com_jnidemo01_CounterNative_nativeSetup(
        JNIEnv *env,
        jobject clazz,jint n) {
    CCounter * obj = new CCounter(n);
    jclass  objClazz = env->GetObjectClass(clazz);
    jfieldID  fid = (jfieldID)env->GetFieldID(objClazz,"mObject","J");
    env->SetLongField(clazz, fid, (jlong) obj);
}

JNIEXPORT jint JNICALL
Java_hiking_com_jnidemo01_CounterNative_nativeExec(
        JNIEnv *env,
        jclass clazz,jobject obj) {
//    jclass objClazz = env->GetObjectClass(obj);
//    jfieldID  fid = env->GetFieldID(objClazz,"mObject","J");
//    jlong p = (jlong) env->GetObjectField(obj, fid);
    CCounter * co = (CCounter *) obj;
    return (jint)co->execute();

}
}
