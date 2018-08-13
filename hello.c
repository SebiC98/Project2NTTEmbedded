#include <iostream>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


using namespace std;

int fd;
unsigned char hello[]={'H','e','l','l','o',' ','A','r','d','u','i','n','o','2','\n'};

unsigned char result;

int spiTxRx(unsigned char txDat);

int main(void)
{
 fd=open("/dev/spidev0.0",O_RDWR);

 unsigned int speed = 115200;
 ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
 while(1)
 {
	for(int i=0;i<sizeof(hello);i++)
	 {
		result=spiTxRx(hello[i]);
		cout<<result;
		usleep(10);
               
	}
}
}

int spiTxRx(unsigned char txDat)
{
unsigned char rxDat;

struct spi_ioc_transfer spi;

memset(&spi,0,sizeof(spi));

spi.tx_buf = (unsigned long)&txDat;
spi.rx_buf = (unsigned long)&rxDat;
spi.len    = 1;

ioctl(fd, SPI_IOC_MESSAGE(1),&spi);
return rxDat;
}
