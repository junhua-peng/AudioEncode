#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "twolame.h"
using namespace std;
#pragma comment(lib,"twolame_staticD.lib")
#define MP2BUFSIZE		(16384)
#define AUDIOBUFSIZE	(9216)
long  framesize= 9216;
twolame_options *encodeOptions;
long readlen=0;
long writelen=0;
long framenum=0;
long numframe=0;
bool  encodeinit(long samplerate,long channels,long bit)
{
	   
	   //初始化
	    encodeOptions=twolame_init();
		twolame_set_in_samplerate(encodeOptions,samplerate);
		twolame_set_out_samplerate(encodeOptions,samplerate);
		twolame_set_num_channels(encodeOptions,channels);
		printf(">>>Input PCM File samplerate is %d\n",samplerate);
		if(channels==1)
		{
			twolame_set_mode(encodeOptions,TWOLAME_MONO);
		}
		if(channels==2)
		{
			twolame_set_mode(encodeOptions,TWOLAME_STEREO);
		}
		if(channels==1)
		{
			printf(">>>Input PCM File Channel MONO\n");
		}

		if(channels==2)
		{
			printf(">>>Input PCM File Channel STEREO\n");
		}

		int ret;
		ret=twolame_init_params(encodeOptions);
		if(ret==0)
		{
		    printf("init success\n\n");
			return true;
		}
		else
		{
			printf("init error\n");
			return false;
		}


}

unsigned char* mp2encode(short int *pcmdata,unsigned char* outbuf,long &outmp2len)
{
	
	printf("PCM Encode MP2 Processing...  ");
	//unsigned char *outbuf=new unsigned char[framesize]; //mp2数据保存
	writelen=twolame_encode_buffer_interleaved(encodeOptions,pcmdata,framesize, outbuf,MP2BUFSIZE);//有点杂音
	//fwrite(outbuf,sizeof(short int),writelen,outputfilename);
	outmp2len=writelen;
	numframe++;
	printf("[Frames=%06i]\r",numframe);
	if(writelen==0)
	{

		printf("Finished");
	}
	if(writelen<0)
	{
		printf("\nEncode Error\n");
	}
	 return outbuf;

}
void encode_cleanup()
{
	 twolame_close(&encodeOptions);
	 printf("\n");

}