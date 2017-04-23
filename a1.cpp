/* PROGRAM Pwer2*/
int val, power, i;

spinlock L;

main()
{
	cout <<"Power of Two: ";
	cin >>power;
	val =1;
	forall i = 1 to power grouping 2 do
	{		Lock(L);
			val =  2*val;
			Unlock(L);
	}

	cout <<" Answer is "<<val <<endl;

}