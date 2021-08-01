void delay(volatile long time)
{
	for(int i=0;i<time;i++)
	{
		for(int i=time;i>0;i--);
	}
}
