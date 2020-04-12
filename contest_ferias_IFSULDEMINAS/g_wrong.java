// Abordagem naive: TLE

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int q = input.nextInt();
        int[] vetor = new int[n];
        for (int i = 0; i < n; i++) {
            vetor[i] = input.nextInt();
        }
        
        for (int i = 0; i < q; i++) {
            int y = input.nextInt();
            if(y == 2) {
                int x, a, b;
                x = input.nextInt();
                a = input.nextInt();
                b = input.nextInt();
                a--; b--;
                int cont = 0;
                for (int j = a; j <= b; j++) {
                    if(vetor[j] > x) cont++;
                }
                System.out.println(cont);
            }
            if(y == 1) {
                int a, z;
                a = input.nextInt();
                z = input.nextInt();
                vetor[a-1] = z;
            }
        }
    }

}

