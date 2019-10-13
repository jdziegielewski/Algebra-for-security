public class euclidalgo {
    public int[] euclidAlgo(int[] a,int[] b) {

    }

    public int[] divwsubtraction (int[] a, int[] b) {
        polynomialsubtraction divObj = new polynomialsubtraction();

        //for-cycle (dega > degb) {do polynomialsubtraction() count++)
        //divObj.polysubtraction(a,b, 10);

    }

    public int finddegree(int[] a) {
        int degA = a.length;

        for (int i = a.length; i <= 0; i-- ) {
            if (a[i-1]==0) {
                degA = degA - 1;
            }
        }
        return degA;
    }
}
