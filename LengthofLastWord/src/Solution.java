public class Solution {

public int lengthOfLastWord(String s) {
		
		if(s == null || s == "" || s == " ") {
			return 0;
		}
		
		s = s.trim();
		
		if(s.indexOf(" ") == 0) {
			return s.length();
		}
		
		int CurrIndex = 0;
		String cachedWord = s;
		
		while(cachedWord.indexOf(" ") > 0) {
			CurrIndex = cachedWord.indexOf(" ");
			while(cachedWord.charAt(CurrIndex) == ' ')
				CurrIndex++;
			cachedWord = cachedWord.substring(CurrIndex);
		}
		
		return cachedWord.length();
	}

	public static void main(String[] args) {
		Solution solution = new Solution();
		System.out.println("" + solution.lengthOfLastWord("b   a    "));
	}

}
