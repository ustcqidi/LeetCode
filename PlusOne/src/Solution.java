public class Solution {

	private int[] tmpDigits;

	public int[] plusOne(int[] digits) {

		if (digits[digits.length - 1] + 1 < 10) {
			digits[digits.length - 1] += 1;

			return digits;
		}

		digits[digits.length - 1] = 0;

		int subDigitArrLen = digits.length - 1 > 0 ? digits.length - 1 : 1;

		tmpDigits = new int[subDigitArrLen];
		for (int i = 0; i < digits.length - 1; i++) {
			tmpDigits[i] = digits[i];
		}

		int[] result = plusOne(tmpDigits);

		int retDigArrLen = result.length == digits.length ? digits.length + 1 : digits.length;
		int[] retDigArr = new int[retDigArrLen];
		
		for (int i = 0; i < result.length; i++) {
			retDigArr[i] = result[i];
		}

		return retDigArr;
	}

	public static void main(String[] args) {

		int[] test = new int[] { 1,9,9, 9 };

		Solution solution = new Solution();

		int[] result = solution.plusOne(test);

		for (int i = 0; i < result.length; i++) {
			System.out.print(" " + result[i]);
		}
	}

}
