struct Servo 
{
	int error = 500, pin = 0;

	void define (byte p)
	{
		pin = p;
		pinMode(pin, OUTPUT);
	}
	void write (int angle)
	{
		short k = angle * 100 / 9;
		k += error;
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				digitalWrite(pin, j == 0 ? HIGH : LOW);
				delayMicroseconds(j == 0 ? k : 20000 - k);
			}
		}
	}
};