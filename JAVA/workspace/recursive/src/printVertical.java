
public class printVertical {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println("writeVertical(3):");
		writeVertical(3);
		
		System.out.println("writeVertical(12):");
		writeVertical(12);

		System.out.println("writeVertical(123):");
		writeVertical(123);

	}

	private static void writeVertical(int n) {
		// TODO Auto-generated method stub
		
		if(n < 10)
		{
			System.out.println(n);
		}
		else
		{
			writeVertical(n/10);
			System.out.println(n % 10);
		}
		
	}

}
