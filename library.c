#include "JacspcscLoader.h"
#include <winscard.h>
#include <stdio.h>

/*
 * Class:     JacspcscLoader
 * Method:    SCardEstablishContext
 * Signature: (IIII)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardEstablishContext(JNIEnv *env, jobject thisObject, jint dwscope, jint pvReserved1, jint pvReserved2, jlongArray phContext) {



    SCARDCONTEXT context = 0;
    LONG result = SCardEstablishContext(dwscope, (LPCVOID) pvReserved1, (LPCVOID) pvReserved2, &context);

    jboolean isCopy = JNI_FALSE;
    jlong * ptrPhContext = (*env)->GetLongArrayElements(env, phContext, &isCopy);
    jsize ptrPhContextSize = (*env)->GetArrayLength(env, phContext);
    if (ptrPhContextSize > 0) {
        *ptrPhContext = context;
    } else {
        jclass iaeClazz = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, iaeClazz, "phContext.length == 0");
    }
    (*env)->ReleaseLongArrayElements(env, phContext, ptrPhContext, 0);
    return result;
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardReleaseContext
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardReleaseContext(JNIEnv *env, jobject thisObject, jlong hContext) {
    return SCardReleaseContext(hContext);
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardListReaders
 * Signature: (II[BI)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardListReaders
        (JNIEnv *env, jobject thisObject, jlong hContext, jint mszGroups, jbyteArray mszReaders, jintArray pcchReaders) {
    char mszGroupsC = mszGroups;




    jboolean isCopy = JNI_FALSE;
    jbyte *ptrMszReaders = (*env)->GetByteArrayElements(env, mszReaders, &isCopy);
    jsize mszReadersSize = (*env)->GetArrayLength(env, mszReaders);

    LPSTR shadow_mszReaders = NULL;
    DWORD shadow_pcchReaders = SCARD_AUTOALLOCATE;
    LONG result = SCardListReaders(hContext, (LPCSTR) mszGroupsC, (LPSTR) &shadow_mszReaders, &shadow_pcchReaders);
    memcpy(ptrMszReaders, shadow_mszReaders, min(shadow_pcchReaders, mszReadersSize));
    SCardFreeMemory(hContext, shadow_mszReaders);

    (*env)->ReleaseByteArrayElements(env, mszReaders, ptrMszReaders, 0);

    jint *pcchReadersPtr = (*env)->GetIntArrayElements(env, pcchReaders, &isCopy);
    jsize pcchReadersSize = (*env)->GetArrayLength(env, pcchReaders);
    if (pcchReadersSize > 0) {
        *pcchReadersPtr = shadow_pcchReaders;
    } else {
        jclass iaeClazz = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, iaeClazz, "pcchReaders.length == 0");
    }
    (*env)->ReleaseIntArrayElements(env, pcchReaders, pcchReadersPtr, 0);
    return result;
}


/*
 * Class:     JacspcscLoader
 * Method:    SCardConnect
 * Signature: (I[BIIII)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardConnect
        (JNIEnv *env,
         jobject thisObject,
         jlong hContext,
         jbyteArray szReaders,
         jint dwShareMode,
         jint dwPreferredProtocols,
         jlongArray phCard,
         jintArray pdwActiveProtocols) {

    jsize phCardSize = (*env)->GetArrayLength(env, phCard);
    if (phCardSize == 0) {
        jclass iaeClazz = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, iaeClazz, "phCard.length == 0");
    }
    jsize pdwActiveProtocolsSize = (*env)->GetArrayLength(env, pdwActiveProtocols);
    if (pdwActiveProtocolsSize == 0) {
        jclass iaeClazz = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, iaeClazz, "pdwActiveProtocols.length == 0");
    }


    jboolean isCopy = FALSE;
    jbyte *szReadersC = (*env)->GetByteArrayElements(env, szReaders, &isCopy);
    SCARDHANDLE     hCardHandle;
    DWORD           dwAP;
    LONG result = SCardConnect(hContext, szReadersC, dwShareMode, dwPreferredProtocols, &hCardHandle, &dwAP);
    (*env)->ReleaseByteArrayElements(env, szReaders, szReadersC, JNI_ABORT);



    jlong *phCardC = (*env)->GetLongArrayElements(env, phCard, &isCopy);
    *phCardC = hCardHandle;
    (*env)->ReleaseLongArrayElements(env, phCard, phCardC, 0);

    jint *pdwActiveProtocolsC = (*env)->GetIntArrayElements(env, pdwActiveProtocols, &isCopy);
    *pdwActiveProtocolsC = dwAP;
    (*env)->ReleaseIntArrayElements(env, pdwActiveProtocols, pdwActiveProtocolsC, 0);


    return result;
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardReconnect
 * Signature: (IIIII)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardReconnect
        (JNIEnv *, jobject, jint, jint, jint, jint, jint) {
    return 0;
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardDisconnect
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardDisconnect
        (JNIEnv *env, jobject thisObject, jlong hCard, jint dwDisposition) {
   return SCardDisconnect(hCard, dwDisposition);
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardBeginTransaction
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardBeginTransaction
        (JNIEnv *, jobject, jint) {
    return 0;
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardEndTransaction
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardEndTransaction
        (JNIEnv *, jobject, jint, jint) {
    return 0;
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardState
 * Signature: (III[BI)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardState
        (JNIEnv *, jobject, jint, jint, jint, jbyteArray, jint) {
    return 0;
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardGetStatusChange
 * Signature: (III[BIIII[B)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardGetStatusChange
        (JNIEnv *, jobject, jint, jint, jint, jbyteArray, jint, jint, jint, jint, jbyteArray) {
    return 0;
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardStatus
 * Signature: (I[BIII[BI)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardStatus
        (JNIEnv *, jobject, jint, jbyteArray, jint, jint, jint, jbyteArray, jint) {
    return 0;
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardTransmit
 * Signature: (ILACSModule/SCARD_IO_REQUEST;[BILACSModule/SCARD_IO_REQUEST;[BI)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardTransmit
        (JNIEnv *, jobject, jint, jobject, jbyteArray, jint, jobject, jbyteArray, jint) {
    return 0;
}

/*
 * Class:     JacspcscLoader
 * Method:    SCardControl
 * Signature: (II[BI[BII)I
 */
JNIEXPORT jint JNICALL Java_JacspcscLoader_SCardControl
        (JNIEnv *env, jobject thisObject,
         jlong hCard,
         jint dwControlCode,
         jbyteArray lpInBuffer,
         jint nInBufferSize,
         jbyteArray lpOutBuffer,
         jint nOutBufferSize,
         jintArray lpBytesReturned) {


    jsize lpBytesReturnedSize = (*env)->GetArrayLength(env, lpBytesReturned);
    if (lpBytesReturnedSize == 0) {
        jclass iaeClazz = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, iaeClazz, "lpBytesReturned.length == 0");
    }

    jboolean isCopy = FALSE;
    jbyte * lpInBufferC = (*env)->GetByteArrayElements(env, lpInBuffer, &isCopy);
    jbyte * lpOutBufferC = (*env)->GetByteArrayElements(env, lpOutBuffer, &isCopy);

    DWORD lpBytesRet = 0;
    LONG result = SCardControl(hCard, dwControlCode, &lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, &lpBytesRet);

    (*env)->ReleaseByteArrayElements(env, lpInBuffer, lpInBufferC,  JNI_ABORT);
    (*env)->ReleaseByteArrayElements(env, lpOutBuffer, lpOutBufferC, 0);

    jint * lpBytesReturnedC = (*env)->GetIntArrayElements(env, lpBytesReturned, &isCopy);
    * lpBytesReturnedC = lpBytesRet;

    (*env)->ReleaseIntArrayElements(env, lpBytesReturned, lpBytesReturnedC, 0);


    return result;
}
