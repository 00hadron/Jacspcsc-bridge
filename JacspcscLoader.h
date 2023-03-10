/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class JacspcscLoader */

#ifndef _Included_JacspcscLoader
#define _Included_JacspcscLoader
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     JacspcscLoader
 * Method:    SCardEstablishContext
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardEstablishContext
  (JNIEnv *, jobject, jint, jint, jint, jlongArray);

/*
 * Class:     JacspcscLoader
 * Method:    SCardReleaseContext
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardReleaseContext
  (JNIEnv *, jobject, jlong);

/*
 * Class:     JacspcscLoader
 * Method:    SCardListReaders
 * Signature: (II[BI)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardListReaders
  (JNIEnv *, jobject, jlong, jint, jbyteArray, jintArray);

/*
 * Class:     JacspcscLoader
 * Method:    SCardConnect
 * Signature: (I[BIIII)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardConnect
  (JNIEnv *, jobject, jlong, jbyteArray, jint, jint, jlongArray , jintArray);

/*
 * Class:     JacspcscLoader
 * Method:    SCardReconnect
 * Signature: (IIIII)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardReconnect
  (JNIEnv *, jobject, jint, jint, jint, jint, jint);

/*
 * Class:     JacspcscLoader
 * Method:    SCardDisconnect
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardDisconnect
  (JNIEnv *, jobject, jlong , jint);

/*
 * Class:     JacspcscLoader
 * Method:    SCardBeginTransaction
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardBeginTransaction
  (JNIEnv *, jobject, jint);

/*
 * Class:     JacspcscLoader
 * Method:    SCardEndTransaction
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardEndTransaction
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     JacspcscLoader
 * Method:    SCardState
 * Signature: (III[BI)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardState
  (JNIEnv *, jobject, jint, jint, jint, jbyteArray, jint);

/*
 * Class:     JacspcscLoader
 * Method:    SCardGetStatusChange
 * Signature: (III[BIIII[B)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardGetStatusChange
  (JNIEnv *, jobject, jint, jint, jint, jbyteArray, jint, jint, jint, jint, jbyteArray);

/*
 * Class:     JacspcscLoader
 * Method:    SCardStatus
 * Signature: (I[BIII[BI)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardStatus
  (JNIEnv *, jobject, jint, jbyteArray, jint, jint, jint, jbyteArray, jint);

/*
 * Class:     JacspcscLoader
 * Method:    SCardTransmit
 * Signature: (ILACSModule/SCARD_IO_REQUEST;[BILACSModule/SCARD_IO_REQUEST;[BI)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardTransmit
  (JNIEnv *, jobject, jint, jobject, jbyteArray, jint, jobject, jbyteArray, jint);

/*
 * Class:     JacspcscLoader
 * Method:    SCardControl
 * Signature: (II[BI[BII)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardControl
  (JNIEnv *, jobject, jlong , jint, jbyteArray, jint, jbyteArray, jint, jintArray);

#ifdef __cplusplus
}
#endif
#endif
