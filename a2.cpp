/* PROGRAM Pwer2*/
int val, power, i;

spinlock L;

main()
{
	cout <<"Power of Two: ";
	cin >>power;
	val =1;
	forall i = 1 to power grouping 6 do	
		val =  2*val;

	cout <<" Answer is "<<val <<endl;

}