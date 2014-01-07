#ifndef LIB_AUDIOENCODE_H
#define LIB_AUDIOENCODE_H
#ifdef AUDIOENCODEDLL
#define AUDIOENCODEDLL extern "C" _declspec(dllimport);
#else
#define AUDIOENCODEDLL extern "C" _declspec(dllexport);
#endif

/*��ʼ�������
* \ param  samplerate  ������  �� 44100 16000
* \param   channels   ͨ����   ��ͨ��Ϊ1 ˫ͨ��Ϊ2
* \param   bit      ����λ��   ��8λ 16λ
*\ return           �ɹ�����true ʧ�ܷ���false
*/
AUDIOENCODEDLL bool encodeinit(long samplerate,long channels,long bit);

/*pcm����Ϊmp2
* \param  pcmdata    pcm���� һ֡������
* \param  outmp2len  pcm����Ϊmp2�����һ֡mp2���ݳ���  fwriteд��ʱ�õ���
*  return ����һ֡mp2���ݵ�ַ fwriteд��ʱ�õ���
*/
AUDIOENCODEDLL unsigned char* mp2encode(short int *pcmdata,unsigned char* outbuf,long &outmp2len);

//�رձ�����
AUDIOENCODEDLL void encode_cleanup();
#endif