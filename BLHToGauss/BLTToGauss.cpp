#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926535897932
double changerad(int a,int b,double c);
int main(void)
{
	int B1,B2,L1,L2,L01,L02;
	double B3,L3,L03,B,L,L0,l,a,b,e1,e2,X,Y,N,t,n,X0,A1,A2,A3,A4,A5;
	a=6.3781370e6;
	b=6356752.3142;
	e1=sqrt((a*a-b*b)/(a*a));
	e2=sqrt((a*a-b*b)/(b*b));
	printf("请按照度 分 秒输入中央子母线的经度\n");
	scanf("%d%d%lf",&L01,&L02,&L03);
	printf("请按照度 分 秒输入纬度\n");
	scanf("%d%d%lf",&B1,&B2,&B3);
	printf("请按照度 分 秒输入经度\n");
	scanf("%d%d%lf",&L1,&L2,&L3);
	B=changerad(B1,B2,B3);
	L=changerad(L1,L2,L3);
	L0=changerad(L01,L02,L03);
	l=L-L0;
	N=a/(sqrt(1-e1*e1*sin(B)*sin(B)));
    t=tan(B);
	n=e2*e2*cos(B)*cos(B);
	A1=1+3*pow(e1,2)/4+45*pow(e1,4)/64+175*pow(e1,6)/256+11025*pow(e1,8)/16384+43659*pow(e1,10)/65536;
	A2=3*pow(e1,2)/4+15*pow(e1,4)/16+525*pow(e1,6)/512+2205*pow(e1,8)/2048+72765*pow(e1,10)/65536;
	A3=15*pow(e1,4)/64+105*pow(e1,6)/256+2205*pow(e1,8)/4096+10395*pow(e1,10)/16384;
	A4=35*pow(e1,6)/512+315*pow(e1,8)/2048+31185*pow(e1,10)/131072;
	A5=315*pow(e1,8)/16384+3645*pow(e1,10)/65536;
	X0=a*(1-e1*e1)*(A1*B-A2*sin(2*B)/2+A3*sin(4*B)/4-A4*sin(6*B)/6+A5*sin(8*B)/8);
	X=X0+N/2*sin(B)*cos(B)*l*l+N/24*sin(B)*pow(cos(B),3)*(5-t*t+9*n*n+4*pow(n,4))*pow(l,4)+N/720*sin(B)*pow(cos(B),5)*(61-58*t*t+pow(t,4))*pow(l,6);
	Y=N*cos(B)*l+N/6*pow(cos(B),3)*(1-t*t+n*n)*l*l*l+N/120*pow(cos(B),5)*(5-18*t*t+pow(t,4)+14*n*n-58*n*n*t*t)*pow(l,5);
	printf("高斯坐标系下的坐标X=%lf,Y=%lf",X,Y);
	system ("pause");
	return 0;
}
double changerad(int a,int b,double c)
{
	double M;
	M=(a+b/60.0+c/3600.0)*PI/180.0;
	return M;
	int a = 0;
	//瞎改的
}
