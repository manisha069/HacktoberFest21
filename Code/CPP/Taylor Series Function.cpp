double fact(int c)
{
   int factorial=1;
   for ( int i = 1; i <= c; i++ )
   {
      factorial *=i;
   }
   return factorial;
}

double taylor(double x, int n)
{
    double approx;
    double sum;
    double value;
    for (int i=1; i<=n; i++)
    {
        sum=((pow(x,i))/fact(i));
        value+=sum;
    }
    approx = 1+value;
    return approx;
}