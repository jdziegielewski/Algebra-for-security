
public class longdivision {
	public int[] longdiv(int[] a,int[] b) {
		int [] q = new int [a.length];
		for(int i=0;i<a.length;i++) {
			q[i]=0;
		}
		int [] r = a;
		int sizer=r.length;
		int degreer=sizer-1;
		int sizeb=b.length;
		int degreeb=sizeb-1;
		int degree;
		while(degreer>=degreeb) {
			int i=0;
			q[i]=q[i]+r[0]/b[0];
		}
		
	}
}
