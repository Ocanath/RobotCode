#include <stdio.h>
#include "userLib.h"
#include "io_hack.h"





int ten_to_power(int exp)
{
	int output = 1;
	int ti;
	for(ti = 0; ti < exp; ti++)
	{
		output = output * 10;
	}
	
	return output;
}


int get_integer_terminal()
{
	int UART_rd;
	int int_out = 0;
	int powten = 0;
	int digits[10];
	int neg_flag = 1;
	while(UART_rd != 13)
	{
		while(!DataRdyUART2());
		UART_rd = ReadUART2();
		
		if(UART_rd == 45)
			neg_flag = -1;
		

		if(UART_rd == 48){
			digits[powten] = 0;
			powten++;
		}
		if(UART_rd == 49){
//			int_out = int_out + ten_to_power(powten);	
			digits[powten] = 1;
			powten++;
		}
		if(UART_rd == 50){
//			int_out = int_out + 2*ten_to_power(powten);	
			digits[powten] = 2;
			powten++;
		}
		if(UART_rd == 51){
			//int_out = int_out + 3*ten_to_power(powten);	
			digits[powten] = 3;
			powten++;
		}
		if(UART_rd == 52){
//			int_out = int_out + 4*ten_to_power(powten);	
			digits[powten] = 4;
			powten++;
		}
		if(UART_rd == 53){
			//int_out = int_out + 5*ten_to_power(powten);	
			digits[powten] = 5;
			powten++;
		}
		if(UART_rd == 54){
			//int_out = int_out + 6*ten_to_power(powten);	
			digits[powten] = 6;
			powten++;
		}
		if(UART_rd == 55){
			//int_out = int_out + 7*ten_to_power(powten);	
			digits[powten] = 7;
			powten++;
		}
		if(UART_rd == 56){
			//int_out = int_out + 8*ten_to_power(powten);	
			digits[powten] = 8;
			powten++;
		}
		if(UART_rd == 57){
			//int_out = int_out + 9*ten_to_power(powten);	
			digits[powten] = 9;
			powten++;
		}

	}		
	int ti = 1;
	int di;
	for(di = powten-1; di >= 0; di--)
	{
		int_out = int_out + digits[di]*ti;
		ti*=10;
	}


	return int_out*neg_flag;

}


int get_int_arg(char inchar, int UART_rd)
{
	//int UART_rd;
	int int_out = 0;
	int powten = 0;
	int digits[10];
	int neg_flag = 1;
	while(UART_rd != inchar)
	{
		while(!DataRdyUART2())
		{
			//servomove(1);
		}
		UART_rd = ReadUART2();
		
		if(UART_rd == 45)
			neg_flag = -1;
		

		if(UART_rd == 48){
			digits[powten] = 0;
			powten++;
		}
		if(UART_rd == 49){
//			int_out = int_out + ten_to_power(powten);	
			digits[powten] = 1;
			powten++;
		}
		if(UART_rd == 50){
//			int_out = int_out + 2*ten_to_power(powten);	
			digits[powten] = 2;
			powten++;
		}
		if(UART_rd == 51){
			//int_out = int_out + 3*ten_to_power(powten);	
			digits[powten] = 3;
			powten++;
		}
		if(UART_rd == 52){
//			int_out = int_out + 4*ten_to_power(powten);	
			digits[powten] = 4;
			powten++;
		}
		if(UART_rd == 53){
			//int_out = int_out + 5*ten_to_power(powten);	
			digits[powten] = 5;
			powten++;
		}
		if(UART_rd == 54){
			//int_out = int_out + 6*ten_to_power(powten);	
			digits[powten] = 6;
			powten++;
		}
		if(UART_rd == 55){
			//int_out = int_out + 7*ten_to_power(powten);	
			digits[powten] = 7;
			powten++;
		}
		if(UART_rd == 56){
			//int_out = int_out + 8*ten_to_power(powten);	
			digits[powten] = 8;
			powten++;
		}
		if(UART_rd == 57){
			//int_out = int_out + 9*ten_to_power(powten);	
			digits[powten] = 9;
			powten++;
		}

	}		
	int ti = 1;
	int di;
	for(di = powten-1; di >= 0; di--)
	{
		int_out = int_out + digits[di]*ti;
		ti*=10;
	}


	return int_out*neg_flag;

}





void mv_io_inpt(int *btlg, int *mdlg, int *tplg)
{
	int UART_IN;
	
	int n;
	int ang;

	int bot_buf[6];	
	int top_buf[6];
	int mid_buf[6];
	
	int i;
	for(i = 1; i <=6; i++)
	{
		printf("btlg %d: %d, tplg %d: %d, mdlg %d: %d\n", i, btlg[i], i, tplg[i], i, mdlg[i] );
		bot_buf[i] = btlg[i];
		top_buf[i] = tplg[i];
		mid_buf[i] = mdlg[i];
		//servomove(1);
	}

	int out_flag = 0;

	int flag = 0;
	printf("Bottomleg:\r");
	while(flag == 0 && out_flag == 0)	
	{
		printf("bottomleg num: ");
		 n= get_int_arg(13 , UART_IN);
		if(n < 1 || n > 6)
			printf("no such leg, new input\n");
		if(n >= 1 && n <= 6)
		{
			printf("bottomleg angle: ");
			ang = get_int_arg(13, UART_IN);
			if(ang >= 400	&& ang <= 2300)
				bot_buf[n] = ang;
			if(ang < 400 || ang > 2300)
				printf("invalid angle, new input\n");
		}

		printf("new leg?\r");
		while(!DataRdyUART2())
		{
			//servomove(1);
		}
		UART_IN = ReadUART2();

		if(UART_IN == 'n' ||UART_IN == 'N' )
			flag = 1;
		else if(UART_IN == 'S' )
			out_flag = 1;
		else if(UART_IN == 'A' )
		{
			flag = 1;
			for(i = 1; i <= 6; i++)
				bot_buf[i] = ang;
		}

		else
			flag = 0;
	}



	flag = 0;
	printf("Middleleg:\r");
	while(flag == 0 && out_flag == 0)	
	{
		printf("Middleleg num: ");
		 n= get_int_arg(13 , UART_IN);
		if(n < 1 || n > 6)
			printf("no such leg, new input\n");
		if(n >= 1 && n <= 6)
		{
			printf("Middleleg angle: ");
			ang = get_int_arg(13, UART_IN);
			if(ang >= 400	&& ang <= 2300)
				mid_buf[n] = ang;
			if(ang < 400 || ang > 2300)
				printf("invalid angle, new input\n");
		}

		printf("new leg?\r");
		while(!DataRdyUART2())
		{
			//servomove(1);
		}
		UART_IN = ReadUART2();

		if(UART_IN == 'n' ||UART_IN == 'N' )
			flag = 1;
		else if(UART_IN == 'S' )
			out_flag = 1;
		else if(UART_IN == 'A' )
		{
			flag = 1;
			for(i = 1; i <= 6; i++)
				mid_buf[i] = ang;
		}
		else
			flag = 0;
	}

	flag = 0;
	printf("Topleg:\r");
	while(flag == 0 && out_flag == 0)	
	{
		printf("tople num: ");
		 n= get_int_arg(13 , UART_IN);
		if(n < 1 || n > 6)
			printf("no such leg, new input\n");
		if(n >= 1 && n <= 6)
		{
			printf("topleg angle: ");
			ang = get_int_arg(13, UART_IN);
			if(ang >= 400	&& ang <= 2300)
				top_buf[n] = ang;
			if(ang < 400 || ang > 2300)
				printf("invalid angle, new input\n");
		}

		printf("new leg?\r");
		while(!DataRdyUART2())
		{
			//servomove(1);
		}
		UART_IN = ReadUART2();

		if(UART_IN == 'n' ||UART_IN == 'N' )
			flag = 1;
		else if(UART_IN == 'S' )
			out_flag = 1;
		else if(UART_IN == 'A' )
		{
			flag = 1;
			for(i = 1; i <= 6; i++)
				top_buf[i] = ang;
		}

		else
			flag = 0;
	}
	
	for(i = 1; i <= 6; i++)
	{
		btlg[i] = bot_buf[i];
		mdlg[i] = mid_buf[i];
		tplg[i] = top_buf[i];
	}
	//servomove(1);


}	




/*

void io_lg_mv(int *btlg, int *tplg, int *mdlg)
{
	int position;
	int i;
	for(i = 1; i <=6; i++)
	{
		printf("btlg %d: %d, tplg %d: %d, mdlg %d: %d\n", i, btlg[i], i, tplg[i], i, mdlg[i] );
		//servomove(1);
	}
	
	printf("\r\r enter leg dofs: ");
	char UART_IN[150];
	for(i = 0; UART_IN[i] != 13 && i < 150; i++)
	{
		while(!DataRdyUART2())
		{
			//servomove(1);
		}
		UART_IN[i] = ReadUART2();
	}
	if(i == 150)
		printf("buffer overflow\r");


	while(!DataRdyUART2())
		//servomove(1);
	int UART_IN;
	int temp = get_int_arg(13 , UART_IN);
	if(ang >= 400	&& ang <= 2300)
		position = temp;
	if(ang < 400 || ang > 2300)
		printf("invalid angle, new input\n");


	int buf_size = i;
	for(i = 0; i < buf_size; i++)
	{
		if (i+3<buf_size &&  (UART_IN[i] == 'h' && UART_IN[i+1] == 'e' && UART_IN[i+2] == 'l' && UART_IN[i+3] == 'p'))
		{
		}
		if(UART_IN[i] == 'b' && UART_IN[i+1] == ' ' && UART_IN[i-1] == ' ')
		{
			for(i = 1; i <= 6; i++)
				btlg[i] = position;	
		}
		if(UART_IN[i] == 'b' && UART_IN[i+1] >= 49 && UART_IN[i+1] <= 54)
		{
			btlg[UART_IN[i+1] - 49] = position;
		}	
	}

	
}
*/
