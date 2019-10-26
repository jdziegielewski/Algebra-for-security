
public class polynomialmulti {
	    public int[] polymulti(int[] a, int[] b, int mod) {
	        int m = a.length;
	        int n = b.length;
	        int[] prod = new int[m + n - 1];

	        // Initialize the porduct polynomial
	        for (int i = 0; i < m + n - 1; i++) {
	            prod[i] = 0;
	        }

	        // Multiply two polynomials term by term
	        // Take ever term of first polynomial
	        for (int i = 0; i < m; i++) {
	            // Multiply the current term of first polynomial
	            // with every term of second polynomial.
	            for (int j = 0; j < n; j++) {
	                prod[i + j] += a[i] * b[j];
	            }
	        }

	        //adjust coefficients according
	        for (int i = 0; i < m + n -1; i++) {
	            prod[i]=prod[i]%mod;
	        }

	        int[] copy = new int[m+n-1];
	        for (int i = 0; i < m + n -1; i++) {
	            copy[i] = prod[m+n-2-i];
	        }

	        return copy;
	    }
	
}
