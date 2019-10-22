import java.util.ArrayList;
import java.util.List;

public class polyequalspoly {
    public boolean peqp(int[] fpre, int[] gpre, int[] pmod, int mod) {

        int size1 = fpre.length;
        int size2 = gpre.length;
        int sizep = pmod.length;
        int size = Math.max(Math.max(size1, size2), sizep);
        int[] f = new int[size];
        int[] g = new int[size];
        int[] p = new int[size];
        boolean yes;

        if (pmod[0] == 0){
            yes = false;
        }
        else {
            for (int i = 0; i < size; i++) {
                f[i] = 0;
                g[i] = 0;
                p[i] = 0;
            }

            for (int i = size - size1, j = 0; j < size1; j++, i++) {
                f[i] = fpre[j];
            }

            for (int i = size - size2, j = 0; j < size2; j++, i++) {
                g[i] = gpre[j];
            }

            for (int i = size - sizep, j = 0; j < sizep; j++, i++) {
                p[i] = pmod[j];
            }

            int s1 = size1;
            int s2 = size2;
            int sp = sizep;


            int[] r1 = f;
            int[] r2 = g;

            int sizer1 = size1;
            int sizer2 = size2;
            int degreer1 = sizer1 - 1;
            int degreer2 = sizer2 - 1;
            int degreep = sizep - 1;

            // first polynomial mod third polynomial
            for (int i = 0; i < size; i++){
                int j;
                if(degreer1 >= degreep){
                    if(i < size-sizep){
                        j = size - sizep;
                    }
                    else{
                        j = i;
                    }
                    int lcr1 = r1[i];
                    r1[i] -= (lcr1 / p[size-sizep]);
                    int ii = i;
                    while(j < size - 1){
                        r1[ii+1] -= p[j+1] * (lcr1 / p[size-sizep]);
                        ii++;
                        j++;
                    }
                    degreer1--;
                }
            }
            for(int i = size - degreep; i < size; i++){
                while(r1[i] > mod){
                    r1[i] -= mod;
                }
                while (r1[i] < 0){
                    r1[i] += mod;
                }
            }

            //second polynomial mod third polynomial
            for (int i = 0; i < size; i++){
                int j;
                if(degreer2 >= degreep){
                    if(i < size-sizep){
                        j=size-sizep;
                    }
                    else{
                        j = i;
                    }
                    int lcr2 = r2[i];
                    r2[i] -= (lcr2 / p[size-sizep]);
                    int ii = i;
                    while(j < size - 1){
                        r2[ii+1] -= p[j+1] * (lcr2 / p[size-sizep]);
                        ii++;
                        j++;
                    }
                    degreer2--;
                }
            }
            for(int i = size - degreep; i < size; i++){
                while(r2[i] > mod){
                    r2[i] -= mod;
                }
                while (r2[i] < 0){
                    r2[i] += mod;
                }
            }

            int k = 0;
            if(degreer1 == degreer2){
                for (int i = size - degreep; i < size; i++){
                    if(r1[i] == r2[i]){
                        k++;
                    }
                }
                if (k == degreep){
                    yes = true;
                }
                else{
                    yes = false;
                }
            }
            else {
                yes = false;
            }
        }

        return yes;

    }
}
