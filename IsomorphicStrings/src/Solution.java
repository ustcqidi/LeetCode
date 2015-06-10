import java.util.HashMap;
import java.util.Map;

public class Solution {
	
    public boolean isIsomorphic(String s, String t) {
    	  Map<Character, Character> hash = new HashMap<Character, Character>();
    	  Map<Character, Character> hash2 = new HashMap<Character, Character>();
  		
  		if(s == null && t == null)
  			return true;
  		
  		if(s.equals("") && t.equals(""))
  			return true;
  		
  		for(int i = 0; i < s.length(); i++) {
  			char chInS = s.charAt(i);
  			char chInT = t.charAt(i);
  			
  			if(hash.containsKey(chInS) == true && hash.get(chInS) != chInT) {
  				return false;
  			}
  			
  			if(hash2.containsKey(chInT) == true && hash2.get(chInT) != chInS) {
  				return false;
  			}
  			
  			hash.put(chInS, chInT);
  			hash2.put(chInT, chInS);
  		}
  		
  		return true;
    }

	public static void main(String[] args) {
		
		Solution solution = new Solution();
		
		System.out.println(solution.isIsomorphic("ab", "aa"));
	}

}
