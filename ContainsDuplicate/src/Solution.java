import java.util.HashSet;
import java.util.Set;

public class Solution {
	
	
	public boolean containsDuplicate(int[] nums) {
		
		Set<Integer> set = new HashSet<Integer>();
		
		for(int i = 0; i < nums.length; i++) {
			if(set.contains(nums[i]) == true) {
				return true;
			}
			
			set.add(nums[i]);
		}
		
		return false;
	}

	public static void main(String[] args) {
		Solution solution = new Solution();
		
		int [] nums = new int[]{1, 2, 2, 4};
		
		System.out.println("" + solution.containsDuplicate(nums));
	}

}
