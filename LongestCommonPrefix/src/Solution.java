
public class Solution {
	
    
    public String longestCommonPrefix(String[] strs) {
    	
    	if(strs == null || strs.length <= 0) {
    		return "";
    	}
    	
    	if(strs.length == 1) {
    		return strs[0];
    	}
    	
    	int subStrIndex = 1;
    	String longestPrefix = "";
    	
    	while(subStrIndex <= strs[0].length()) {
    		String tmpPrefix = strs[0].substring(0, subStrIndex);
    		
    		int i;
    		for(i = 0; i < strs.length; i++) {
    			if(strs[i].startsWith(tmpPrefix) == false) {
    				break;
    			}
    		}
    		
    		if(i >= strs.length && tmpPrefix.length() > longestPrefix.length()) {
    			longestPrefix = tmpPrefix;
    			subStrIndex++;
    		} else {
    			return longestPrefix;
    		}
    		
    	}
    	
    	return longestPrefix;
    }

	public static void main(String[] args) {
		Solution solution = new Solution();
		
		String[] strs = new String[]{};
		
		System.out.println(solution.longestCommonPrefix(strs));
	}

}
