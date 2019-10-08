/**
 * 
 */

/**
 * @author 20181064
 *
 */
public class polynomialaddition {
	public int[] polyaddition(int[] fpre,int[] gpre,int mod) {
		int size1=fpre.length;
		int size2=gpre.length;
		int zprime;
		int size = Math.max(size1,size2);
		int [] f = new int[size];
		int [] g = new int[size];
		int [] result = new int[size];
 		for(int i=0; i<size;i++) {
			f[i]=0;
			g[i]=0;
		}
		for(int i=size-size1,j=0;j<size1;j++,i++) {
			f[i]=fpre[j];
			
		}
		for(int i=size-size2,j=0;j<size2;j++,i++) {
			g[i]=gpre[j];
			
		}
		for(int i=0;i<size;i++) {
			zprime=f[i]+g[i];
			if(zprime<mod) {
				result[i]=zprime;
			}
			else {
				result[i]=zprime-mod;
			}
		}
		return result;
	}
}
