import java.util.Arrays;

public class longdivision {
	public int[][] longdiv(int[] fpre, int[] gpre, int mod) {
		int size1 = fpre.length;
		int size2 = gpre.length;

		int size = Math.max(size1, size2);
		int[] f = new int[size];
		int[] g = new int[size];

		for (int i = 0; i < size; i++) {
			f[i] = 0;
			g[i] = 0;
		}

		for (int i = size - size1, j = 0; j < size1; j++, i++) {
			f[i] = fpre[j];
		}

		for (int i = size - size2, j = 0; j < size2; j++, i++) {
			g[i] = gpre[j];
		}

		int[] r = f;
		int[] q = new int[Math.abs(size1-size2)+1];
		int degreer = size1 - 1;
		int degreeg = size2 - 1;
		int degreef = degreer;

		//if g is 0
		if(g[0] == 0 && size2 == 1){
			int[][] result = new int[5][5];
			for(int i = 0; i < 2; i++){
				result[i][0] = 0;
				result[i][1] = 0;
				result[i][2] = 0;
				result[i][3] = 0;
				result[i][4] = 0;
			}
			return result;
		}

		//if polynomials have degree 0
		else if(degreeg == degreer && degreeg == 0){
			int[] rem = new int[mod];
			int[] qq = new int[mod];
			for(int i = 0; i < mod; i++){
				rem[i] = 0;
				qq[i] = 0;
			}
			int x;
			//vedem ce resturi sunt daca inmultim r cu nr pana la 7 si tinem minte
			//primul nr care da acel rest
			for(int i = 0; i < mod; i++){
				x = (r[0] + 7 * i) % g[0];
				while(x > mod){
					x -= mod;
				}
				rem[x]++;
				if(qq[x] == 0){
					qq[x] = r[0] + 7 * i;
				}
			}
			int kr = 0; //the reminder
			int kq = 0; //the number which gives that reminder
			for(int i = 0; i < mod-1; i++){
				if(rem[i] > 0){
					kr = i;
					kq = qq[i]/g[0];
					break;
				}
			}


			int[][] result = new int[2][1]; //two dimension array of strings to store the qoutient and reminder
			result[0][0] = kq;
			result[1][0] = kr;
			return result;

		}
		else if (size1 >= size2){
			for(int i = 0; i < size2; i++){
				while(g[i] < 0){
					g[i] += mod;
				}
				while (g[i] >= mod){
					g[i] -= mod;
				}
			}
			while (degreer >= degreeg){
				int j = degreer - degreeg;
				for(int i = degreef - degreer; i < size1 - size2 + 1; i++){
					for(int i2 = degreef - degreer; i2 < size1; i2++){
						while(r[i2] < 0){
							r[i2] += mod;
						}
						while (r[i2] >= mod){
							r[i2] -= mod;
						}
					}
					int x;
					int k = degreef - degreer;
					int lcr = r[k];
					int qq = 0;
					int lcg = g[degreef - degreeg];
					for(int i1 = 0; i1 < mod; i1++){
						x = i1 * lcg;
						while(Math.abs(x) >= mod){
							if(x > 0){
								x -= mod;
							}
							else{
								x += mod;
							}
						}
						if (x == lcr){
							qq = i1;
							break;
						}
					}
					q[j] = qq;
					j--;
					if (i < size - size2){
						k = size - size2;
					}
					else{
						k = i;
					}
					x = qq * g[k];
					while(Math.abs(x) >= mod){
						if(x < 0){
							x += mod;
						}
						else{
							x -= mod;
						}
					}
					r[i] -= x;
					int ii = i;
					while(k < size - 1){
						x = qq * g[k + 1];
						while(Math.abs(x) >= mod){
							if(x < 0){
								x += mod;
							}
							else{
								x -= mod;
							}
						}
						r[ii + 1] -= x;
						ii++;
						k++;
					}
					degreer--;
				}
			}
			for(int i2 = degreef - degreer; i2 < size1; i2++){
				while(r[i2] < 0){
					r[i2] += mod;
				}
				while (r[i2] >= mod){
					r[i2] -= mod;
				}
			}

			int[][] result = new int[2][];
			result[0] = new int[degreef - degreeg + 1]; //store the quotient
			result[1] = new int[degreef - degreer + 1]; //store the reminder


			for (int i = degreef - degreeg, j=0; i >= 0; i--, j++){
				result[0][j] = q[i];
			}
			for (int i = degreef - degreer; i <= degreef; i++){
				result[1][i] = r[i];
			}

			return result;

		}
		else {
			int [][] result = new int[2][];
			result[0] = new int[1];
			result[1] = new int[size1];
			result[0][0] = 0;
			int j = 0;
			for (int i = degreeg - degreer; i <= degreeg; i++){
				result[1][j] = r[i];
			}
			return result;

		}
	}
}
