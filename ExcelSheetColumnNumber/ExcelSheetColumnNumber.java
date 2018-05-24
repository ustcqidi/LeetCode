import java.util.HashMap;
import java.util.Map;


public class ExcelSheetColumnNumber {
    
	private Map<String, Integer> excelSheetNumMap = new HashMap<String, Integer>();
    
    private void initMap() {
    	excelSheetNumMap.clear();
    	excelSheetNumMap.put("A", 1);
    	excelSheetNumMap.put("B", 2);
    	excelSheetNumMap.put("C", 3);
    	excelSheetNumMap.put("D", 4);
    	excelSheetNumMap.put("E", 5);
    	excelSheetNumMap.put("F", 6);
    	excelSheetNumMap.put("G", 7);
    	excelSheetNumMap.put("H", 8);
    	excelSheetNumMap.put("I", 9);
    	excelSheetNumMap.put("J", 10);
    	excelSheetNumMap.put("K", 11);
    	excelSheetNumMap.put("L", 12);
    	excelSheetNumMap.put("M", 13);
    	excelSheetNumMap.put("N", 14);
    	excelSheetNumMap.put("O", 15);
    	excelSheetNumMap.put("P", 16);
    	excelSheetNumMap.put("Q", 17);
    	excelSheetNumMap.put("R", 18);
    	excelSheetNumMap.put("S", 19);
    	excelSheetNumMap.put("T", 20);
    	excelSheetNumMap.put("U", 21);
    	excelSheetNumMap.put("V", 22);
    	excelSheetNumMap.put("W", 23);
    	excelSheetNumMap.put("X", 24);
    	excelSheetNumMap.put("Y", 25);
    	excelSheetNumMap.put("Z", 26);
    }
    
	public int titleToNumber(String s) {
		initMap();
		
		if(s.length() == 1)
			return excelSheetNumMap.get(s).intValue();
		
		int sum = 0;
		for(int i = 0; i < s.length()-1; i++) {
			String key = Character.toString(s.charAt(i));
			sum += excelSheetNumMap.get(key).intValue() * Math.pow(26, (s.length() - i - 1));
		}
		
		sum += excelSheetNumMap.get(Character.toString(s.charAt(s.length()-1))).intValue();
		
		return sum;
    }
    
	public static void main(String[] args) {
		ExcelSheetColumnNumber excel = new ExcelSheetColumnNumber();
		System.out.print(excel.titleToNumber("AAA"));
	}

}
