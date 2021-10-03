public class LCM {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int lcm ;
		
		if (a>b)
		{
			lcm = a;
		}
		else 
		{
			lcm = b;
		}
		while(true)
		{
			if (lcm%a==0 && lcm%b==0)
			{
				System.out.println(lcm);
				break;
			}
			++lcm;
		}
		
		
	}

}
