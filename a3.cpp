/**
* Calculating power 
*/

int globalanswer;


int sum2()


int pow(int b)
{
  if (b == 0)
    return 1;
  int answer = 2;
  int increment = 2;
  int i, j;
  for(i = 1; i < b; i++)
  {
     for(j = 1; j < 2; j++)
     {
        answer += increment;
     }
     increment = answer;
  }
  return answer;
}


main()
{
	int power;
	cout<<"Enter Power of Two ";
	cin>>power;
	globalanswer=pow(power);
	cout<< "Power of Two is "<<globalanswer<<endl;

}