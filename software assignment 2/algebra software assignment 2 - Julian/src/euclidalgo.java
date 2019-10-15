public class euclidalgo {
    public int[] euclidAlgo(int[] a, int[] b, int mod) {
        int size = Math.max(a.length, b.length);
        int[] X = new int[size];
        X[0] = 1;
        int[] Xp = new int[size];


        int[] V = new int[size];
        V[0] = 1;


        int[] Y = new int[size];
        Y[0] = 0;
        int[] Yp = new int[size];


        int[] U = new int[size];
        U[0] = 0;

        int[] Q = new int[size];
        int[] Qp = new int[size];
        int[] R = new int[size];

        int[] QU = new int[size];
        int[] QV = new int[size];


        while (b[0] != 0) {
            Q = longdivquo(a, b, mod);
            R = longdivrem(a, b, mod);
            a = b;
            b = R;
            Xp = X;
            Yp = Y;
            X = U;
            Y = V;
            QU = polymultiplication(Q, U, mod);
            QV = polymultiplication(Q, V, mod);
            U = polysubtraction(Xp, QU, mod);
            V = polysubtraction(Yp, QV, mod);

        }
        return X;
    }


    public int[] polysubtraction(int[] fpre, int[] gpre, int mod) {
        int size1 = fpre.length;
        int size2 = gpre.length;
        int zprime;
        int size = Math.max(size1, size2);
        int[] f = new int[size];
        int[] g = new int[size];
        int[] result = new int[size];
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
        for (int i = 0; i < size; i++) {
            zprime = f[i] - g[i];
            if (zprime >= 0) {
                result[i] = zprime;
            } else {
                result[i] = zprime + mod;
            }
        }
        return result;
    }

    public int[] longdivquo(int[] fpre, int[] gpre, int mod) {
        int size1 = fpre.length;
        int size2 = gpre.length;
        int size = Math.max(size1, size2);
        int[] f = new int[size];
        int[] g = new int[size];

        for (int i = 0; i<size; i++){
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
        int[] q = new int[Math.abs(size1 - size2) + 1];
        int degreer = size1 - 1;
        int degreeg = size2 - 1;
        int degreef = degreer;

        if (g[0] == 0 && size2 == 1) {
            System.out.println("ERROR");
            System.out.println("ERROR");
        }

        //if polynomials have degree 0
        else if (degreeg == degreer && degreeg == 0) {
            int[] rem = new int[mod];
            int[] qq = new int[mod];
            for (int i = 0; i < mod; i++) {
                rem[i] = 0;
                qq[i] = 0;
            }
            int x;
            //vedem ce resturi sunt daca inmultim r cu nr pana la 7 si tinem minte
            //primul nr care da acel rest
            for (int i = 0; i < mod; i++) {
                x = (r[0] + 7 * i) % g[0];
                while (x > mod) {
                    x -= mod;
                }
                rem[x]++;
                if (qq[x] == 0) {
                    qq[x] = r[0] + 7 * i;
                }
            }
            int kr = 0; //the reminder
            int kq = 0; //the number which gives that reminder
            for (int i = 0; i < mod - 1; i++) {
                if (rem[i] > 0) {
                    kr = i;
                    kq = qq[i] / g[0];
                    break;
                }
            }
            System.out.println(kq);
            System.out.println(kr);
        } else if (size1 >= size2) {
            for (int i = 0; i < size2; i++) {
                while (g[i] < 0) {
                    g[i] += mod;
                }
                while (g[i] >= mod) {
                    g[i] -= mod;
                }
            }
            while (degreer >= degreeg) {
                int j = degreer - degreeg;
                for (int i = degreef - degreer; i < size1 - size2 + 1; i++) {
                    for (int i2 = degreef - degreer; i2 < size1; i2++) {
                        while (r[i2] < 0) {
                            r[i2] += mod;
                        }
                        while (r[i2] >= mod) {
                            r[i2] -= mod;
                        }
                    }
                    int x;
                    int k = degreef - degreer;
                    int lcr = r[k];
                    int qq = 0;
                    int lcg = g[degreef - degreeg];
                    for (int i1 = 0; i1 < mod; i1++) {
                        x = i1 * lcg;
                        while (Math.abs(x) >= mod) {
                            if (x > 0) {
                                x -= mod;
                            } else {
                                x += mod;
                            }
                        }
                        if (x == lcr) {
                            qq = i1;
                            break;
                        }
                    }
                    q[j] = qq;
                    j--;
                    if (i < size - size2) {
                        k = size - size2;
                    } else {
                        k = i;
                    }
                    x = qq * g[k];
                    while (Math.abs(x) >= mod) {
                        if (x < 0) {
                            x += mod;
                        } else {
                            x -= mod;
                        }
                    }
                    r[i] -= x;
                    int ii = i;
                    while (k < size - 1) {
                        x = qq * g[k + 1];
                        while (Math.abs(x) >= mod) {
                            if (x < 0) {
                                x += mod;
                            } else {
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
            for (int i2 = degreef - degreer; i2 < size1; i2++) {
                while (r[i2] < 0) {
                    r[i2] += mod;
                }
                while (r[i2] >= mod) {
                    r[i2] -= mod;
                }
            }
        }
        return q;
    }

    public int[] longdivrem(int[] fpre, int[] gpre, int mod) {
        int size1 = fpre.length;
        int size2 = gpre.length;
        int size = Math.max(size1, size2);
        int[] f = new int[size];
        int[] g = new int[size];

        for (int i = 0; i<size; i++){
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
        int[] q = new int[Math.abs(size1 - size2) + 1];
        int degreer = size1 - 1;
        int degreeg = size2 - 1;
        int degreef = degreer;

        if (g[0] == 0 && size2 == 1) {
            System.out.println("ERROR");
            System.out.println("ERROR");
        }

        //if polynomials have degree 0
        else if (degreeg == degreer && degreeg == 0) {
            int[] rem = new int[mod];
            int[] qq = new int[mod];
            for (int i = 0; i < mod; i++) {
                rem[i] = 0;
                qq[i] = 0;
            }
            int x;
            //vedem ce resturi sunt daca inmultim r cu nr pana la 7 si tinem minte
            //primul nr care da acel rest
            for (int i = 0; i < mod; i++) {
                x = (r[0] + 7 * i) % g[0];
                while (x > mod) {
                    x -= mod;
                }
                rem[x]++;
                if (qq[x] == 0) {
                    qq[x] = r[0] + 7 * i;
                }
            }
            int kr = 0; //the reminder
            int kq = 0; //the number which gives that reminder
            for (int i = 0; i < mod - 1; i++) {
                if (rem[i] > 0) {
                    kr = i;
                    kq = qq[i] / g[0];
                    break;
                }
            }
            System.out.println(kq);
            System.out.println(kr);
        } else if (size1 >= size2) {
            for (int i = 0; i < size2; i++) {
                while (g[i] < 0) {
                    g[i] += mod;
                }
                while (g[i] >= mod) {
                    g[i] -= mod;
                }
            }
            while (degreer >= degreeg) {
                int j = degreer - degreeg;
                for (int i = degreef - degreer; i < size1 - size2 + 1; i++) {
                    for (int i2 = degreef - degreer; i2 < size1; i2++) {
                        while (r[i2] < 0) {
                            r[i2] += mod;
                        }
                        while (r[i2] >= mod) {
                            r[i2] -= mod;
                        }
                    }
                    int x;
                    int k = degreef - degreer;
                    int lcr = r[k];
                    int qq = 0;
                    int lcg = g[degreef - degreeg];
                    for (int i1 = 0; i1 < mod; i1++) {
                        x = i1 * lcg;
                        while (Math.abs(x) >= mod) {
                            if (x > 0) {
                                x -= mod;
                            } else {
                                x += mod;
                            }
                        }
                        if (x == lcr) {
                            qq = i1;
                            break;
                        }
                    }
                    q[j] = qq;
                    j--;
                    if (i < size - size2) {
                        k = size - size2;
                    } else {
                        k = i;
                    }
                    x = qq * g[k];
                    while (Math.abs(x) >= mod) {
                        if (x < 0) {
                            x += mod;
                        } else {
                            x -= mod;
                        }
                    }
                    r[i] -= x;
                    int ii = i;
                    while (k < size - 1) {
                        x = qq * g[k + 1];
                        while (Math.abs(x) >= mod) {
                            if (x < 0) {
                                x += mod;
                            } else {
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
            for (int i2 = degreef - degreer; i2 < size1; i2++) {
                while (r[i2] < 0) {
                    r[i2] += mod;
                }
                while (r[i2] >= mod) {
                    r[i2] -= mod;
                }
            }
        }
        return r;
    }

    public int[] polymultiplication(int[] a, int[] b, int mod) {
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

        for (int i = 0; i < m + n -1; i++) {
            prod[i]=prod[i]%mod;
        }

        int[] copy = new int[m+n-1];
        for (int i = 0; i < m + n -1; i++) {
            copy[i] = prod[m+n-2-i];
        }

        return copy;
    }


//    public int finddegree(int[] a) {
//        int degA = a.length;
//
//        for (int i = a.length - 1; i >= 0; i--) {
//            if (a[i] == 0) {
//                degA = degA - 1;
//            }
//        }
//        return degA - 1;
//    }


}