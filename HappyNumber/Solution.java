public class Solution {

	//求一个数的每一痊的方法??
	public int caluDigitSquareSum(int n) {
		
		int sum = 0;
		
		while (n > 0) {
			sum += Math.pow((n%10), 2);
			
			n /= 10;
		}
		
		return sum;
		
	}
	
	public boolean isHappy(int n) {
		while(true) {
			n = caluDigitSquareSum(n);
			
			if(n == 1) {
				break;
			} else if(n == 4) 
				return false;
		}
		
		return true;
	}

	public static void main(String[] args) {
		Solution solution = new Solution();
		
		System.out.println(solution.isHappy(10));
	}

}
