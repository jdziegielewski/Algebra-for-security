/**
 * 
 */

/**
 * @author 20181064
 *
 */
public class displaypolynomial {

public void displaypoly(int[] poly) {
	int size=poly.length;
	int degree=size-1;
	int count=0;
	for(int i=0;i<size;i++) {
		if(degree>1) {
			if(poly[i]==0) {
				degree--;
				continue;}
			else if (poly[i]==1) {
				System.out.print("X^" + degree + "+");
				count++;
			}
			else {
				System.out.print(poly[i] + "X^" + degree + "+");
				count++;
			}
		}
		else if (degree==0){
			if(poly[i]==0){continue;}
			else {
				System.out.print(poly[i]);
				count++;
			}
		}
		else if (degree==1){
			
			if(poly[i]==0){
				degree--;
				continue;}
			else if (poly[i]==1) {
				if(poly[i+1]==0) {
					System.out.print("X");
					count++;
				}
				else {
				System.out.print("X" +  "+");
				count++;
				}
			}
			else {
				if(poly[i+1]==0) {
					System.out.print(poly[i] + "X");
					count++;
				}
				else {
				System.out.print(poly[i] + "X" + "+");
				count++;
				}
			}
		}
		degree--;
	}
	if(count==0) {
	System.out.println(0);
	}
	else System.out.println();
	
}
}
