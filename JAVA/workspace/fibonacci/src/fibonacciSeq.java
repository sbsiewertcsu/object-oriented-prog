
public class fibonacciSeq {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println("fibComputeRecurse(30):");
		System.out.println(fibComputeRecurse(30));

		System.out.println("fibComputeIterate(30):");
		System.out.println(fibComputeIterate(30));

	}

	private static long fibComputeRecurse(final long n) {
		// TODO Auto-generated method stub
		
		if (n < 2)
			return n;
		else
			return fibComputeRecurse(n-1) + fibComputeRecurse(n-2);
		
	}
	
	private static long fibComputeIterate(long n)
	{
		if(n < 2)
			return n;
		
		long answer=0;
		long n1 = 0;
		long n2 = 1;
		
		for(n--; n > 0; n--)
		{
			answer = n1 + n2;
			n1 = n2;
			n2 = answer;
		}
		
		return answer;
	}

}
