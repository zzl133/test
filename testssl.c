#include<string.h>
#include<stdio.h.h>
#include<stdlib.h>
#include<openssl/rsa.h>
#include<openssl/aes.h>

int main(void)
{
	//1.产生RSA密钥对
	//产生512字节公钥指数未RSA_F4的密钥对，公钥指数有RSA_F4和RSA_3两种
	//我不清楚他们的区别，就顺便选定RSA_F4
	//可以使用RSA_PRINT_FP()看看里的东西
	
	RSA *ClientRsa=RSA_generate_key(512,RSA_F4,NULL,NULL);

	//--------
	//2.从RSA结构中提取到BUFF，以便将它传输给对方
	//512位的RSA其公钥提出来长度是74字节，而私钥提取出来有超过300字节
	//未保险起见，建议给他们预留一个512字节的空间
	

	unsigned char Publickey[512];
	unsigned char *Pkey=Publickey; //注意这个指针不是多余，是特意要这样做的
    int PublickeyLen=i2d_RSAPublickey(ClientRsa,&PKey);

	//不能采用下面的方法，因为i2d——RSAPublickey()会修改Publickey的值
	//所以要引入PKey，让他作为替死鬼
	//unsigned char *Publickey=(unsigned char*)malloc(512);
	//int PublickeyLen=i2d_RSAPublickey(ClientRsa,&Publickey);
	
	//逐个字符打印Publickey信息
	
	printf("PublickeyBuff,Len=%d\n",PublickeyLen);
	for(int i=0;i<PublickeyLen;i++)
	{
		printf("0x%02x, ",*(Publickey+i));
	}
	printf("\n");

}

