class palindrome
{
  public static void main(String args[])
  {
    int n=Math.abs(Integer.valueOf(args[0]));
    int rev=0,t=n;
    while(n>0)
    {
      int rem=n%10;
      rev=rev*10+rem;
      n/=10;
    }
    if (rev==t)
    {
      System.out.println(t+" is a palindrome");
    }
    else
    {
      System.out.println(t+" is not a palindrome");
    }
  }
}
