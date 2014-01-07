#ifndef LIB_AUDIOENCODE_H
#define LIB_AUDIOENCODE_H
#ifdef AUDIOENCODEDLL
#define AUDIOENCODEDLL extern "C" _declspec(dllimport);
#else
#define AUDIOENCODEDLL extern "C" _declspec(dllexport);
#endif

/*初始化编码库
* \ param  samplerate  采样率  如 44100 16000
* \param   channels   通道数   单通道为1 双通道为2
* \param   bit      采样位数   如8位 16位
*\ return           成功返回true 失败返回false
*/
AUDIOENCODEDLL bool encodeinit(long samplerate,long channels,long bit);

/*pcm编码为mp2
* \param  pcmdata    pcm数据 一帧数据量
* \param  outmp2len  pcm编码为mp2后输出一帧mp2数据长度  fwrite写入时用到。
*  return 返回一帧mp2数据地址 fwrite写入时用到。
*/
AUDIOENCODEDLL unsigned char* mp2encode(short int *pcmdata,unsigned char* outbuf,long &outmp2len);

//关闭编码器
AUDIOENCODEDLL void encode_cleanup();
#endif