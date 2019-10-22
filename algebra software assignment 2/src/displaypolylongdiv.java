import static java.lang.Integer.parseInt;

public class displaypolylongdiv {
    public void displaypolyld(int[][] poly) {
        int sizeq = poly[0].length;
        int sizer = poly[1].length;
        if (poly[0][0] == 0 && poly[0][1] == 0) {
            System.out.println("ERROR");
            System.out.println("ERROR");
        }
        else {
            int[] q = new int[sizeq];
            int[] r = new int[sizer];
            for(int i = 0; i < sizeq; i++){
                q[i] = poly[0][i];
            }
            for(int i = 0; i < sizer; i++){
                r[i] = poly[1][i];
            }

            int degreeq = sizeq - 1;
            int degreer = sizer - 1;
            int count=0;
            for(int i = 0; i < sizeq; i++) {
                if(degreeq > 1) {
                    if(q[i] == 0) {
                        degreeq--;
                        continue;
                    }
                    else if (q[i] == 1) {
                        System.out.print("X^" + degreeq + "+");
                        count++;
                    }
                    else {
                        System.out.print(q[i] + "X^" + degreeq + "+");
                        count++;
                    }
                }
                else if (degreeq == 0){
                    if(q[i] == 0){continue;}
                    else {
                        System.out.print(q[i]);
                        count++;
                    }
                }
                else if (degreeq == 1){

                    if(q[i] == 0){
                        degreeq--;
                        continue;
                    }
                    else if (q[i] == 1) {
                        if(q[i+1] == 0) {
                            System.out.print("X");
                            count++;
                        }
                        else {
                            System.out.print("X" +  "+");
                            count++;
                        }
                    }
                    else {
                        if(q[i+1] == 0) {
                            System.out.print(q[i] + "X");
                            count++;
                        }
                        else {
                            System.out.print(q[i] + "X" + "+");
                            count++;
                        }
                    }
                }
                degreeq--;
            }
            if(count==0) {
                System.out.println(0);
            }
            System.out.println();
            count = 0;
            for(int i = 0; i < sizer; i++) {
                if(degreer > 1) {
                    if(r[i] == 0) {
                        degreer--;
                        continue;
                    }
                    else if (r[i] == 1) {
                        System.out.print("X^" + degreer + "+");
                        count++;
                    }
                    else {
                        System.out.print(r[i] + "X^" + degreer + "+");
                        count++;
                    }
                }
                else if (degreer == 0){
                    if(r[i] == 0){continue;}
                    else {
                        System.out.print(r[i]);
                        count++;
                    }
                }
                else if (degreer == 1){

                    if(r[i] == 0){
                        degreer--;
                        continue;
                    }
                    else if (r[i] == 1) {
                        if(r[i+1] == 0) {
                            System.out.print("X");
                            count++;
                        }
                        else {
                            System.out.print("X" +  "+");
                            count++;
                        }
                    }
                    else {
                        if(r[i+1] == 0) {
                            System.out.print(r[i] + "X");
                            count++;
                        }
                        else {
                            System.out.print(r[i] + "X" + "+");
                            count++;
                        }
                    }
                }
                degreer--;
            }
            if(count==0) {
                System.out.println(0);
            }
            else System.out.println();
        }
    }
}
