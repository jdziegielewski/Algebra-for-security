/**
 * 
 */

/**
 * @author 20181064
 *
 */
public class convertpolynomial {
	public int[] polyconversion(String f, int mod){
		String testpoly = f.substring(1,f.length()-1);
		if(testpoly.length()==0) {
		int [] zero = new int[1];
		zero[0]=0;
		return zero;
		}
		else {
		String[] stringpoly = testpoly.split(",");
		int [] poly = new int[stringpoly.length];
		for(int i=0; i<poly.length;i++) {
			poly[i]=Integer.parseInt(stringpoly[i]);
		}
		//modular reduction
		int [] polyred = new int[stringpoly.length];
		for(int i=0; i<poly.length;i++) {
		double q1=Math.floor(poly[i]/(double) mod);
		int q = (int) q1;
		polyred[i]=poly[i]-q*mod;
		}
		return polyred;
		}
	}
}
